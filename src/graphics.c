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
//#include "background.h"
#include "bitmaps.h"
#include <string.h>
#include <stdio.h>

static GLIB_Context_t glibContext;          /* Global glib context */

static void GRAPHICS_Signed_DrawDataHalfScreenFilled(int yoffset, int xoffset, int idx, int displayLen,
		int8_t *data, int logLen, int min, int max, int ytick, int ynumtick, int div);
static void GRAPHICS_Unsigned_DrawDataHalfScreenFilled(int yoffset, int xoffset, int idx, int displayLen,
		uint8_t *data, int logLen, int min, int max, int ytick, int ynumtick, int div);
static void GRAPHICS_Signed_DrawDataHalfScreen(int yoffset, int xoffset, int8_t *data, int logLen,
		int min, int max, int ytick, int ynumtick, int xtick, int div);
static void GRAPHICS_Unsigned_DrawDataHalfScreen(int yoffset, int xoffset, uint8_t *data, int logLen,
		int min, int max, int ytick, int ynumtick, int xtick, int div);
//static void GRAPHICS_DrawDataThirdScreen(int yoffset, int xoffset, int8_t *data, int logLen, int min, int max, int tick);
static void GRAPHICS_DrawArrow(int pointx, int pointy, int arrowSize, int shaftLen, int upfacing, int downfacing);
static void GRAPHICS_drawStringV(char *str, int x, int y, int maxchars);
static void GRAPHICS_DrawQuadVals(uint8_t tData, int8_t rhData, int8_t vData, int8_t irData);
static int scaleInt( int val, int oldmin, int oldmax, int newmin, int newmax);

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
	if( displayIsAwake == 0 ) {
		return;
	}
	EMSTATUS status;
	status = GLIB_displaySleep();
	displayIsAwake = 0;
}

void GRAPHICS_Wake(void) {
	if( displayIsAwake == 1 ) {
		return;
	}
	EMSTATUS status;
	status = GLIB_displayWakeUp();
	displayIsAwake = 1;
}

int GRAPHICS_DisplayIsAwake(void) {
	return displayIsAwake;
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
void GRAPHICS_Draw(int displayState, int logIdx, int logLen,
		int8_t *tData, uint8_t *rhData, uint8_t *uvData,
		uint8_t *irData, uint8_t *visData,
		bool lowBat, int uptimeTicks, int ticksInHr, uint16_t vis)
{
	char string[15];
	int xoffset = 30;
	int ARROW_HEAD_Y = 65;
	int ARROW_HEAD_SIZE = 3;
	int ARROW_LEN = 15;
	int ARROW_LEN_SHORT = 11;
	int nom, denom;
	int SHORT_HIST = 16;
	int OFFSET_Y_1 = 20;
	int OFFSET_Y_2 = 66;
	int OFFSET_Y_3 = 108;
	int OFFSET_Y_4 = 45;
	int OFFSET_Y_5 = 90;
	char smallstr[2];

	if( displayIsAwake == 0 ) {
		return;
	}

	GLIB_clear(&glibContext);

	/*
	if ((!si114x_status) || (!si7013_status)) {
		GLIB_drawString(&glibContext, "SensorEXP fail!", 16, 5, 115, 0);
		DMD_updateDisplay();
		return;
	}
	*/

	smallstr[1] = '\0';
	// DEBUG to print 16bit number in bits across screen
	/*
	smallstr[1] = '\0';
	for( int i = 0 ; i < 16 ; i++ ) {
		smallstr[0] = vis & (1 << (15-i)) ? '1' : '0';
		GLIB_drawString(&glibContext, smallstr, 1, 8*i, 8, 0);
	}
	DMD_updateDisplay();
	return;
	*/

	if( displayState == 0 )
	{
		// temp
		GRAPHICS_Signed_DrawDataHalfScreenFilled(60, OFFSET_Y_1, logIdx, SHORT_HIST, tData, logLen, -10, 40, 5, 10, 1);
		sprintf(string, "t%d", tData[(logIdx-1)%logLen]);
		GLIB_drawString(&glibContext, string, strlen(string), OFFSET_Y_1-12, 65, 0);
		// humidity
		GRAPHICS_Unsigned_DrawDataHalfScreenFilled(60, OFFSET_Y_2, logIdx, SHORT_HIST, rhData, logLen, 0, 100, 10, 20, 2);
		sprintf(string, "h%d", rhData[(logIdx-1)%logLen]);
		GLIB_drawString(&glibContext, string, strlen(string), OFFSET_Y_2-12, 65, 0);
		// uv
		GRAPHICS_Unsigned_DrawDataHalfScreenFilled(60, OFFSET_Y_3, logIdx, SHORT_HIST, uvData, logLen, 0, 12, 5, 10, 1);
		sprintf(string, "u%d", uvData[(logIdx-1)%logLen]);
		GLIB_drawString(&glibContext, string, strlen(string), OFFSET_Y_3-12, 65, 0);
		// vis
		GRAPHICS_Unsigned_DrawDataHalfScreenFilled(125, OFFSET_Y_4, logIdx, SHORT_HIST, visData, logLen, 0, 200, 25, 50, 5);
		sprintf(string, "v%d", visData[(logIdx-1)%logLen]);
		GRAPHICS_drawStringV(string, 0, 80, 4);
		// ir
		GRAPHICS_Unsigned_DrawDataHalfScreenFilled(125, OFFSET_Y_5, logIdx, SHORT_HIST, irData, logLen, 0, 200, 25, 50, 5);
		sprintf(string, "i%d", irData[(logIdx-1)%logLen]);
		GRAPHICS_drawStringV(string, 120, 80, 4);
	} else if( displayState == 1 ) {
		// Temp vs Relative humidity
		GRAPHICS_Signed_DrawDataHalfScreen(56, xoffset, tData, logLen,
				-10, 40, 5, 10, 4, 1);
		GRAPHICS_Unsigned_DrawDataHalfScreen(126, xoffset, rhData, logLen,
				0, 100, 10, 20, 4, 2);
		sprintf(string, "t%d/r%d", tData[(logIdx-1)%logLen], rhData[(logIdx-1)%logLen]);
				GLIB_drawString(&glibContext, string, strlen(string), logIdx > (logLen/2) ? 16 : 80, 62, 0);
	} else if( displayState == 2 ) {
		// Visible vs Infrared light
		GRAPHICS_Unsigned_DrawDataHalfScreen(55, xoffset, visData, logLen,
											0, 200, 25, 50, 4, 5);
		GRAPHICS_Unsigned_DrawDataHalfScreen(126, xoffset, irData, logLen,
									0, 200, 25, 50, 4, 5);
		sprintf(string, "v%d/i%d", visData[(logIdx-1)%logLen], irData[(logIdx-1)%logLen]);
		GLIB_drawString(&glibContext, string, strlen(string), logIdx > (logLen/2) ? 16 : 80, 62, 0);
	} else if( displayState == 3 ) {
		// uv : ultraviolet
		GRAPHICS_Unsigned_DrawDataHalfScreen(60, xoffset, uvData, logLen,
								0, 12, 10, 5, 4, 1);
		sprintf(string, "uv: %d", uvData[(logIdx-1)%logLen]);
		GLIB_drawString(&glibContext, string, strlen(string), 5, 80, 0);
		// print string: up time
		nom = uptimeTicks / ticksInHr;
		denom = uptimeTicks % ticksInHr;
		sprintf(string, "up %d %d/%d hr", nom, denom, ticksInHr);
		GLIB_drawString(&glibContext, string, strlen(string), 8, 120, 0);
		// infos
		strcpy(string, "Env sensor log");
		GLIB_drawString(&glibContext, string, strlen(string), 8, 92, 0);
		strcpy(string, "by digithree");
		GLIB_drawString(&glibContext, string, strlen(string), 8, 100, 0);
	} else if( displayState == 4 ) {
		DMD_writeData(0, 0, circlesBitmap, 128*128);
		GRAPHICS_DrawQuadVals(
				tData[(logIdx-1)%logLen],
				rhData[(logIdx-1)%logLen],
				visData[(logIdx-1)%logLen],
				irData[(logIdx-1)%logLen]);
		smallstr[0] = 't';
		GLIB_drawString(&glibContext, smallstr, 1, 48, 0, 0);
		smallstr[0] = 'r';
		GLIB_drawString(&glibContext, smallstr, 1, 120, 48, 0);
		smallstr[0] = 'i';
		GLIB_drawString(&glibContext, smallstr, 1, 128-48, 120, 0);
		smallstr[0] = 'v';
		GLIB_drawString(&glibContext, smallstr, 1, 0, 128-48, 0);
	}
	// draw arrow
	//if( displayState == 1 || displayState == 2 ) {
		//GRAPHICS_DrawArrow( (xoffset + logIdx), ARROW_HEAD_Y, ARROW_HEAD_SIZE, ARROW_LEN, 1, 0);
	//} else
	if( displayState == 1 || displayState == 2 ) {
		GRAPHICS_DrawArrow( (xoffset + logIdx), ARROW_HEAD_Y-5, ARROW_HEAD_SIZE, ARROW_LEN_SHORT, 1, 1);
	}
	if ( lowBat ) {
		GLIB_drawString(&glibContext, "LOWBAT", 16, 0, 120, 0);
	}

	DMD_updateDisplay();
}

static void GRAPHICS_DrawQuadVals(uint8_t tData, int8_t rhData, int8_t vData, int8_t irData)
{
	int tScaled;
	int rhScaled;
	int vScaled;
	int irScaled;

	tScaled = scaleInt(tData, 10, 30, 0, 60);
	rhScaled = scaleInt(rhData, 40, 80, 0, 60);
	vScaled = scaleInt(vData, 0, 100, 0, 60);
	irScaled = scaleInt(irData, 0, 100, 0, 60);

	GLIB_drawLine(&glibContext, 64, 64-tScaled, 64+rhScaled, 64);
	GLIB_drawLine(&glibContext, 64+rhScaled, 64, 64, 64+irScaled);
	GLIB_drawLine(&glibContext, 64, 64+irScaled, 64-vScaled, 64);
	GLIB_drawLine(&glibContext, 64-vScaled, 64, 64, 64-tScaled);
}

static int scaleInt( int val, int oldmin, int oldmax, int newmin, int newmax)
{
	int newval = val;
	if( newval > oldmax ) {
		newval = oldmax;
	} else if( newval < oldmin ) {
		newval = oldmin;
	}
	float factor = (float)(newmax - newmin) / (float)(oldmax - oldmin);
	return (int)(((float)(newval-oldmin) * factor) + newmin);
}

static void GRAPHICS_drawStringV(char *str, int x, int y, int maxchars)
{
	int len;
	int px;
	int py;
	char onecharstr[2];
	len = strlen(str);
	if( maxchars < len ) {
		len = maxchars;
	}
	px = x;
	py = y;
	onecharstr[1] = '\0';
	for( int i = 0 ; i < maxchars ; i++ ) {
		onecharstr[0] = str[i];
		GLIB_drawString(&glibContext, onecharstr, 1, px, py, 0);
		py += 8;
	}
}

static void GRAPHICS_Signed_DrawDataHalfScreenFilled(int yoffset, int xoffset, int idx, int displayLen,
		int8_t *data, int logLen, int min, int max, int ytick, int ynumtick, int div)
{
	int i;
	int j;
	int k;
	int8_t d;
	char num[3];
	int yZeroOffset = yoffset;
	int yMinDist = 0;
	if( min != 0 ) {
		yMinDist = ((-min)/div);
		yZeroOffset -= yMinDist;
	}

	// draw axis
	GLIB_drawLineH(&glibContext, xoffset-8, yZeroOffset, xoffset+displayLen-1);
	GLIB_drawLineV(&glibContext, xoffset-1, yZeroOffset-(max/div), yZeroOffset+yMinDist);
	// draw ticks (axis ticks only)
	k = 1;
	for( j = (ytick/div) ; j <= (max/div) ; j += (ytick/div) ) {
		GLIB_drawLineH(&glibContext, xoffset-1, yZeroOffset-j, xoffset-2-(((k+1)%2)*2) );
		k = (k + 1) % 2;
	}
	if( min < 0 ) {
		k = 1;
		for( j = -(ytick/div) ; j >= (min/div) ; j -= (ytick/div) ) {
			GLIB_drawLineH(&glibContext, xoffset-1, yZeroOffset-j, xoffset-2-(((k+1)%2)*2) );
			k = (k + 1) % 2;
		}
	}
	// draw num ticks
	for( j = (ynumtick/div) ; j <= (max/div) ; j += (ynumtick/div) ) {
		k = j * div;
		if( k < 100 ) {
			sprintf(num, "%d", k);
			GLIB_drawString(&glibContext, num, strlen(num), xoffset-20, yZeroOffset-j-4, 0);
		} else {
			sprintf(num, "%d", k);
						GLIB_drawString(&glibContext, num, strlen(num), xoffset-28, yZeroOffset-j-4, 0);
		}
	}
	if( min < 0 ) {
		for( j = (-ynumtick/div) ; j >= (min/div) ; j -= (ynumtick/div) ) {
			k = (j+((-j)*div));
			sprintf(num, "%d", k);
			GLIB_drawString(&glibContext, num, strlen(num), xoffset-20, yZeroOffset-j-4, 0);
		}
	}

	for( i = 0 ; i < displayLen ; i++ ) {
		k = idx-displayLen+i;
		while( k < 0 ) {
			k += logLen;
		}
		d = data[k%logLen];
		if( d < min ) {
			d = min;
		} else if( d > max ) {
			d = max;
		}
		d /= div;
		GLIB_drawLineV(&glibContext, xoffset + i, yZeroOffset, yZeroOffset - d);
	}
}

static void GRAPHICS_Unsigned_DrawDataHalfScreenFilled(int yoffset, int xoffset, int idx, int displayLen,
		uint8_t *data, int logLen, int min, int max, int ytick, int ynumtick, int div)
{
	int i;
	int j;
	int k;
	uint8_t d;
	char num[3];
	int yZeroOffset = yoffset;
	int yMinDist = 0;
	if( min != 0 ) {
		yMinDist = ((-min)/div);
		yZeroOffset -= yMinDist;
	}

	// draw axis
	GLIB_drawLineH(&glibContext, xoffset-8, yZeroOffset, xoffset+displayLen-1);
	GLIB_drawLineV(&glibContext, xoffset-1, yZeroOffset-(max/div), yZeroOffset+yMinDist);
	// draw ticks (axis ticks only)
	k = 1;
	for( j = (ytick/div) ; j <= (max/div) ; j += (ytick/div) ) {
		GLIB_drawLineH(&glibContext, xoffset-1, yZeroOffset-j, xoffset-2-(((k+1)%2)*2) );
		k = (k + 1) % 2;
	}
	// draw num ticks
	for( j = (ynumtick/div) ; j <= (max/div) ; j += (ynumtick/div) ) {
		k = j * div;
		if( k < 100 ) {
			sprintf(num, "%d", k);
			GLIB_drawString(&glibContext, num, strlen(num), xoffset-20, yZeroOffset-j-4, 0);
		} else {
			sprintf(num, "%d", k);
						GLIB_drawString(&glibContext, num, strlen(num), xoffset-28, yZeroOffset-j-4, 0);
		}
	}
	for( i = 0 ; i < displayLen ; i++ ) {
		k = idx-displayLen+i;
		while( k < 0 ) {
			k += logLen;
		}
		d = data[k%logLen];
		if( d < min ) {
			d = min;
		} else if( d > max ) {
			d = max;
		}
		d /= div;
		GLIB_drawLineV(&glibContext, xoffset + i, yZeroOffset, yZeroOffset - d);
	}
}

static void GRAPHICS_Signed_DrawDataHalfScreen(int yoffset, int xoffset, int8_t *data, int logLen,
		int min, int max, int ytick, int ynumtick, int xtick, int div)
{
	int tickOffset;
	int i;
	int j;
	int k;
	int8_t d;
	char num[3];
	int yZeroOffset = yoffset;
	int yMinDist = 0;
	if( min != 0 ) {
		yMinDist = ((-min)/div);
		yZeroOffset -= yMinDist;
	}

	// draw axis
	GLIB_drawLineH(&glibContext, xoffset-8, yZeroOffset, xoffset+logLen);
	GLIB_drawLineV(&glibContext, xoffset-1, yZeroOffset-(max/div), yZeroOffset+yMinDist);
	// draw ticks
	k = 1;
	for( j = (ytick/div) ; j <= (max/div) ; j += (ytick/div) ) {
		GLIB_drawLineH(&glibContext, xoffset-1, yZeroOffset-j, xoffset-2-(((k+1)%2)*3) );
		tickOffset = ((k+1)*xtick);
		for( i = tickOffset ; i < logLen ; i += tickOffset) {
			GLIB_drawPixel(&glibContext, xoffset + i, yZeroOffset - j);
		}
		k = (k + 1) % 2;
	}
	if( min < 0 ) {
		k = 1;
		for( j = -(ytick/div) ; j >= (min/div) ; j -= (ytick/div) ) {
			GLIB_drawLineH(&glibContext, xoffset-1, yZeroOffset-j, xoffset-2-(((k+1)%2)*3) );
			tickOffset = ((k+1)*xtick);
			for( i = tickOffset ; i < logLen ; i += tickOffset) {
				GLIB_drawPixel(&glibContext, xoffset + i, yZeroOffset - j);
			}
			k = (k + 1) % 2;
		}
	}
	// draw num ticks
	for( j = (ynumtick/div) ; j <= (max/div) ; j += (ynumtick/div) ) {
		k = j * div;
		sprintf(num, "%d", k);
		GLIB_drawString(&glibContext, num, strlen(num), 1, yZeroOffset-j-4, 0);
	}
	if( min < 0 ) {
		for( j = (-ynumtick/div) ; j >= (min/div) ; j -= (ynumtick/div) ) {
			k = (j+((-j)*div));
			sprintf(num, "%d", k);
			GLIB_drawString(&glibContext, num, strlen(num), 1, yZeroOffset-j-4, 0);
		}
	}

	for( i = 0 ; i < logLen ; i++ ) {
		d = data[i];
		if( d < min ) {
			d = min;
		} else if( d > max ) {
			d = max;
		}
		d /= div;
		// on pixel
		//GLIB_drawPixel(&glibContext, xoffset + i, yZeroOffset - d);
		GLIB_drawLineV(&glibContext, xoffset + i, yZeroOffset - d, yZeroOffset);
	}
}

static void GRAPHICS_Unsigned_DrawDataHalfScreen(int yoffset, int xoffset, uint8_t *data, int logLen,
		int min, int max, int ytick, int ynumtick, int xtick, int div)
{
	int tickOffset;
	int i;
	int j;
	int k;
	uint8_t d;
	char num[3];
	int yZeroOffset = yoffset;
	int yMinDist = 0;
	if( min != 0 ) {
		yMinDist = ((-min)/div);
		yZeroOffset -= yMinDist;
	}

	// draw axis
	GLIB_drawLineH(&glibContext, xoffset-8, yZeroOffset, xoffset+logLen);
	GLIB_drawLineV(&glibContext, xoffset-1, yZeroOffset-(max/div), yZeroOffset+yMinDist);
	// draw ticks
	k = 1;
	for( j = (ytick/div) ; j <= (max/div) ; j += (ytick/div) ) {
		GLIB_drawLineH(&glibContext, xoffset-1, yZeroOffset-j, xoffset-2-(((k+1)%2)*3) );
		tickOffset = ((k+1)*xtick);
		for( i = tickOffset ; i < logLen ; i += tickOffset) {
			GLIB_drawPixel(&glibContext, xoffset + i, yZeroOffset - j);
		}
		k = (k + 1) % 2;
	}
	// draw num ticks
	for( j = (ynumtick/div) ; j <= (max/div) ; j += (ynumtick/div) ) {
		k = j * div;
		sprintf(num, "%d", k);
		GLIB_drawString(&glibContext, num, strlen(num), 1, yZeroOffset-j-4, 0);
	}

	for( i = 0 ; i < logLen ; i++ ) {
		d = data[i];
		if( d < min ) {
			d = min;
		} else if( d > max ) {
			d = max;
		}
		d /= div;
		// on pixel
		//GLIB_drawPixel(&glibContext, xoffset + i, yZeroOffset - d);
		GLIB_drawLineV(&glibContext, xoffset + i, yZeroOffset - d, yZeroOffset);
	}
}

static void GRAPHICS_DrawArrow(int pointx, int pointy, int arrowSize, int shaftLen, int upfacing, int downfacing)
{
	GLIB_drawLineV(&glibContext, pointx , pointy, pointy + shaftLen);
	if( upfacing == 1 ) {
		GLIB_drawLine(&glibContext, pointx, pointy,
				pointx-arrowSize, pointy+arrowSize);
		GLIB_drawLine(&glibContext, pointx, pointy,
				pointx+arrowSize, pointy+arrowSize);
	}
	if( downfacing == 1 ) {
		GLIB_drawLine(&glibContext, pointx, pointy+shaftLen,
				pointx-arrowSize, pointy+shaftLen-arrowSize);
		GLIB_drawLine(&glibContext, pointx, pointy+shaftLen,
				pointx+arrowSize, pointy+shaftLen-arrowSize);
	}
}
