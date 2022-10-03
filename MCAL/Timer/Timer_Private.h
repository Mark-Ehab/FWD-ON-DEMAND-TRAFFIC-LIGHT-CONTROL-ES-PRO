/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : Timer Private                                  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/


#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#include"../../LIB/STD_TYPES.h"
											/* Defining Timer Registers */
/*Timer/Counter Interrupt Mask Register*/
#define TIMSK 	*((volatile u8*)0x59)
/*Timer/Counter Interrupt Flag Register*/
#define TIFR    *((volatile u8*)0x58)
/*Timer0 Registers*/
#define TCCR0  	*((volatile u8*)0x53)
#define TCNT0 	*((volatile u8*)0x52)
#define OCR0   	*((volatile u8*)0x5C)
/*Timer1 Registers*/
#define TCCR1A 	*((volatile u8*)0x4F)
#define TCCR1B 	*((volatile u8*)0x4E)
#define TCNT1H 	*((volatile u8*)0x4D)
#define TCNT1L 	*((volatile u8*)0x4C)
#define OCR1AH 	*((volatile u8*)0x4B)
#define OCR1AL 	*((volatile u8*)0x4A)
#define OCR1BH 	*((volatile u8*)0x49)
#define OCR1BL 	*((volatile u8*)0x48)
#define ICR1H   *((volatile u8*)0x47)
#define ICR1L   *((volatile u8*)0x46)
/*Timer2 Registers*/
#define TCCR2  *((volatile u8*)0x45)
#define TCNT2  *((volatile u8*)0x44)
#define OCR2   *((volatile u8*)0x43)
										    /* Private Macros */
#define NULL (u8)0
/* Timer0 */
/* Timer/Counter0 Waveform Generation Mode Bits in TCCR0 Register */
#define TIMER_TIMER0_TCCR0_WGM01   3
#define TIMER_TIMER0_TCCR0_WGM00   6

/* Timer/Counter0 Clock Select bits values of each presacler in TCCR0 Register */
#define TIMER_TIMER0_TCCR0_NO_CLOCK_SRC     (u8)0b11111000
#define TIMER_TIMER0_TCCR0_PRESCALER_1    	(u8)0b00000001
#define TIMER_TIMER0_TCCR0_PRESCALER_8     	(u8)0b00000010
#define TIMER_TIMER0_TCCR0_PRESCALER_64    	(u8)0b00000011
#define TIMER_TIMER0_TCCR0_PRESCALER_256    (u8)0b00000100
#define TIMER_TIMER0_TCCR0_PRESCALER_1024  	(u8)0b00000101

/* Timer/Counter0 Overflow and Output Compare Match Interrupt Enable bits in TIMSK Register */
#define TIMER_TIMER0_TIMSK_TOIE0   0
#define TIMER_TIMER0_TIMSK_OCIE0   1

/* Timer/Counter0 Overflow and Output Compare Match Interrupt Flag bits in TIFR Register */
#define TIMER_TIMER0_TIFR_TOV0     0
#define TIMER_TIMER0_TIFR_OCF0     1

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
