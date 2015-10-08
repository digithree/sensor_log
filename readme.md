# Sensor Log

### Description

An app which logs 24 hours of temperature sensor readings with display display. Made for the Zero Gecko Dev kit with Weatherstation Sensor add-on.

## Operation

When the app starts you will be presented with a blank screen. This is because the display is in sleep mode to conserve power. To wake up the display, press the PB_0 button or make a swipe gesture in front of the sensor add-on panel.

Even when the display is asleep, the device takes a periodic sensor reading. Currently this is set to every 15 minutes. The sensor data log buffer size is set to 96 which gives an exact 24 hour log of data.

The screen will display for 10 seconds from last button or gesture input before going to sleep again. On the display you will see the temperature plot on the top of the screen. A solid line axis shows the graph left edge and the zero degrees line (temperature is in Celcius). Every 5 degrees there is a tick and dotted vertical line; every 10 degrees the tick is bigger and dotted line denser. The temperature plot is plotted with a solid pixel.

Below the graph is additional information. An up-facing arrow shows the current plot position. Temperature is stored with a moving wrap around pointer. Additionally the current temperature is displayed in text, as is the device up time.

## Energy consumption

Silicon Labs have build the dev kit, and all their products, with energy consumption in mind. Using the Simplicity Studio profiler, the energy score is about 5.2 out of 10 when idle for a few minutes.    

I have yet to test how long it will run with 2032 coin cell battery. It's not clear to me yet what the energy scores mean.

## Build and install

To build use Simplicity Studio v3, provided by Silicon Labs. The hardware required is the Zero Gecko Dev kit with Weatherstation Sensor add-on (EFM32ZG-STK3200).

## Attribution

This app is based on the weatherstation demo code provided by Silicon Labs. The original licence is included, and the original readme read as follows:

Weatherstation using the Sensor add-on board on the EFM32ZG-STK3200.

This example project uses the EFM32 CMSIS including emlib and the
board support package support functions/drivers to demonstrate driving
the Sharp Memory LCD display on the EFM32ZG_STK3200 kit. In addition, it
demonstrates the use of Silabs I2C based sensors on the expansion board
header.

You must have a Silabs Sensor add-on board to make use of this demo.
Once the demo is started, hold your hand over the gesture sensor. Once
the sensor detects your hand the display will become active.

Swipe left and right over the sensor to scroll through temperature, humidity
and UV index. On the temperature screen, you can swipe up or down to change
between Fahrenheit or Celcius.

Note: Due to the size of this example, you might need to enable compiler
optimizations to be able to fit the entire binary in the 32k of flash!

Board:  Silicon Labs EFM32ZG-STK3200 Development Kit and Sensor Add-on board
Device: EFM32ZG222F32
