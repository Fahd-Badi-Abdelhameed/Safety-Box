/*****************************************************************************/
/* Title        	: 	Safety Box Project   						         */
/* File Name    	: 	Password.h                                           */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	09/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include mor 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef PASSWORD_H_
#define PASSWORD_H_

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description : Application Function, Used to @ Correct Password.	          *
* Parameters  : none.                                                    	  *
* Return type : void                                                  	 	  *
******************************************************************************/

void CorrectPassword(void);

/******************************************************************************
* Description : Application Function, Used to @ Incorrect Password.	          *
* Parameters  : none.                                                    	  *
* Return type : void                                                  	 	  *
******************************************************************************/

void IncorrectPassword(void);


#endif
/*** !comment : End of gaurd [PASSWORD_H_] ***********************************/
