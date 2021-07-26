
#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT PORT_D


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */




uint8_t Read_Pin(void);

void KeyPad_Init(void);



#endif /* KEYPAD_H_ */
