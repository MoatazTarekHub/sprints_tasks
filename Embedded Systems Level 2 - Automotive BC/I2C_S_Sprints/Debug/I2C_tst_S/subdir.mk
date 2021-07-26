################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../I2C_tst_S/I2C_tst.c 

OBJS += \
./I2C_tst_S/I2C_tst.o 

C_DEPS += \
./I2C_tst_S/I2C_tst.d 


# Each subdirectory must supply rules for building sources it contributes
I2C_tst_S/%.o: ../I2C_tst_S/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\project\MCAL\I2C" -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\project\MCAL\DIO" -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\project\lib" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


