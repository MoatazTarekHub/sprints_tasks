################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/Uart_Program.c 

OBJS += \
./MCAL/UART/Uart_Program.o 

C_DEPS += \
./MCAL/UART/Uart_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.o: ../MCAL/UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti 3 month\iti avr workspace\SPI_UART_M_Sprint\MCAL\UART" -I"D:\iti 3 month\iti avr workspace\SPI_UART_M_Sprint\lib" -I"D:\iti 3 month\iti avr workspace\SPI_UART_M_Sprint\MCAL\DIO" -I"D:\iti 3 month\iti avr workspace\SPI_UART_M_Sprint\MCAL\UART" -I"D:\iti 3 month\iti avr workspace\SPI_UART_M_Sprint\MCAL\SPI" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


