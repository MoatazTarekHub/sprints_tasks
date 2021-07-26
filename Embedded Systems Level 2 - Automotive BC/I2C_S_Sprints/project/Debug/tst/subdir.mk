################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tst/I2C_tst.c 

OBJS += \
./tst/I2C_tst.o 

C_DEPS += \
./tst/I2C_tst.d 


# Each subdirectory must supply rules for building sources it contributes
tst/%.o: ../tst/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\MCAL\I2C" -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\MCAL\DIO" -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\lib" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


