/*****************************************************************************/
/* Title        	: 	Safety Box Project   						         */
/* File Name    	: 	Password.c                                           */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	09/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************* Delay DIRECTIVES ****************************
******************************************************************************/

#include <util/delay.h>

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/

#include "DIO_interface.h"

/******************************************************************************
********************************* KPD DIRECTIVES ******************************
******************************************************************************/

#include "KPD_interface.h"

/******************************************************************************
********************************* LCD DIRECTIVES ******************************
******************************************************************************/

#include "LCD_interface.h"

/******************************************************************************
********************************* SSD DIRECTIVES ******************************
******************************************************************************/

#include "SSD_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/

#include "Password.h"

/******************************************************************************
*************************** Global Variable Deceleration  *********************
******************************************************************************/

extern uint8 Global_u8Iteration;
extern uint8 Global_u8Count;
extern uint8 Global_u8Flag;


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/


/******************************************************************************
* Description 	: Application Function.						                  *
*                 Used to @ Correct Password.                                 *
******************************************************************************/

void CorrectPassword(void){

	LCD_voidClearScreen();
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Correct Password   ");

	SSD_voidDisplayNumber(0);

	/* Open the safey box */
	DIO_voidSetPinValue(PORT_B, PIN3, HIGH);
	DIO_voidSetPinValue(PORT_B, PIN4, HIGH);
	_delay_ms(500);

	/* Back to All Default Value */
	DIO_voidSetPinValue(PORT_B, PIN3, LOW);
	DIO_voidSetPinValue(PORT_B, PIN4, LOW);
	Global_u8Iteration = 0;
	Global_u8Count = 0;
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Enter Your Pass: ");
	LCD_voidSetPosition(1, 0);
	Global_u8Flag = 3;
	SSD_voidDisplayNumber(Global_u8Flag);
}


/******************************************************************************
* Description 	: Application Function.						                  *
*                 Used to @ Incorrect Password.                               *
******************************************************************************/

void IncorrectPassword(void){

	Global_u8Flag--;

	if(0 == Global_u8Flag){

		SSD_voidDisplayNumber(Global_u8Flag);

		DIO_voidSetPinValue(PORT_B, PIN5, HIGH);

		LCD_voidClearScreen();
		LCD_voidSetPosition(0, 0);
		LCD_voidWriteString("Incorrect Pass 3 ");
		LCD_voidSetPosition(1, 0);
		LCD_voidWriteString("times wait 30 Sec");

		_delay_ms(2000);

	}
	else{

		LCD_voidClearScreen();
		LCD_voidSetPosition(0, 0);
		LCD_voidWriteString("Incorrect Pass   ");
		LCD_voidSetPosition(1, 0);
		LCD_voidWriteString("Try Again...          ");

		SSD_voidDisplayNumber(Global_u8Flag);
	}

	_delay_ms(300);

	/* Back to All Default Value */
	Global_u8Iteration = 0;
	Global_u8Count = 0;
	DIO_voidSetPinValue(PORT_B, PIN5, LOW);
	LCD_voidClearScreen();
	LCD_voidSetPosition(0, 0);
	LCD_voidWriteString("Enter Your Pass: ");
	LCD_voidSetPosition(1, 0);

}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
