################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/display.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/displayls013b7dh03.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/displaypalemlib.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/i2cspm.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/src/rtcdriver.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si1147_i2c.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si114x_algorithm.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si114x_functions.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si7013.c \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/udelay.c 

OBJS += \
./Drivers/display.o \
./Drivers/displayls013b7dh03.o \
./Drivers/displaypalemlib.o \
./Drivers/i2cspm.o \
./Drivers/rtcdriver.o \
./Drivers/si1147_i2c.o \
./Drivers/si114x_algorithm.o \
./Drivers/si114x_functions.o \
./Drivers/si7013.o \
./Drivers/udelay.o 

C_DEPS += \
./Drivers/display.d \
./Drivers/displayls013b7dh03.d \
./Drivers/displaypalemlib.d \
./Drivers/i2cspm.d \
./Drivers/rtcdriver.d \
./Drivers/si1147_i2c.d \
./Drivers/si114x_algorithm.d \
./Drivers/si114x_functions.d \
./Drivers/si7013.d \
./Drivers/udelay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/display.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/display.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/display.d" -MT"Drivers/display.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/displayls013b7dh03.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/displayls013b7dh03.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/displayls013b7dh03.d" -MT"Drivers/displayls013b7dh03.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/displaypalemlib.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/displaypalemlib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/displaypalemlib.d" -MT"Drivers/displaypalemlib.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/i2cspm.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/i2cspm.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/i2cspm.d" -MT"Drivers/i2cspm.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/rtcdriver.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/src/rtcdriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/rtcdriver.d" -MT"Drivers/rtcdriver.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/si1147_i2c.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si1147_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/si1147_i2c.d" -MT"Drivers/si1147_i2c.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/si114x_algorithm.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si114x_algorithm.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/si114x_algorithm.d" -MT"Drivers/si114x_algorithm.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/si114x_functions.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si114x_functions.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/si114x_functions.d" -MT"Drivers/si114x_functions.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/si7013.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/si7013.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/si7013.d" -MT"Drivers/si7013.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/udelay.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers/udelay.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DNDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"Drivers/udelay.d" -MT"Drivers/udelay.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


