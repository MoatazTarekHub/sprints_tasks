/*
 * main.c
 *
 *  Created on: Jul 15, 2021
 *      Author: Al Badr
 */


#include "DataTypes.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "Uart_Interface.h"
#include "SPI_Interface.h"

int main(void){
	uint8_t data=0;
	uint8_t string[100]={0};
			SPI_MasterInit();

			UART_Init(9600);

//_delay_ms(100);
			//data=SPI_SlaveReceive();

			//SPI_Recive_String(string);


			//SPI_MasterTransmit('a');
			DIO_voidSetPinDirection(PORT_A,PIN0,OUTPUT);
			DIO_voidSetPinValue(PORT_A,PIN0,LOW);

	while(1){
		UART_Recive_String(string);
		SPI_Transmite_String(string);
		DIO_voidTogPin(PORT_A,PIN0);

	}



}
