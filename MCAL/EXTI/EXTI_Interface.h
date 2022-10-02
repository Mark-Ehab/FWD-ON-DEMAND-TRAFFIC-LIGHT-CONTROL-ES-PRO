/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Oct 11, 2021                                   */
/* 						Description	 : EXTI Interface                             	  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*
 * Defining New Datatypes
 */

typedef void(*Callback_Function)(void);

/**************************************************************************/

/*
 * Macros
 */

/*Defining Null as 0 Macro*/

#define NULL 									(u8)0

/*External Interrupts Enable and Disable Flags Macros*/

/**External Interrupts (INT0, INT1 and INT2) Enable Flags**/

#define EXTI_INT0_ENABLE						(u8)0b01000000
#define EXTI_INT1_ENABLE						(u8)0b10000000
#define EXTI_INT2_ENABLE						(u8)0b00100000

/**External Interrupts (INT0, INT1 and INT2) Disable Flags**/

#define EXTI_INT0_DISABLE						(u8)0b10111111
#define EXTI_INT1_DISABLE						(u8)0b01111111
#define EXTI_INT2_DISABLE						(u8)0b11011111

/**Clear Interrupts (INT0, INT1 and INT2) Sense Controls**/

#define EXTI_INT0_CLEAR_SENSE_CONTROL 			(u8)0b11111100
#define EXTI_INT1_CLEAR_SENSE_CONTROL 			(u8)0b11110011
#define EXTI_INT2_CLEAR_SENSE_CONTROL 			(u8)0b10111111


/**************************************************************************/

/*
 * Enums
 */

/*Interrupt Sense Controls For Each External Interrupt*/

/**External Interrupt INT0**/

typedef enum
{
	EXTI_INT0_LOW_LEVEL = 					(u8)0b00000000,
	EXTI_INT0_ANY_LOGICAL_CHANGE = 			(u8)0b00000001,
	EXTI_INT0_FALLING_EDGE = 				(u8)0b00000010,
	EXTI_INT0_RISING_EGDE =					(u8)0b00000011
}ISC_INT0_e;

/**External Interrupt INT1**/

typedef enum
{
	EXTI_INT1_LOW_LEVEL = 					(u8)0b00000000,
	EXTI_INT1_ANY_LOGICAL_CHANGE =  		(u8)0b00000100,
	EXTI_INT1_FALLING_EDGE = 				(u8)0b00001000,
	EXTI_INT1_RISING_EGDE =					(u8)0b00001100
} ISC_INT1_e;

/**External Interrupt INT2**/

typedef enum
{
	EXTI_INT2_FALLING_EDGE =				(u8)0b00000000,
	EXTI_INT2_RISING_EGDE =					(u8)0b01000000
}ISC_INT2_e;

/**************************************************************************/

/*
 * Functions Prototypes
 */

u8 EXTI_u8EnableINT0(u8 Copy_u8Flag);
u8 EXTI_u8EnableINT1(u8 Copy_u8Flag);
u8 EXTI_u8EnableINT2(u8 Copy_u8Flag);
u8 EXTI_u8INT0SenseControlConfiguration(ISC_INT0_e Copy_u8ISC);
u8 EXTI_u8INT1SenseControlConfiguration(ISC_INT1_e Copy_u8ISC);
u8 EXTI_u8INT2SenseControlConfiguration(ISC_INT2_e Copy_u8ISC);
void EXT_INT0_vidRegisterCallback(Callback_Function Copy_u8fptr);
void EXT_INT1_vidRegisterCallback(Callback_Function Copy_u8fptr);
void EXT_INT2_vidRegisterCallback(Callback_Function Copy_u8fptr);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
