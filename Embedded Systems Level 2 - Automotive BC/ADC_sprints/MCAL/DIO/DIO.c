/**
 * @file DIO.c
 * @author Elgharib
 * @brief  This is a DIO File for Atmega32
 * @version 0.1
 * @date 2021-07-07
 * 
 */

#include "DIO_Interface.h"

/**
 * @brief This Function to change Pin value HIGH | LOW
 * 
 * @param EN_Port   PORT Name
 * @param EN_Pin    PIN Number
 * @param EN_Value  HIGH or LOW
 * @return EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_DIOERRORSTATE_t DIO_voidSetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin, EN_value_type EN_Value)
{
    EN_DIOERRORSTATE_t state;
    state = E_DIOOK;

    if (EN_Value == LOW)
    {
        switch (EN_Port)
        {
        case PORT_A:
            CLRBIT(PORTA, EN_Pin);
            break;
        case PORT_B:
            CLRBIT(PORTB, EN_Pin);
            break;
        case PORT_C:
            CLRBIT(PORTC, EN_Pin);
            break;
        case PORT_D:
            CLRBIT(PORTD, EN_Pin);
            break;
        default:
            state = E_DIOValue;
            break;
        }
    }
    else if (EN_Value == HIGH)
    {
        switch (EN_Port)
        {
        case PORT_A:
            SETBIT(PORTA, EN_Pin);
            break;
        case PORT_B:
            SETBIT(PORTB, EN_Pin);
            break;
        case PORT_C:
            SETBIT(PORTC, EN_Pin);
            break;
        case PORT_D:
            SETBIT(PORTD, EN_Pin);
            break;
        default:
            state = E_DIOValue;
            break;
        }
    }
    return state;
} /* DIO_voidSetPinValue */


/**
 * @brief This Function to change DIrection of Pins 
 * 
 * @param EN_port PORT Name
 * @param EN_Pin  PIN Number
 * @param EN_Direction Direction of the Pin INPUT | OUTPUT
 * @return EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_DIOERRORSTATE_t DIO_voidSetPinDirection(EN_port_num EN_port, EN_pin_num EN_Pin, EN_direction_type EN_Direction)
{
    EN_DIOERRORSTATE_t state;
    state = E_DIOOK;

    if (EN_Direction == INPUT)
    {
        switch (EN_port)
        {
        case PORT_A:
            CLRBIT(DDRA, EN_Pin);
            break;
        case PORT_B:
            CLRBIT(DDRB, EN_Pin);
            break;
        case PORT_C:
            CLRBIT(DDRC, EN_Pin);
            break;
        case PORT_D:
            CLRBIT(DDRD, EN_Pin);
            break;
        default:
            state = E_DIODirec;
            break;
        }
    }
    else if (EN_Direction == OUTPUT)
    {
        switch (EN_port)
        {
        case PORT_A:
            SETBIT(DDRA, EN_Pin);
            break;
        case PORT_B:
            SETBIT(DDRB, EN_Pin);
            break;
        case PORT_C:
            SETBIT(DDRC, EN_Pin);
            break;
        case PORT_D:
            SETBIT(DDRD, EN_Pin);
            break;
        default:
            state = E_DIODirec;
            break;
        }
    }
    return state;
} /* DIO_voidSetPinDirection */


/**
 * @brief This Function to check value in the pin 
 * 
 * @param EN_Port           PORT Name
 * @param EN_Pin            PIN Number
 * @return EN_value_type    return Pin HIGH | LOW
 */
EN_value_type DIO_uint8_tGetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    EN_value_type EN_ret_val;
    switch (EN_Port)
    {
    case PORT_A:
        EN_ret_val = GETBIT(PINA, EN_Pin);
        break;
    case PORT_B:
        EN_ret_val = GETBIT(PINB, EN_Pin);
        break;
    case PORT_C:
        EN_ret_val = GETBIT(PINC, EN_Pin);
        break;
    case PORT_D:
        EN_ret_val = GETBIT(PIND, EN_Pin);
        break;
    }
    return EN_ret_val;
} /* DIO_uint8_tGetPinValue */


/**
 * @brief This Function to Toggel Pin 
 * 
 * @param EN_Port PORT Name
 * @param EN_Pin PIN Number
 * @return EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_DIOERRORSTATE_t DIO_voidTogPin(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    EN_DIOERRORSTATE_t state;
    state = E_DIOOK;

    switch (EN_Port)
    {
    case PORT_A:
        TGLBIT(PORTA, EN_Pin);
        break;
    case PORT_B:
        TGLBIT(PORTB, EN_Pin);
        break;
    case PORT_C:
        TGLBIT(PORTC, EN_Pin);
        break;
    case PORT_D:
        TGLBIT(PORTD, EN_Pin);
        break;
    default:
        state = E_DIOPORT;
        break;
    }

    return state;
} /* DIO_voidTogPin */


/**
 * @brief This Funtion to Set Value of all Pins in the Port
 * 
 * @param EN_Port PORT Name
 * @param EN_Value HIGH | LOW
 * @return EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_DIOERRORSTATE_t DIO_voidSetPortValue(EN_port_num EN_Port, EN_value_type EN_Value)
{
    EN_DIOERRORSTATE_t state;
    state = E_DIOOK;
    switch (EN_Port)
    {
    case PORT_A:
        PORTA = EN_Value;
        break;
    case PORT_B:
        PORTB = EN_Value;
        break;
    case PORT_C:
        PORTC = EN_Value;
        break;
    case PORT_D:
        PORTD = EN_Value;
        break;
    default:
        state = E_DIOPORT;
        break;
    }
    return state;
} /* DIO_voidSetPortValue */


/**
 * @brief This Funtion to Set Direction of all Pins in the Port
 * 
 * @param EN_Port PORT Name
 * @param EN_Direction PORT Direction
 * @return EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_DIOERRORSTATE_t DIO_voidSetPortDirection(EN_port_num EN_Port, EN_direction_type EN_Direction)
{
    EN_DIOERRORSTATE_t state;
    state = E_DIOOK;

    switch (EN_Port)
    {
    case PORT_A:
        DDRA = EN_Direction;
        break;
    case PORT_B:
        DDRB = EN_Direction;
        break;
    case PORT_C:
        DDRC = EN_Direction;
        break;
    case PORT_D:
        DDRD = EN_Direction;
        break;
    default:
        state = E_DIOPORT;
        break;
    }
    return state;

} /* DIO_voidSetPortDirection */


/**
 * @brief This Function to change pin to Pull Up
 * 
 * @param EN_Port PORT Name
 * @param EN_Pin PIN Number
 * @return EN_ERRORSTATE_t E_OK OR ERROR
 */
EN_DIOERRORSTATE_t DIO_voidInpullUp(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    EN_DIOERRORSTATE_t state;
    state = E_DIOOK;
    switch (EN_Port)
    {
    case PORT_A:
        CLRBIT(DDRA, EN_Pin);
        SETBIT(PORTA, EN_Pin);
        break;
    case PORT_B:
        CLRBIT(DDRB, EN_Pin);
        SETBIT(PORTB, EN_Pin);
        break;
    case PORT_C:
        CLRBIT(DDRC, EN_Pin);
        SETBIT(PORTC, EN_Pin);
        break;
    case PORT_D:
        CLRBIT(DDRD, EN_Pin);
        SETBIT(PORTD, EN_Pin);
        break;
    default:
        state = E_DIOPORT;
        break;
    }
    return state;
} /* DIO_voidInpullUp */



EN_value_type DIO_u8GetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    EN_value_type EN_ret_val;
    switch (EN_Port)
    {
    case PORT_A:
        EN_ret_val = GETBIT(PINA, EN_Pin);
        break;
    case PORT_B:
        EN_ret_val = GETBIT(PINB, EN_Pin);
        break;
    case PORT_C:
        EN_ret_val = GETBIT(PINC, EN_Pin);
        break;
    case PORT_D:
        EN_ret_val = GETBIT(PIND, EN_Pin);
        break;
    }
    return EN_ret_val;
} /* DIO_u8GetPinValue */





EN_DIOERRORSTATE_t  DIO_voidSetfirstnippleDir(uint8_t copy_uint8_tport, uint8_t copy_uint8_tstate){
	if(copy_uint8_tstate == 1){
		switch(copy_uint8_tport){
		case 0:  DDRA |= 0x0f; break;
		case 1:  DDRB |= 0x0f; break;
		case 2:  DDRC |= 0x0f; break;
		case 3:  DDRD |= 0x0f; break;
		}
	}
	else if(copy_uint8_tstate == 0){
		switch(copy_uint8_tport){
		case 0:  DDRA &=~ 0xf0; break;
		case 1:  DDRB &=~ 0xf0; break;
		case 2:  DDRC &=~ 0xf0; break;
		case 3:  DDRD &=~ 0xf0; break;
		}

	}
}
EN_DIOERRORSTATE_t DIO_voidSetlastnippleDir(uint8_t copy_uint8_tport, uint8_t copy_uint8_tstate){
	if(copy_uint8_tstate == 1){
		switch(copy_uint8_tport){
		case 0:  DDRA |= 0xf0; break;
		case 1:  DDRB |= 0xf0; break;
		case 2:  DDRC |= 0xf0; break;
		case 3:  DDRD |= 0xf0; break;
		}
	}
	else if(copy_uint8_tstate == 0){
		switch(copy_uint8_tport){
		case 0:  DDRA &=~ 0xf0; break;
		case 1:  DDRB &=~ 0xf0; break;
		case 2:  DDRC &=~ 0xf0; break;
		case 3:  DDRD &=~ 0xf0; break;
		}
	}

}

EN_DIOERRORSTATE_t DIO_voidSetFirstNipple(uint8_t copy_u8port, uint8_t copy_u8val){
	switch(copy_u8port){
	case 0: PORTA = (PORTA & 0xf0) | (copy_u8val & 0x0f);  break;
	case 1: PORTB = (PORTB & 0xf0) | (copy_u8val & 0x0f);  break;
	case 2: PORTC = (PORTC & 0xf0) | (copy_u8val & 0x0f);  break;
	case 3: PORTD = (PORTD & 0xf0) | (copy_u8val & 0x0f);  break;
	}
}

EN_DIOERRORSTATE_t  DIO_voidSetLastNipple(uint8_t copy_u8port, uint8_t copy_u8val){
	switch(copy_u8port){
	case 0: PORTA = (PORTA & 0x0f) | (copy_u8val & 0xF0);  break;
	case 1: PORTB = (PORTB & 0x0f) | (copy_u8val & 0xF0);  break;
	case 2: PORTC = (PORTC & 0x0f) | (copy_u8val & 0xF0);  break;
	case 3: PORTD = (PORTD & 0x0f) | (copy_u8val & 0xF0);  break;
	}
}
EN_DIOERRORSTATE_t DIO_voidPlaceFirstNipple(uint8_t copy_uint8_tport, uint8_t copy_uint8_tval){

	switch(copy_uint8_tport){
	case 0: PORTA = (PORTA & 0x0f) | ((copy_uint8_tval & 0x0f)<<4);  break;
	case 1: PORTB = (PORTB & 0x0f) | ((copy_uint8_tval & 0x0f)<<4);  break;
	case 2: PORTC = (PORTC & 0x0f) | ((copy_uint8_tval & 0x0f)<<4);  break;
	case 3: PORTD = (PORTD & 0x0f) | ((copy_uint8_tval & 0x0f)<<4);  break;
	}
}

EN_DIOERRORSTATE_t DIO_voidPLaceLastNipple(uint8_t copy_uint8_tport, uint8_t copy_uint8_tval){
	switch(copy_uint8_tport){
	case 0: PORTA = (PORTA & 0x0F) | ((copy_uint8_tval & 0xf0)>>4);  break;
	case 1: PORTB = (PORTB & 0x0f) | ((copy_uint8_tval & 0xf0)>>4);  break;
	case 2: PORTC = (PORTC & 0x0f) | ((copy_uint8_tval & 0xf0)>>4);  break;
	case 3: PORTD = (PORTD & 0x0f) | ((copy_uint8_tval & 0xf0)>>4);  break;
	}
}
