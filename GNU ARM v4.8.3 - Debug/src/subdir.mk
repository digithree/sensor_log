################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/graphics.c \
../src/weatherstation.c 

OBJS += \
./src/graphics.o \
./src/weatherstation.o 

C_DEPS += \
./src/graphics.d \
./src/weatherstation.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics.o: ../src/graphics.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/graphics.d" -MT"src/graphics.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/weatherstation.o: ../src/weatherstation.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/weatherstation.d" -MT"src/weatherstation.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


