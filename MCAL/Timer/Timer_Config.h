/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : Timer Configuration                            */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

/*****************************************************************/
/* Set MCU CLK Frequency 									     */
/* Note : CLock frequency in AVR ATMEGA 32 could be up to 16 MHz */
/*****************************************************************/
#define TIMER_MCU_CLK_FREQ 8000000UL

/* Timer 0 */

/******************************************************************/
/* Timer0 modes of operation:                                     */
/*                                                                */
/* Options:                                                       */
/* 			1) Normal (OverFlow)  ----> OVERFLOW_MODE             */
/* 			2) PWM, Phase Correct ----> PWM_PHASE_CORRECT_MODE    */
/* 			3) CTC                ----> CTC_MODE                  */
/* 			4) Fast PWM           ----> FAST_PWM_MODE             */
/*                                                                */
/* Default : Normal (OverFlow) ----> OVERFLOW_MODE                */
/*                                                                */
/******************************************************************/
#define TIMER_TIMER0_MODE OVERFLOW_MODE

/******************************************************************/
/* Timer0 prescalers:                                             */
/*                                                                */
/* Options:                                                       */
/* 			1) clkI/O/     (No prescaling)  ----> 1    		      */
/* 			2) clkI/O/8    (From prescaler) ----> 8               */
/* 			3) clkI/O/64   (From prescaler) ----> 64              */
/* 			4) clkI/O/256  (From prescaler) ----> 256             */
/* 			5) clkI/O/1024 (From prescaler) ----> 1024            */
/*                                                                */
/* Default : clkI/O/(No prescaling)  ----> 1      			      */
/*                                                                */
/******************************************************************/
#define TIMER_TIMER0_PRESCALER 1024


/************************ Timer 1 & Timer 2 ---> To Be Continued :) ************/
/* Timer 1 */

/******************************************************************************/
/* Timer 2 */

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
