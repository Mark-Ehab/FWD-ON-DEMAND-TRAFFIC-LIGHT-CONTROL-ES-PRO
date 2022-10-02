/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : Timer Interface                                */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

								/* Defining New DataTypes */

/* Define a pointer to function DataType */
typedef void(*fptr)(void);
								/* Interface Macros */

/* Timer 0 Interface Macros */

/*******************************************************************************/
/* Timer 1 Interface Macros */

/*******************************************************************************/
/* Timer 2 Interface Macros */

								/* Function Prototypes */

/* Timer 0 Function Prototypes */
void Timer_vidTimer0Init(void);
void Timer_vidTimer0Stop(void);
u8   Timer_u8Timer0SetBusyWait(u32 Copy_u32DelayTime_ms);
void Timer_vidTimer0EnableOvfInterrupt(void);
void Timer_vidTimer0DisableOvfInterrupt(void);
void Timer_vidTimer0EnableOcmInterrupt(void);
void Timer_vidTimer0DisableOcmIterrupt(void);
void Timer_vidTimer0SetOvfCallbackFunction(fptr Copy_CBFFunc);
void Timer_vidTimer0SetCtcCallbackFunction(fptr Copy_CBFFunc);

/************************ Timer 1 & Timer 2 ---> To Be Continued :) ************/
/* Timer 1 Function Prototypes */
//void Timer_vidTimer1Init(void);

/*******************************************************************************/
/* Timer 2 Function Prototypes */
//void Timer_vidTimer2Init(void);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
