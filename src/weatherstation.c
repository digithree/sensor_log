/**************************************************************************//**
 * @file
 * @brief Weather station demo for EFM32ZG_STK3200 and Sensors-EXP
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

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "i2cspm.h"
#include "si7013.h"
#include "si114x_algorithm.h"
#include "rtcdriver.h"
#include "graphics2.h"
#include "em_adc.h"
#include "bspconfig.h"

/**************************************************************************//**
 * Local defines
 *****************************************************************************/
/** Time (in ms) to keep looking for gestures if none are seen. */
#define SCREEN_TIMEOUT_MS      10000
/** Time (in ms) between periodic updates of the measurements. Currently 15 minutes*/
#define PERIODIC_UPDATE_MS      15 * 60 * 1000
/** Time (in ms) between scrolling updates. Lower means faster scrolling
 *  between screens. */
#define ANIMATION_UPDATE_MS     50
/** Voltage defined to indicate dead battery. */
#define LOW_BATTERY_THRESHOLD   2800


/**************************************************************************//**
 * Local variables
 *****************************************************************************/
/* RTC callback parameters. */
static void (*rtcCallback)(void*) = NULL;
static void * rtcCallbackArg = 0;

/** This flag tracks if we need to update the display */
static volatile bool updateDisplay = true;
/** This flag tracks if we need to perform a new measurement. */
static volatile bool updateMeasurement = true;
/** Flag used to indicate ADC is finished */
static volatile bool adcConversionComplete = false;

static const int UPDATE_TICKS_IN_HR = 4;
static volatile int UPTIME_TICKS = 0;

static const int NUM_DISPLAY_STATE = 7;
static const int FIRST_DISPLAY_STATE = 6;
static volatile int displayState = 6;

/** Timer used for timing out sreen to save power. */
RTCDRV_TimerID_t screenTimeoutTimerId;
/** Timer used for periodic update of the measurements. */
RTCDRV_TimerID_t periodicUpdateTimerId;

/**************************************************************************//**
 * Local prototypes
 *****************************************************************************/
static void gpioSetup(void);
static void periodicUpdateCallback(RTCDRV_TimerID_t id, void *user);
static void screenTimeoutCallback(RTCDRV_TimerID_t id, void *user);
static void memLcdCallback(RTCDRV_TimerID_t id, void *user);
static uint32_t checkBattery (void);
static void adcInit( void );

/**************************************************************************//**
 * @brief  Helper function to perform data measurements.
 *****************************************************************************/
static int performMeasurements(uint32_t *rhData, int32_t *tData, uint16_t *uvData, uint32_t *vBat)
{
  *vBat = checkBattery();
  Si7013_MeasureRHAndTemp(I2C0, SI7013_ADDR, rhData, tData);
  int dummyObjectDetect;
  Si1147_MeasureUVAndObjectPresent(I2C0, SI1147_ADDR, uvData, &dummyObjectDetect);
  return 0;
}


/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  I2CSPM_Init_TypeDef i2cInit = I2CSPM_INIT_DEFAULT;
  uint32_t         rhData;
  bool             si7013_status, si1147_status;
  int32_t          tempData;
  uint16_t         uvData;
  uint32_t         vBat = 3300;
  bool             lowBatPrevious = true;
  bool             lowBat = false;

  int 				LOG_LEN = 96;
  int 				logIdx = 0;
  int8_t			tDataLog[96];
  int8_t			rhDataLog[96];
  int8_t			uvDataLog[96];

  int i;

  /* Chip errata */
  CHIP_Init();

  /* Misc initalizations. */
  gpioSetup();
  adcInit();

  for( i = 0 ; i < LOG_LEN ; i++ ) {
	  tDataLog[i] = 0;
	  rhDataLog[i] = 0;
	  uvDataLog[i] = 0;
  }

  /* Misc timers. */
  RTCDRV_Init();
  RTCDRV_AllocateTimer(&screenTimeoutTimerId);
  RTCDRV_AllocateTimer(&periodicUpdateTimerId);

  GRAPHICS_Init();

  /* Initialize I2C driver, using standard rate. */
  I2CSPM_Init(&i2cInit);

  si7013_status = Si7013_Detect(I2C0, SI7013_ADDR, NULL);
  si1147_status = Si1147_Detect_Device(I2C0, SI1147_ADDR);
  Si1147_ConfigureDetection(I2C0, SI1147_ADDR, true);

  /* Set up periodic update of the display.
   * Note: Must update at a much lesser rate than the gesture detection
   * algorithm sample rate. */
  RTCDRV_StartTimer(periodicUpdateTimerId, rtcdrvTimerTypePeriodic,
                    PERIODIC_UPDATE_MS, periodicUpdateCallback, NULL);

  /* Start timer for display sleep */
  	RTCDRV_StartTimer(screenTimeoutTimerId, rtcdrvTimerTypePeriodic,
  			SCREEN_TIMEOUT_MS, screenTimeoutCallback, NULL);

  // show screen on first time start up
  updateDisplay = true;
  updateMeasurement = true;

  while (1)
  {
    if (updateMeasurement)
    {
      performMeasurements(&rhData, &tempData, &uvData, &vBat);
      // update log
      tDataLog[logIdx] = (int8_t)(tempData/1000);
      rhDataLog[logIdx] = (int8_t)(rhData/1000);
      uvDataLog[logIdx] = (int8_t)uvData;
      logIdx++;
      if( logIdx >= LOG_LEN ) {
    	  logIdx = 0;
      }
      updateMeasurement = false;
      UPTIME_TICKS++;
      if (lowBatPrevious)
          lowBat = (vBat <= LOW_BATTERY_THRESHOLD);
      else
          lowBat = false;
      lowBatPrevious = (vBat <= LOW_BATTERY_THRESHOLD);
      // Restart timer for sensor update
      RTCDRV_StartTimer(periodicUpdateTimerId, rtcdrvTimerTypePeriodic,
    		  PERIODIC_UPDATE_MS, periodicUpdateCallback, NULL);
    }
    if (updateDisplay)
    {
    	updateDisplay = false;
    	GRAPHICS_Wake();
    	GRAPHICS_Draw(displayState, logIdx, LOG_LEN, tDataLog, rhDataLog, uvDataLog, lowBat,
    			UPTIME_TICKS, UPDATE_TICKS_IN_HR);
    }

    EMU_EnterEM2(false);
  }
}

/**************************************************************************//**
 * @brief This function is called whenever we want to measure the supply v.
 *        It is reponsible for starting the ADC and reading the result.
 *****************************************************************************/
static uint32_t checkBattery (void)
{
  uint32_t vData;
  /* Sample ADC */
  adcConversionComplete = false;
  ADC_Start(ADC0, adcStartSingle);
  while (!adcConversionComplete) EMU_EnterEM1();
  vData = ADC_DataSingleGet( ADC0 );
  return vData;
}

/**************************************************************************//**
 * @brief ADC Interrupt handler (ADC0)
 *****************************************************************************/
void ADC0_IRQHandler( void ) {

   uint32_t flags;

   /* Clear interrupt flags */
   flags = ADC_IntGet( ADC0 );
   ADC_IntClear( ADC0, flags );

   adcConversionComplete = true;

}

/**************************************************************************//**
 * @brief ADC Initialization
 *****************************************************************************/
static void adcInit( void ) {

   ADC_Init_TypeDef       init       = ADC_INIT_DEFAULT;
   ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;

   /* Enable ADC clock */
   CMU_ClockEnable( cmuClock_ADC0, true );

   /* Initiate ADC peripheral */
   ADC_Init(ADC0, &init);

   /* Setup single conversions for internal VDD/3 */
   initSingle.acqTime = adcAcqTime16;
   initSingle.input   = adcSingleInpVDDDiv3;
   ADC_InitSingle( ADC0, &initSingle );

   /* Manually set some calibration values */
   ADC0->CAL = (0x7C << _ADC_CAL_SINGLEOFFSET_SHIFT) | (0x1F << _ADC_CAL_SINGLEGAIN_SHIFT);

   /* Enable interrupt on completed conversion */
   ADC_IntEnable(ADC0, ADC_IEN_SINGLE);
   NVIC_ClearPendingIRQ( ADC0_IRQn );
   NVIC_EnableIRQ( ADC0_IRQn );
}



/**************************************************************************//**
* @brief Setup GPIO interrupt for pushbuttons.
*****************************************************************************/
static void gpioSetup(void)
{
  /* Enable GPIO clock */
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Configure PB0 as input and enable interrupt  */
  GPIO_PinModeSet(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, gpioModeInputPull, 1);
  GPIO_IntConfig(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, false, true, true);

  /* Configure PB1 as input and enable interrupt */
  GPIO_PinModeSet(BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN, gpioModeInputPull, 1);
  GPIO_IntConfig(BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN, false, true, true);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  /* Configure PD4 as pushpull. (5v enable signal) */
  GPIO_PinModeSet(gpioPortD, 4, gpioModePushPull, 0);
  GPIO_PinOutClear(gpioPortD, 4);

  /* Configure PD5 as input and enable interrupt - proximity interrupt. */
  /* Interrupt is active low */
  //GPIO_PinModeSet(gpioPortD, 5, gpioModeInputPull, 1);
  //GPIO_IntConfig(gpioPortD, 5, false, true, true);

  /*Enable 5V supply to add-on board. */
  GPIO_PinOutSet(gpioPortD, 4);
}

/**************************************************************************//**
* @brief Unified GPIO Interrupt handler (pushbuttons)
*        PB0 Switches units within a measurement display
*        PB1 Starts the demo (quit splashscreen)
*****************************************************************************/
void GPIO_Unified_IRQ(void)
{
  /* Get and clear all pending GPIO interrupts */
  uint32_t interruptMask = GPIO_IntGet();
  GPIO_IntClear(interruptMask);

  /* Act on interrupts */
  if (interruptMask & (1 << BSP_GPIO_PB0_PIN))
  {
	  /* PB0: Turn on screen and goto first screen */
	  updateDisplay = true;
	  displayState = FIRST_DISPLAY_STATE;
  }

  if (interruptMask & (1 << BSP_GPIO_PB1_PIN))
  {
	  /* PB1: Turn on screen and cycle through screens */
	  if( GRAPHICS_DisplayIsAwake() == 1 ) {
		  displayState = (displayState+1)%NUM_DISPLAY_STATE;
	  }
	  updateDisplay = true;
  }
}

/**************************************************************************//**
* @brief GPIO Interrupt handler for even pins
*****************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
  GPIO_Unified_IRQ();
}

/**************************************************************************//**
* @brief GPIO Interrupt handler for odd pins
*****************************************************************************/
void GPIO_ODD_IRQHandler(void)
{
  GPIO_Unified_IRQ();
}

/**************************************************************************//**
 * @brief   The actual callback for Memory LCD toggling
 * @param[in] id
 *   The id of the RTC timer (not used)
 *****************************************************************************/
static void memLcdCallback(RTCDRV_TimerID_t id, void *user)
{
  (void) id;
  (void) user;
  rtcCallback(rtcCallbackArg);
}

/**************************************************************************//**
 * @brief   Register a callback function at the given frequency.
 *
 * @param[in] pFunction  Pointer to function that should be called at the
 *                       given frequency.
 * @param[in] argument   Argument to be given to the function.
 * @param[in] frequency  Frequency at which to call function at.
 *
 * @return  0 for successful or
 *         -1 if the requested frequency does not match the RTC frequency.
 *****************************************************************************/
int RtcIntCallbackRegister(void (*pFunction)(void*),
                           void* argument,
                           unsigned int frequency)
{
  RTCDRV_TimerID_t timerId;
  rtcCallback    = pFunction;
  rtcCallbackArg = argument;

  RTCDRV_AllocateTimer(&timerId);

  RTCDRV_StartTimer(timerId, rtcdrvTimerTypePeriodic, 1000 / frequency,
                    memLcdCallback, NULL);

  return 0;
}

/**************************************************************************//**
 * @brief Callback used to count between measurement updates
 *****************************************************************************/
static void periodicUpdateCallback(RTCDRV_TimerID_t id, void *user)
{
  (void) id;
  (void) user;
  updateMeasurement = true;
}

static void screenTimeoutCallback(RTCDRV_TimerID_t id, void *user)
{
	(void) id;
	(void) user;
	GRAPHICS_Sleep();
	// Start timer for display sleep
	RTCDRV_StartTimer(screenTimeoutTimerId, rtcdrvTimerTypePeriodic,
			SCREEN_TIMEOUT_MS, screenTimeoutCallback, NULL);
}
