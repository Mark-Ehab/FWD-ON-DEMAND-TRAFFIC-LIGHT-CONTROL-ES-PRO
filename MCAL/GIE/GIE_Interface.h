/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Nov 7, 2021                                    */
/* 						Description	 : GIE Interface                             	  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef MCAL_GIE_GIE_INTERFACE_H_
#define MCAL_GIE_GIE_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*
 * Macros
 */

/*Global Interrupt Enable and Disable Flags Macros*/

#define GIE_ENABLE							0b10000000
#define GIE_DISABLE							0b01111111

/***************************************************************/

/*
 * Functions Prototypes
 */

u8 GIE_u8EnableGlobalInterrupt(u8 Copy_u8Flag);

#endif /* MCAL_GIE_GIE_INTERFACE_H_  */
