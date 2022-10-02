/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Oct 11, 2021                                   */
/* 						Description	 : EXTI Private                             	  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#include"../../LIB/STD_TYPES.h"

/*General Interrupt Control Register*/
#define GICR_REG 	*((volatile u8*)0x5B)
/*General Interrupt Flag Register*/
#define GIFR_REG 	*((volatile u8*)0x5A)
/*MCU Control Register*/
#define MCUCR_REG 	*((volatile u8*)0x55)
/*MCU Control and Status Register*/
#define MCUCSR_REG 	*((volatile u8*)0x54)

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
