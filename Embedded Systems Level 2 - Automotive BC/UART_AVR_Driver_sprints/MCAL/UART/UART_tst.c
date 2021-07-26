/*
 * UART_tst.c
 *
 *  Created on: Jul 25, 2021
 *      Author: Al Badr
 */

#include <assert.h>
#include <stdio.h>
#include "../../lib/DataTypes.h"
#include "../../lib/BIT_Math.h"
#include "Uart_Config.h"


uint8_t UDR;
uint8_t UCSRA;
uint8_t UCSRB;
uint8_t UBRRL;
uint8_t UBRRH;
uint8_t UCSRC ;

EN_ERRORSTATE_t UART_Init(uint32_t BoudRate){



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
	return E_OK;
}


uint8_t UART_Recive(void){
	uint8_t recived_data;
	recived_data=UDR;
	return recived_data;
}

EN_ERRORSTATE_t UART_Transmite(uint8_t Data){
	UDR=Data;
	return E_OK;
}

void usart_InitTest(void)
{
    assert(UART_Init(9600) == E_OK);
    assert(UBRRL==51);
    assert(UCSRC == 0X86);
    assert(UCSRB== 0x18);
}


void usart_SendDataTest(void)
{
    assert(UART_Transmite('k')==E_OK);
}

void usart_ReceiveTest(void)
{
    assert(UART_Recive()=='k');
}
void main()
{
    usart_InitTest();
    usart_SendDataTest();
    usart_ReceiveTest();
    printf("No Error");

}
