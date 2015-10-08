################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c 

S_UPPER_SRCS += \
/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.S 

OBJS += \
./CMSIS/efm32zg/startup_efm32zg.o \
./CMSIS/efm32zg/system_efm32zg.o 

C_DEPS += \
./CMSIS/efm32zg/system_efm32zg.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/efm32zg/startup_efm32zg.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -c -x assembler-with-cpp -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" '-DEFM32ZG222F32=1' -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/efm32zg/system_efm32zg.o: /Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb '-DEFM32ZG222F32=1' '-DDEBUG=1' -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/examples/weatherstation" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/EFM32ZG_STK3200/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/config" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/gpiointerrupt/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/nvm/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/sleep/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/spidrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/uartdrv/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/emdrv/ustimer/inc" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32ZG/Include" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/glib" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd" -I"/Applications/SimplicityStudio_v3/developer/sdks/efm32/v2/reptile/glib/dmd/ssd2119" -Os -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"CMSIS/efm32zg/system_efm32zg.d" -MT"CMSIS/efm32zg/system_efm32zg.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


