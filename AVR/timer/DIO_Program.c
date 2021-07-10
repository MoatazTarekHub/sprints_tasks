/******************  Auther : Moataz Tarek */
/******************  Date   : 29/11/2020   */
/******************  Version: 1            */
/******************  Desc   :***********   */
#ifndef _DIO_PROGRAM_C
#define _DIO_PROGRAM_C


#include "std_type.h"
#include "DIO_Register.h"
#include "bit_math.h"

void DIO_Init(void){



}


void DIO_VidSetPortDirection(u8 Copy_U8Port, u8 Copy_U8Direction){
	if (0 == Copy_U8Direction ){
		switch (Copy_U8Port){
		 case 0:
		 DDRA=0;
		 break;
		 case 1:
		 DDRB=0;
		 break;
		 case 2:
		 DDRC=0;
		  break;
		 case 3:
		 DDRC=0;
		  break;
		}
	}
    if (1 == Copy_U8Direction){
		switch (Copy_U8Port){
		 case 0:
		 DDRA=0xff;
		 break;
		 case 1:
		 DDRB=0xff;
		 break;
		 case 2:
		 DDRC=0xff;
		  break;
		 case 3:
		 DDRD=0xff;
		  break;

		}
		
	}
	
	
}
void DIO_VidSetPinDirection (u8 Copy_U8Port ,u8 Copy_U8Pin, u8 Copy_U8Direction){
	
	if (0 == Copy_U8Direction ){
		switch (Copy_U8Port){
		 case 0:
		 CLR_BIT(DDRA,Copy_U8Pin);
		 break;
		 case 1:
		 CLR_BIT(DDRB,Copy_U8Pin);
		 break;
		 case 2:
		 CLR_BIT(DDRC,Copy_U8Pin);
		  break;
		 case 3:
		 CLR_BIT(DDRD,Copy_U8Pin);
		  break;
		}
	}
    if (1 == Copy_U8Direction){
		switch (Copy_U8Port){
		 case 0:
		 SET_BIT(DDRA,Copy_U8Pin);
		 break;
		 case 1:
		 SET_BIT(DDRB,Copy_U8Pin);
		 break;
		 case 2:
		 CLR_BIT(DDRC,Copy_U8Pin);
		  break;
		 case 3:
		 SET_BIT(DDRD,Copy_U8Pin);
		  break;

		}
		
	}
	
	
	
}
void DIO_VidSetPortValue    (u8 Copy_U8Port, u8 Copy_U8Value){
	switch(Copy_U8Port){
		
		 case 0:
		 PORTA=Copy_U8Value;
		 break;
		 case 1:
		 PORTB=Copy_U8Value;
		 break;
		 case 2:
		 PORTC=Copy_U8Value;
		  break;
		 case 3:
		 PORTD=Copy_U8Value;
		  break;
		}
	}
	
	




void DIO_VidSetPinValue     (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value){
	
	if (1==Copy_U8Value){
		switch(Copy_U8Port){
		 case 0:
		 SET_BIT(PORTA,Copy_U8Pin);
		 break;
		 case 1:
		 SET_BIT(PORTB,Copy_U8Pin);
		 break;
		 case 2:
		 CLR_BIT(PORTC,Copy_U8Pin);
		  break;
		 case 3:
		 SET_BIT(PORTD,Copy_U8Pin);
		  break;

		}
	}
	if (0==Copy_U8Value){
		switch (Copy_U8Port){
		 case 0:
		 CLR_BIT(PORTA,Copy_U8Pin);
		 break;
		 case 1:
		 CLR_BIT(PORTB,Copy_U8Pin);
		 break;
		 case 2:
		 CLR_BIT(PORTC,Copy_U8Pin);
		  break;
		 case 3:
		 CLR_BIT(PORTD,Copy_U8Pin);
		  break;
		}
		
	}
	
	
	
}
void DIO_VidTogglePin       (u8 Copy_U8Port, u8 Copy_U8Pin){
	
	switch(Copy_U8Port){
		
		 case 0:
		 TOGGLE_BIT(PORTA, Copy_U8Pin );
		 break;
		 case 1:
		 TOGGLE_BIT( PORTB, Copy_U8Pin );
		 break;
		 case 2:
		TOGGLE_BIT( PORTC, Copy_U8Pin );
		  break;
		 case 3:
		 TOGGLE_BIT( PORTD, Copy_U8Pin );
		  break;
		}
	
}
u8   DIO_U8GetPinValue      (u8 Copy_U8Port, u8 Copy_U8Pin){
	u8 pin_value;
	switch(Copy_U8Port){
		
		 case 0:
			 pin_value=GET_BIT( PINA , Copy_U8Pin );
		 break;
		 case 1:
			 pin_value=GET_BIT( PINB, Copy_U8Pin );
		 break;
		 case 2:
			 pin_value=GET_BIT( PINC, Copy_U8Pin );
		  break;
		 case 3:
			 pin_value= GET_BIT( PIND, Copy_U8Pin );
		  break;
		}
	return pin_value;
}

#endif
