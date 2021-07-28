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
			SPI_MasterInit();


//_delay_ms(100);
			//data=SPI_SlaveReceive();

			//SPI_Recive_String(string);


			SPI_MasterTransmit('a');

	while(1){

//if (data==50){
	//DIO_voidTogPin(PORT_A,PIN0);
//}
	}



}
