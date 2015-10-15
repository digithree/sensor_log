# Sensor Log

### Description

An app which logs 24 hours of environmental sensor readings with display. Made for the Zero Gecko Dev kit with Weatherstation Sensor add-on.

## Operation

### Sensors

Five kinds of sensor data are recorded. Each has a one character abreviation used in the app, shown in square brackets.

1. [T]emperature (Celcius)
2. [R]elative Humidity (in percent)
3. [U]ltraviolet light (UV index: 1 to 11+)
4. [V]isible light (adjusted lux)
5. [I]nfrared light (adjusted lux)

### Measurement

A reading of each data category is recorded every 15 minutes. 24 hours of data is stored, data is overwritten. The app is extremely low power and will run for a long time when switched on continuously.

### Display

There are five data viewing screens. The PB0 button switches to the first screen and the PB1 button cycles through each screen, one pre press. The screen will sleep after 5 seconds of on time and either button wakes the screen up.

#### Screen 1: quadrant display

Shows: temperature, relative humidity, visible light, infrared.

You will see four concentric circles of 15 pixel radius = 60 pixels total. Sensor values are scaled along the axies starting in the centre:

1. temperature pointing up, scaled between 10 and 30 degrees
2. relative humidity pointing right, scaled between 40 and 80 percent
3. visible light pointing right, scaled between 0 and 100
3. infrared light pointing right, scaled between 0 and 100

Lines are drawn between each of the points to imply an area as a different way to look at the data.

### Screen 2: last 4 hour overview

Shows: all

A graph of each of the 5 sensor readings with a short history of the last four hours is shown. Each graph has vertical (value) ticks and tick numbers showing. Additionally the latest value is shown in text

### Screen 3: temperature vs. relative humidity

Shows: temperature, realtive humidity

A full 24 hour graph of temperature and humidity is shown. Vertical (value) ticks and values are shown, as well as horizontal (time) ticks on the graph, divided into hours and half hours. The left-most value is the 0th hour recording, i.e. the time when the device was started. The last write location is shown with a double vertical arrow in the vertical centre. The last value for each data reading is also show in the vertical centre.

### Screen 4: visible light vs. ir light

Shows: visible light, infrared light

This is the same as screen 3 except for these sensor data readings.

### Screen 5: uv light and infos

Shows: ultraviolet light

(This screen needs work!)

UV light in the scale is shown. Additionally, a the title of the app and develop name appear, as well as the time the app has been on (up time) in quarter hour segments.

## Energy consumption

Silicon Labs have build the dev kit, and all their products, with energy consumption in mind. Using the Simplicity Studio profiler, the energy score is about 5 out of 10 when idle for a few minutes.    

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
