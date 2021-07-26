#include "DataTypes.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"

#include <avr/delay.h>



void LCD_VidSendCommand(uint8_t Copy_uint8_tCommand){
	_delay_ms(5);

	DIO_voidSetPinValue(Control_Port,RS,LOW);	// RS=0 D0
	DIO_voidSetPinValue(Control_Port,RW,LOW);  // RW=0 D1
	_delay_ms(1);
	DIO_voidSetPinValue (Control_Port,EN,HIGH);  // Enable
	_delay_ms(1);


#if (DATA_BITS_MODE == 4)
	/* out the highest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
	DIO_voidSetLastNipple(Data_Port,  Copy_uint8_tCommand);
#else
	DIO_voidPLaceLastnipple(Data_Port, Copy_uint8_tCommand);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(Control_Port, EN,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidSetPinValue(Control_Port, EN,HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
	DIO_voidPlaceFirstNipple(Data_Port,  Copy_uint8_tCommand );
	_delay_ms(1);
#else
	DIO_voidSetFirstNipple(Data_Port,  Copy_uint8_tCommand);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(Control_Port, EN,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */


#elif (DATA_BITS_MODE == 8)

	DIO_voidSetPortValue (Data_Port,Copy_uint8_tCommand);  //PORT Data
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue (Control_Port,EN,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}


void LCD_VidInit(void){
	DIO_voidSetPinDirection (Control_Port ,RS,OUTPUT);
	DIO_voidSetPinDirection (Control_Port ,RW,OUTPUT);
	DIO_voidSetPinDirection (Control_Port ,EN,OUTPUT);
#if (DATA_BITS_MODE == 4)
#ifdef UPPER_PORT_PINS
	DIO_voidSetlastnippleDir (Data_Port, OUTPUT);
	_delay_ms(80);

#else
	DIO_SetfirstnippleDir(LCD_DATA_CONNECTED_PORT, 1);
#endif
	LCD_VidSendCommand( Four_Bit_Mode); /* initialize LCD in 4-bit mode */
	_delay_ms(1);

	LCD_VidSendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode +
5*7 dot display Mode */
	_delay_ms(1);

	LCD_VidSendCommand(CURSOR_ON);
	_delay_ms(5);

#elif (DATA_BITS_MODE == 8)
	DIO_voidSetPortDirection(Data_Port, 0xff);
	_delay_ms(80);
		LCD_VidSendCommand(0b00111000);   // 8_bit mode // two line
		_delay_ms(1);
		LCD_VidSendCommand(0b00001111);   //
		_delay_ms(1);
		LCD_VidSendCommand(0b00000001);   // 8_bit mode
		_delay_ms(5);
#endif

}



void LCD_VidSendData(uint8_t Copy_uint8_tData){

	_delay_ms(5);

	DIO_voidSetPinValue(Control_Port,RS,HIGH);	// RS=1 D0
	DIO_voidSetPinValue(Control_Port,RW,LOW);  // RW=0 D1
	_delay_ms(1);
	DIO_voidSetPinValue (Control_Port,EN,HIGH);  // Enable
	_delay_ms(1);
#if (DATA_BITS_MODE == 4)
	/* out the highest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
	DIO_voidSetLastNipple(Data_Port,  Copy_uint8_tData);
#else
	DIO_voidPLaceLastnipple(LCD_DATA_CONNECTED_PORT, Copy_U8Data);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(Control_Port, EN,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidSetPinValue(Control_Port, EN,HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
	DIO_voidPlaceFirstNipple(Data_Port,  Copy_uint8_tData );
	_delay_ms(1);
#else
	DIO_voidSetFirstNipple(LCD_DATA_CONNECTED_PORT,  Copy_U8Data);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(Control_Port, EN,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#elif (DATA_BITS_MODE == 8)

	DIO_voidSetPortValue (Data_Port,Copy_uint8_tData);  //PORT Data
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue (Control_Port,EN,LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}


void LCD_VidSendNumber(uint32_t num){
	uint8_t rev;

	while (num>0){

		uint8_t rev;
		rev=(rev*10)+(num%10);
		num=num/10;

	}


	while(rev>0){

		LCD_VidSendData(48+(rev%10));
		rev=rev/10;

	}


}

void LCD_VidWriteString(char *str)
{
	uint8_t i=0;
	while(str[i]!='\0'){
		// loop will go on till the NULL character in the string
		LCD_VidSendData(str[i]); // sending data on LCD byte by byte
		i++;
	}
}
void LCD_IntegerToString(uint8_t copy_uint8_tnum){
	uint32_t i, rem, len = 0, n;
	uint8_t str[20]={0};

	n = copy_uint8_tnum;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = copy_uint8_tnum % 10;
		copy_uint8_tnum = copy_uint8_tnum / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	LCD_VidWriteString(str);
}

void LCD_VidGoToRowColum(uint8_t Copy_uint8_tRow,uint8_t Copy_uint8_tColum ){

	uint8_t address;
	switch(Copy_uint8_tRow){
	case 0: address= Copy_uint8_tColum; break;
	case 1: address= Copy_uint8_tColum +0x40; break;
	}

	LCD_VidSendCommand(address|0x80);


}
void LCD_DrowChar( uint8_t POS, uint8_t* Copy_Puint8_tSpecialChar)
{
	LCD_VidSendCommand(0x40 + (POS*8)); // 0b01000000; //64 /*0x40 GOTO CGRAM */
	for(uint8_t i=0 ; i<8 ; i++)
	{
		LCD_VidSendData(Copy_Puint8_tSpecialChar[i]);
	}
	LCD_VidSendCommand(0x80);//first address in ddram
}

void LCD_DrowSpecial( uint8_t Length,uint8_t* Copy_Puint8_tSpecialChar , uint8_t ROW , uint8_t COL)
{

	LCD_VidSendCommand(0x40); // 0b01000000; //64
	for(uint8_t i=0 ; i<(Length*8); i++)
	{
		LCD_VidSendData(Copy_Puint8_tSpecialChar[i]);
	}
	LCD_VidSendCommand(0x80);//first address in ddram
	LCD_VidGoToRowColum(ROW,COL);

	for( sint8_t j = Length-1  ; j >= 0   ; j-- )
	{
		LCD_VidSendData(j);

	}
}



void LCD_VidDisplayStringRow(uint8_t Copy_uint8_tRow, uint8_t Copy_uint8_tColum ,uint32_t *str){

	LCD_VidGoToRowColum(Copy_uint8_tRow,Copy_uint8_tColum);
	LCD_VidWriteString(str);

}
void LCD_VidClearScreen (void)
{
	/*send CLear screen command */
	LCD_VidSendCommand(0x01);
	_delay_ms(10);
}

