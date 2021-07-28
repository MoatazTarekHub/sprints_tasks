/*
 * Uart_Program.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Al Badr
 */


#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"
#include "Uart_Config.h"
#include "Memmap.h"

//#include <util/delay.h>
/*void UART_Init( u32 Copy_uint8_tBoudRate )
{

	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT ) ;//TX
	//DIO_SetPinDirection( PORTD , PIN0 , INPUT  ) ;//RX
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);

	u16 UBRR ;

	//UBRR = ( F_CPU / ( 16 * Copy_uint8_tBoudRate ) ) -1 ;
	UBRR=(F_CPU/(16*Copy_uint8_tBoudRate))-1;

	UBRRH = (uint8_t)( UBRR >> 8 ) ;
	UBRRL = (uint8_t)( UBRR ) ;

	SETBIT( UCSRB , 3 );
	SETBIT( UCSRB , 4 );

	UCSRC = (1<<7) | (1<<2) | (1<<1) ;



}
*/
void UART_Init(uint32_t BoudRate){

	DIO_voidSetPinDirection(PORT_D,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORT_D,PIN0,INPUT);
/*
u16 UBRR_HELP;
UBRR_HELP=(F_CPU/(16*BoudRate))-1;
UBRRL=(uint8_t)(UBRR_HELP>>8);
UBRRH=(uint8_t)(UBRR_HELP);
*/
//select normal mode
 CLRBIT(UCSRA,1);
 CLRBIT(UCSRA,0);

SETBIT(UCSRB,3);
SETBIT(UCSRB,4);

uint8_t UCSRC_HELP=0;
SETBIT(UCSRC_HELP,7);
// 8bit data
CLRBIT(UCSRB,2);
SETBIT(UCSRC_HELP,2);
SETBIT(UCSRC_HELP,1);
//asynch.
CLRBIT(UCSRC_HELP,6);
//patity mode =disable
CLRBIT(UCSRC_HELP,4);
CLRBIT(UCSRC_HELP,5);
// 1 stop bit
CLRBIT(UCSRC_HELP,3);

UCSRC=UCSRC_HELP;
UBRRL=51;
UBRRH=0;
}

uint8_t UART_Recive(void){
uint8_t recived_data;
	while (0==GETBIT(UCSRA,7));
recived_data=UDR;
return recived_data;
}
/*
void UART_Transmite( uint8_t Copy_uint8_tData )
{
	while(!GETBIT(UCSRA,5)); // flags of intruupt

	UDR = Copy_uint8_tData ;
}

void UART_Transmite_String(uint8_t * Copy_Puint8_tString)
{
	for ( uint8_t Counter=0  ;  Copy_Puint8_tString[Counter]!='\0'  ;  Counter++ )
	{
		UART_Transmite( Copy_Puint8_tString[Counter] );
	}

}
*/
void UART_Transmite(uint8_t Data){
	while (0==GETBIT(UCSRA,5));
	UDR=Data;
}

void UART_Transmite_String(uint8_t *str){
	uint8_t i=0;
	while (str[i]!='\0'){
	UART_Transmite(str[i]);
	i++;
}

}


void UART_Recive_String(uint8_t *str){
uint8_t i=0;
	str[i]=UART_Recive();
	while(str[i]!='#'){

		i++;
		str[i]=UART_Recive();

	}
	str[i]='\0';
}
