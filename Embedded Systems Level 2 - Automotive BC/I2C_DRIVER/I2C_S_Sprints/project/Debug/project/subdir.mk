################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../project/main.c 

OBJS += \
./project/main.o 

C_DEPS += \
./project/main.d 


# Each subdirectory must supply rules for building sources it contributes
project/%.o: ../project/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\project\MCAL\I2C" -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\project\MCAL\DIO" -I"D:\iti 3 month\iti avr workspace\I2C_S_Sprints\project\lib" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


