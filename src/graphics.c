/**************************************************************************//**
 * @brief Draws the graphics on the display
 * @version 4.0.0
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#include "graphics2.h"
#include "em_types.h"
#include "glib.h"
#include "dmd.h"
#include "display.h"
#include "textdisplay.h"
#include "retargettextdisplay.h"
#include "background.h"
#include <string.h>
#include <stdio.h>

static GLIB_Context_t glibContext;          /* Global glib context */

static void GRAPHICS_DrawTemperatureC(int yheight, int yoffset, int xoffset, int8_t *tempData, int logLen);

static volatile int displayIsAwake = 0;

/**************************************************************************//**
 * @brief Initializes the graphics stack.
 * @note This function will /hang/ if errors occur (usually
 *       caused by faulty displays.
 *****************************************************************************/
void GRAPHICS_Init(void)
{
  EMSTATUS status;

  /* Initialize the display module. */
  status = DISPLAY_Init();
  if (DISPLAY_EMSTATUS_OK != status)
    while (1)
      ;

  /* Initialize the DMD module for the DISPLAY device driver. */
  status = DMD_init(0);
  if (DMD_OK != status)
    while (1)
      ;

  status = GLIB_contextInit(&glibContext);
  if (GLIB_OK != status)
    while (1)
      ;

  glibContext.backgroundColor = Black;
  glibContext.foregroundColor = White;

  displayIsAwake = 1;
}

void GRAPHICS_Sleep(void) {
	EMSTATUS status;
	status = GLIB_displaySleep();
	if (GLIB_OK != status)
	    while (1)
	      ;
	displayIsAwake = 0;
}

void GRAPHICS_Wake(void) {
	EMSTATUS status;
	status = GLIB_displayWakeUp();
	if (GLIB_OK != status)
		while (1)
		  ;
	displayIsAwake = 1;
}

/**************************************************************************//**
 * @brief This function draws the background image
 * @param xoffset
 *        The background image is wider than the display. This parameter
 *        selects which part to show. The offset is given in multiples of 8.
 *        If you increase xoffset by 1, the bacground will be shifted by 8
 *        pixels
 *****************************************************************************/
void GRAPHICS_ShowStatus(bool si114x_status, bool si7013_status, bool removeObject, bool lowBat)
{
	if( displayIsAwake == 0 ) {
		return;
	}

	GLIB_clear(&glibContext);

	if (removeObject) {
		GLIB_drawString(&glibContext, "Please remove ", 15, 5, 40, 0);
		GLIB_drawString(&glibContext, "object in front", 15, 5, 50, 0);
		GLIB_drawString(&glibContext, "of sensor board", 15, 5, 60, 0);
	} else {
		GLIB_drawString(&glibContext, "To start demo ", 14, 5, 20, 0);
		GLIB_drawString(&glibContext, "press PB1 or", 14, 5, 30, 0);
		GLIB_drawString(&glibContext, "hover hand over", 15, 5, 40, 0);
		GLIB_drawString(&glibContext, "sensor board.", 13, 5, 50, 0);
	}

	if (lowBat) {
		GLIB_drawString(&glibContext, "Low Battery!", 16, 5, 115, 0);
	} else if ((!si114x_status) || (!si7013_status)) {
		GLIB_drawString(&glibContext, "SensorEXP fail!", 16, 5, 115, 0);
	}
	/*
	 else
	 {
	 GLIB_drawString(&glibContext, DEMO_VERSION, 16, 5, 115, 0);
	 }
	 */
	DMD_updateDisplay();
}

/**************************************************************************//**
 * @brief This function draws the actual UI
 * @param xoffset
 *        This parameter selects which part of the UI to show.
 * @param tempData
 *        Temperature data (given in Celsius) multiplied by 1000
 * @param rhData
 *        Relative humidity (in percent), multiplied by 1000.
 * @param uvData
 *        UV Index
 * @param degF
 *        Set to 0 to display temperature in Celsius, otherwise Fahrenheit.
 *****************************************************************************/
void GRAPHICS_Draw(int logIdx, int logLen, int8_t *tData, bool lowBat, int uptimeTicks, int ticksInHr)
{
	char string[15];
	int xoffset = 25;
	int ARROW_HEAD_Y = 65;
	int ARROW_HEAD_SIZE = 3;
	int ARROW_LEN = 15;
	int nom, denom;

	if( displayIsAwake == 0 ) {
		return;
	}

	GLIB_clear(&glibContext);
	if ( lowBat ) {
		GLIB_drawString(&glibContext, "Low Battery!", 16, 28, 3, 0);
	}

	// print string: temperature
	sprintf(string, "temp: %d C", tData[(logIdx-1)%logLen]);
	GLIB_drawString(&glibContext, string, strlen(string), 5, 100, 0);
	// print string: up time
	nom = uptimeTicks / ticksInHr;
	denom = uptimeTicks % ticksInHr;
	sprintf(string, "up %d %d/%d hr", nom, denom, ticksInHr);
	GLIB_drawString(&glibContext, string, strlen(string), 5, 115, 0);

	GRAPHICS_DrawTemperatureC(64, 45, xoffset, tData, logLen);

	GLIB_drawLineV(&glibContext, (xoffset + logIdx), ARROW_HEAD_Y, ARROW_HEAD_Y + ARROW_LEN);
	GLIB_drawLine(&glibContext, (xoffset + logIdx), ARROW_HEAD_Y,
			(xoffset + logIdx)-ARROW_HEAD_SIZE, ARROW_HEAD_Y+ARROW_HEAD_SIZE);
	GLIB_drawLine(&glibContext, (xoffset + logIdx), ARROW_HEAD_Y,
			(xoffset + logIdx)+ARROW_HEAD_SIZE, ARROW_HEAD_Y+ARROW_HEAD_SIZE);

	DMD_updateDisplay();
}


/**************************************************************************//**
 * @brief Helper function for drawing the temperature in Celsius.
 * @param xoffset
 *        This parameter selects which part of the UI to show.
 * @param yoffset
 *        This parameter selects which part of the UI to show.
 * @param tempData
 *        Temperature data (given in Celsius) multiplied by 1000
 *****************************************************************************/
static void GRAPHICS_DrawTemperatureC(int yheight, int yoffset, int xoffset, int8_t *tempData, int logLen)
{
	int TICK = 5;
	int TICK_SPACING = 3;
	int tickOffset;
	int MIN_TEMP;
	int MAX_TEMP;
	int i;
	int j;
	int k;
	int8_t temp;

	MIN_TEMP = -10;
	MAX_TEMP = 40;

	// draw axis
	GLIB_drawLineH(&glibContext, xoffset-8, yoffset, xoffset+logLen);
	GLIB_drawLineV(&glibContext, xoffset-1, yoffset-MAX_TEMP, yoffset-MIN_TEMP);
	// draw ticks
	k = 1;
	for( j = TICK ; j <= MAX_TEMP ; j += TICK ) {
		GLIB_drawLineH(&glibContext, xoffset-1, yoffset-j, xoffset-2-(((k+1)%2)*3) );
		tickOffset = ((k+1)*TICK_SPACING);
		for( i = 0 ; i < logLen ; i += tickOffset) {
			GLIB_drawPixel(&glibContext, xoffset + i, yoffset - j);
		}
		k = (k + 1) % 2;
	}
	k = 1;
	for( j = -TICK ; j >= MIN_TEMP ; j -= TICK ) {
		GLIB_drawLineH(&glibContext, xoffset-1, yoffset-j, xoffset-2-(((k+1)%2)*3) );
		tickOffset = ((k+1)*TICK_SPACING);
		for( i = 0 ; i < logLen ; i += tickOffset) {
			GLIB_drawPixel(&glibContext, xoffset + i, yoffset - j);
		}
		k = (k + 1) % 2;
	}

	for( i = 0 ; i < logLen ; i++ ) {
		temp = tempData[i];
		if( temp < MIN_TEMP ) {
			temp = MIN_TEMP;
		} else if( temp > MAX_TEMP ) {
			temp = MAX_TEMP;
		}
		GLIB_drawPixel(&glibContext, xoffset + i, yoffset - temp);
		//GLIB_drawLineV(&glibContext, xoffset + i, yoffset, yoffset-temp);
	}
}
