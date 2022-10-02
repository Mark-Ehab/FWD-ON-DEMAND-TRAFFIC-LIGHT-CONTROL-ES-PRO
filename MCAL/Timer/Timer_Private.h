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
#define TIMSK_REG *((volatile u8*)0x59)
/*Timer/Counter Interrupt Flag Register*/
#define TIFR_REG *((volatile u8*)0x58)
/*Timer0 Registers*/
#define TCCR0_REG  *((volatile u8*)0x53)
#define TCNT0_REG  *((volatile u8*)0x52)
#define OCR0_REG   *((volatile u8*)0x5C)
/*Timer1 Registers*/
#define TCCR1A_REG *((volatile u8*)0x4F)
#define TCCR1B_REG *((volatile u8*)0x4E)
#define TCNT1H_REG *((volatile u8*)0x4D)
#define TCNT1L_REG *((volatile u8*)0x4C)
#define OCR1AH_REG *((volatile u8*)0x4B)
#define OCR1AL_REG *((volatile u8*)0x4A)
#define OCR1BH_REG *((volatile u8*)0x49)
#define OCR1BL_REG *((volatile u8*)0x48)
#define ICR1H_REG  *((volatile u8*)0x47)
#define ICR1L_REG  *((volatile u8*)0x46)
/*Timer2 Registers*/
#define TCCR2_REG  *((volatile u8*)0x45)
#define TCNT2_REG  *((volatile u8*)0x44)
#define OCR2_REG   *((volatile u8*)0x43)
										    /* Private Macros */
#define NULL (u8)0
/* Timer0 */
/* Timer/Counter0 Waveform Generation Mode Bits in TCCR0 Register */
#define TIMER_TIMER0_TCCR0_WGM01   (u8)3
#define TIMER_TIMER0_TCCR0_WGM00   (u8)6
/* Timer/Counter0 Clock Select bits in TCCR0 Register */
#define TIMER_TIMER0_TCCR0_CS00    (u8)0
#define TIMER_TIMER0_TCCR0_CS01    (u8)1
#define TIMER_TIMER0_TCCR0_CS02    (u8)2
/* Timer/Counter0 Overflow and Output Compare Match Interrupt Enable bits in TIMSK Register */
#define TIMER_TIMER0_TIMSK_TOIE0   (u8)0
#define TIMER_TIMER0_TIMSK_OCIE0   (u8)1
/* Timer/Counter0 Overflow and Output Compare Match Interrupt Flag bits in TIFR Register */
#define TIMER_TIMER0_TIFR_TOV0     (u8)0
#define TIMER_TIMER0_TIFR_OCF0     (u8)1

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
