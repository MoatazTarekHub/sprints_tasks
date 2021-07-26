/*
 * SPI_Program.c
 *
 *  Created on: Dec 23, 2020
 *      Author: Al Badr
 */
#include "DataTypes.h"
#include "BIT_Math.h"
//#include "SPI_Private.h"
#include "Memmap.h"
#include "DIO_Interface.h"
//#include <util/delay.h>
#include "SPI_Config.h"




void SPI_MasterInit(void){
	DIO_voidSetPinDirection(PORT_B,PIN4,OUTPUT);//ss
	DIO_voidSetPinValue(PORT_B,PIN7,LOW);//ss

	DIO_voidSetPinDirection(PORT_B,PIN5,OUTPUT);//mosi
	DIO_voidSetPinDirection(PORT_B,PIN6,INPUT);//miso
	DIO_voidSetPinDirection(PORT_B,PIN7,OUTPUT);//clk

	uint8_t SPCR_HELP=0;
		SETBIT(SPCR_HELP,6);//spi enable

		//SETBIT(SPCR_HELP,5);//lsb
		SETBIT(SPCR_HELP,4);//master
		//SETBIT(SPCR_HELP,3);//rising
		//SETBIT(SPCR_HELP,2);//setup then sample
		//clk f/4
		CLRBIT(SPCR_HELP,1);
		CLRBIT(SPCR_HELP,0);
		CLRBIT(SPSR,0);
	SPCR=SPCR_HELP;




}
/*void SPI_MasterInit(void)
{
// Set MOSI and SCK output, all others input
	DIO_voidSetPinDirection(PORT_B,PIN4,OUTPUT);//ss
		DIO_voidSetPinValue(PORT_B,PIN7,LOW);//ss

		DIO_voidSetPinDirection(PORT_B,PIN5,OUTPUT);//mosi
		DIO_voidSetPinDirection(PORT_B,PIN6,INPUT);//miso
		DIO_voidSetPinDirection(PORT_B,PIN7,OUTPUT);//clk
// Enable SPI, Master, set clock rate fck/16
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}*/
/*void SPI_MasterTransmit(char cData)
{
 Start transmission
SPDR = cData;
 Wait for transmission complete
while(!(SPSR & (1<<SPIF)))
;
}*/
void SPI_SlaveInit(void){
	uint8_t SPCR_HELP=0;

	DIO_voidSetPinDirection(PORT_B,PIN4,INPUT);//ss
		//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_LOW);//ss

	DIO_voidSetPinDirection(PORT_B,PIN5,INPUT);//mosi
	DIO_voidSetPinDirection(PORT_B,PIN6,OUTPUT);//miso
	DIO_voidSetPinDirection(PORT_B,PIN7,INPUT);//clk
			SETBIT(SPCR_HELP,6);//spi enable

				//SETBIT(SPCR_HELP,5);//lsb
				CLRBIT(SPCR_HELP,4);//slave
				SETBIT(SPCR_HELP,3);//rising
				CLRBIT(SPCR_HELP,2);//setup then sample
				//clk f/4
				CLRBIT(SPCR_HELP,1);
				CLRBIT(SPCR_HELP,0);
				//CLRBIT(SPSR,0);

			SPCR=SPCR_HELP;

}


void SPI_MasterTransmit(uint8_t cData){
	SPDR = cData;
while(!(GETBIT(SPSR,7)));

cData=SPDR;
}


uint8_t SPI_SlaveReceive(void){

	while(0==GETBIT(SPSR,7));
	return SPDR;

}
void SPI_Transmite_String(uint8_t *str){
	uint8_t i;
	while (str[i]!='\0'){
		SPI_MasterTransmit(str[i]);
	i++;
	}
}
void SPI_Recive_String(uint8_t *str){
uint8_t i=0;
	str[i]=SPI_SlaveReceive();
	while(str[i]!='#'){

		i++;
		str[i]=SPI_SlaveReceive();

	}
	str[i]='\n';
}

