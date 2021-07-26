################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/App.c \
../APP/main.c 

OBJS += \
./APP/App.o \
./APP/main.o 

C_DEPS += \
./APP/App.d \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti 3 month\iti avr workspace\UART_Avr_Sprints\lib" -I"D:\iti 3 month\iti avr workspace\UART_Avr_Sprints\APP" -I"D:\iti 3 month\iti avr workspace\UART_Avr_Sprints\MCAL\UART" -I"D:\iti 3 month\iti avr workspace\UART_Avr_Sprints\MCAL" -I"D:\iti 3 month\iti avr workspace\UART_Avr_Sprints" -I"D:\iti 3 month\iti avr workspace\UART_Avr_Sprints\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


