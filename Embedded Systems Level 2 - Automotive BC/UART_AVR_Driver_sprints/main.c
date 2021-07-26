/*
 * main.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Al Badr
 */


#include "Uart_Interface.h"
#include "DIO_Interface.h"
#include <util/delay.h>

	 uint8_t recive[100];

int main(){
	UART_Init(9600);
	UART_Recive_String(recive);

	UART_Transmite_String(recive);
	DIO_voidSetPinDirection(PORT_A,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORT_A,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORT_A,PIN2,OUTPUT);
	_delay_ms(1000);

	UART_Transmite_String("\r\n done");


	while(1){
		UART_Recive_String(recive);
		UART_Transmite_String(recive);

	}


}
