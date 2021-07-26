/******************  Auther : Moataz Tarek */
/******************  Date   : 30/11/2020   */
/******************  Version: 1            */
/******************  Desc   :***********   */

#ifndef _LCD_INTERFACE_H_INCLUDED_H_
#define _LCD_INTERFACE_H_INCLUDED_H_

void LCD_VidInit(void);

void LCD_VidSendData(uint8_t Copy_uint8_tData);

void LCD_VidSendString(uint8_t Copy_uint8_tString);


void LCD_VidSendCommand(uint8_t Copy_uint8_tCommand);

void LCD_VidWriteString(uint8_t *str);
void LCD_IntegerToString(uint8_t copy_uint8_tnum);
void LCD_VidGoToRowColum(uint8_t Copy_uint8_tRow,uint8_t Copy_uint8_tColum );
void LCD_VidDisplayStringRow(uint8_t Copy_uint8_tRow, uint8_t Copy_uint8_tColum ,uint8_t *str);

void LCD_VidClearScreen (void);
void LCD_DrowChar( uint8_t POS, uint8_t* Copy_Puint8_tSpecialChar);
void LCD_DrowSpecial( uint8_t Length,uint8_t* Copy_Puint8_tSpecialChar , uint8_t ROW , uint8_t COL);


#endif
