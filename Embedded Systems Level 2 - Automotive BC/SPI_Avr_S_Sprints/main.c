/*
 * main.c
 *
 *  Created on: Jul 15, 2021
 *      Author: Al Badr
 */


#include "DataTypes.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#include "SPI_Interface.h"

int main(void){
	uint8_t data=0;
	uint8_t string[100]={0};
			SPI_SlaveInit();
			DIO_voidSetPortDirection(PORT_C,0xff);
			//DIO_voidSetPortValue(PORT_C,0xff);

//_delay_ms(100);
			DIO_voidSetPinValue(PORT_C,PIN4,LOW);//ss

			data=SPI_SlaveReceive();
			DIO_voidSetPinValue(PORT_C,PIN5,LOW);//ss

			//SPI_Recive_String(string);

			DIO_voidSetPortValue(PORT_C,data);
			//SPI_MasterTransmit('a');
			if (data=='a'){
			DIO_voidSetPinValue(PORT_C,PIN0,LOW);
				//_delay_ms(1000);

			}
	while(1){


	}



}
