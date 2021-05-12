/*****************************************************************************/
/* Title        	: 	Safety Box Project   						         */
/* File Name    	: 	main.c                                               */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	09/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <stdio.h>
#include <util/delay.h>


#include "DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "SSD_interface.h"

#include "Password.h"

uint8 Global_u8Iteration = 0;
uint8 Global_u8Count = 0;
uint8 Global_u8Flag = 3;



int main(void){

	DIO_voidSetPinDirection(PORT_B, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, PIN6, OUTPUT);

	KPD_voidInit();
	LCD_voidInit();
	SSD_voidInit();

	/* LCD displays “Enter Your Password” @ Row_1 */
	LCD_voidWriteString("Enter Your Pass: ");
	LCD_voidSetPosition(1, 0);


	uint8 MyPassword[] = "1234";

	uint8 Local_u8KPDresult = 0;
	uint8 Local_u8Number = sizeof(MyPassword)-1;
	uint8 EnterPassword[sizeof(MyPassword)-1];

	SSD_voidDisplayNumber(Global_u8Flag);

	while(1){

		DIO_voidSetPinValue(PORT_B, PIN6, HIGH);

		while(Global_u8Flag>0){

			Local_u8KPDresult = KPD_u8GetPressedKey(4,3);

			if((Local_u8KPDresult > NULL) && (Local_u8KPDresult != '#')){

				LCD_voidWriteData('*');
				EnterPassword[Global_u8Iteration] = Local_u8KPDresult;
				Global_u8Iteration++;

			}
			else if('#' == Local_u8KPDresult){

				if(Global_u8Iteration == Local_u8Number){

					for(uint8 j=0; j<Local_u8Number; j++){

						if(EnterPassword[j] == MyPassword[j]){  Global_u8Count++;  }
					}

					if(Global_u8Count == Local_u8Number){  CorrectPassword();  }

					else{   IncorrectPassword();   }
			}
			else{  IncorrectPassword();  }
			}
		}

		Global_u8Flag = 3;
		SSD_voidDisplayNumber(Global_u8Flag);

	}

	return 0;
}

