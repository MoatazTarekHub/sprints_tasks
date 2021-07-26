/*
 * Uart_Program.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Al Badr
 */


#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"
#include "Uart_Interface.h"
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
// enable transmite and recieve
	SETBIT(UCSRB,3);
	SETBIT(UCSRB,4);

	uint8_t UCSRC_HELP=0;
	SETBIT(UCSRC_HELP,7);
	//asynch.
	CLRBIT(UCSRC_HELP,6);
	// 8bit data
#if  character_size == eight
	SETBIT  (UCSRC_HELP,1);
	SETBIT  (UCSRC_HELP,2);
	CLRBIT(UCSRB,2);
#elif character_size == seven
	CLRBIT(UCSRC_HELP,1);
	SETBIT  (UCSRC_HELP,2);
	CLRBIT(UCSRB,2);

#elif character_size == six
	SETBIT   (UCSRC_HELP,1);
	CLRBIT (UCSRC_HELP,2);
	CLRBIT (UCSRB,2);

#elif character_size == five
	CLRBIT (UCSRC_HELP,1);
	CLRBIT  (UCSRC_HELP,2);
	CLRBIT (UCSRB,2);

#elif character_size == nine
	SETBIT (UCSRC_HELP,1);
	SETBIT (UCSRC_HELP,2);
	SETBIT (UCSRB,2);

#endif

#if clock_polarity_TXD == Rising
	CLRBIT(UCSRC_HELP, 0);
#elif clock_polarity_TXD == Falling
	SETBIT(UCSRC_HELP, 0);
#endif

	//patity mode =disable
#if parity_bit ==    odd_parity
	SETBIT(UCSRC_HELP,4);
	SETBIT(UCSRC_HELP,5);
#elif  parity_bit ==   even_parity
	CLRBIT(UCSRC_HELP,4);
	SETBIT  (UCSRC_HELP,5);
#elif  parity_bit ==   disable_parity
	CLRBIT(UCSRC_HELP,4);
	CLRBIT(UCSRC_HELP,5);
#endif

	// 1 stop bit
#if Num_of_Stop_bit == one
	CLRBIT(UCSRC_HELP ,3);
#elif Num_of_Stop_bit == two
	SETBIT(temp_UCSRC, 3);
#endif

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
