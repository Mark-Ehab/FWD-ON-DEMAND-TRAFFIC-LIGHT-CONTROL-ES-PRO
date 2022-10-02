/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Nov 7, 2021                                    */
/* 						Description	 : GIE Program                              	  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#include "../../LIB/STD_ERRORS.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"

/*
 * Enable and Disable the Global Interrupt
 */

u8 GIE_u8EnableGlobalInterrupt(u8 Copy_u8Flag)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8Flag == GIE_ENABLE || Copy_u8Flag == GIE_DISABLE)
	{
		switch(Copy_u8Flag)
		{
		case GIE_ENABLE:
			SREG_REG |= Copy_u8Flag;
			break;
		case GIE_DISABLE:
			SREG_REG &= Copy_u8Flag;
			break;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}

