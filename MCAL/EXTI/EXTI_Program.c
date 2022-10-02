/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Oct 11, 2021                                   */
/* 						Description	 : EXTI Program	                            	  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_ERRORS.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

static Callback_Function local_Callback_FunctionInt0Function = NULL ;
static Callback_Function local_Callback_FunctionInt1Function = NULL ;
static Callback_Function local_Callback_FunctionInt2Function = NULL ;

/*
 * Enable and Disable External Interrupts
 */

/*Enable and Disable INT0*/
u8 EXTI_u8EnableINT0(u8 Copy_u8Flag)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8Flag == EXTI_INT0_ENABLE || Copy_u8Flag == EXTI_INT0_DISABLE)
	{
		switch(Copy_u8Flag)
		{
		case EXTI_INT0_ENABLE:
			GICR_REG |= Copy_u8Flag;
			break;
		case EXTI_INT0_DISABLE:
			GICR_REG &= Copy_u8Flag;
			break;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}
/*Enable and Disable INT1*/
u8 EXTI_u8EnableINT1(u8 Copy_u8Flag)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8Flag == EXTI_INT1_ENABLE || Copy_u8Flag == EXTI_INT1_DISABLE)
	{
		switch(Copy_u8Flag)
		{
		case EXTI_INT1_ENABLE:
			GICR_REG |= Copy_u8Flag;
			break;
		case EXTI_INT1_DISABLE:
			GICR_REG &= Copy_u8Flag;
			break;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}
/*Enable and Disable INT2*/
u8 EXTI_u8EnableINT2(u8 Copy_u8Flag)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8Flag == EXTI_INT2_ENABLE || Copy_u8Flag == EXTI_INT2_DISABLE)
	{
		switch(Copy_u8Flag)
		{
		case EXTI_INT2_ENABLE:
			GICR_REG |= Copy_u8Flag;
			break;
		case EXTI_INT2_DISABLE:
			GICR_REG &= Copy_u8Flag;
			break;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}

/*
 * Configure the sense control for external interrupts
 */

/*Configure INT0 Sense Control*/
u8 EXTI_u8INT0SenseControlConfiguration(ISC_INT0_e Copy_u8ISC)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8ISC == EXTI_INT0_LOW_LEVEL || Copy_u8ISC == EXTI_INT0_ANY_LOGICAL_CHANGE || Copy_u8ISC == EXTI_INT0_FALLING_EDGE || Copy_u8ISC == EXTI_INT0_RISING_EGDE)
	{
		u8 local_u8MCUCRTemp = MCUCR_REG;
		local_u8MCUCRTemp &= EXTI_INT0_CLEAR_SENSE_CONTROL;
		local_u8MCUCRTemp |= Copy_u8ISC;
		MCUCR_REG = local_u8MCUCRTemp;
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}
/*Configure INT1 Sense Control*/
u8 EXTI_u8INT1SenseControlConfiguration(ISC_INT1_e Copy_u8ISC)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8ISC == EXTI_INT1_LOW_LEVEL || Copy_u8ISC == EXTI_INT1_ANY_LOGICAL_CHANGE || Copy_u8ISC == EXTI_INT1_FALLING_EDGE || Copy_u8ISC == EXTI_INT1_RISING_EGDE)
	{
		u8 local_u8MCUCRTemp = MCUCR_REG;
		local_u8MCUCRTemp &= EXTI_INT1_CLEAR_SENSE_CONTROL;
		local_u8MCUCRTemp |= Copy_u8ISC;
		MCUCR_REG = local_u8MCUCRTemp;
	}
	else
	{

		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}
/*Configure INT2 Sense Control*/
u8 EXTI_u8INT2SenseControlConfiguration(ISC_INT2_e Copy_u8ISC)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8ISC == EXTI_INT2_FALLING_EDGE || Copy_u8ISC == EXTI_INT2_RISING_EGDE)
	{
		u8 local_u8MCUCSRTemp = MCUCSR_REG;
		local_u8MCUCSRTemp &= EXTI_INT2_CLEAR_SENSE_CONTROL;
		local_u8MCUCSRTemp |= Copy_u8ISC;
		MCUCSR_REG = local_u8MCUCSRTemp;
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return(local_u8errStatus);
}

/*
 * Callback Register Functions
 */

/*External INT0 Registration Function*/
void EXT_INT0_vidRegisterCallback(Callback_Function Copy_u8fptr)
{
	local_Callback_FunctionInt0Function=Copy_u8fptr;
}
/*External INT1 Registration Function*/
void EXT_INT1_vidRegisterCallback(Callback_Function Copy_u8fptr)
{
	local_Callback_FunctionInt1Function=Copy_u8fptr;
}
/*External INT2 Registration Function*/
void EXT_INT2_vidRegisterCallback(Callback_Function Copy_u8fptr)
{
	local_Callback_FunctionInt2Function=Copy_u8fptr;
}
/*
 * External Interrupt Service Routines
 */

/*External INT0*/
void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_1 (void)
{
	if(local_Callback_FunctionInt0Function != NULL)
	{
		local_Callback_FunctionInt0Function();
	}
}
/*External INT1*/
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_2 (void)
{
	if(local_Callback_FunctionInt1Function != NULL)
	{
		local_Callback_FunctionInt1Function();
	}
}
/*External INT2*/
void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_3 (void)
{
	if(local_Callback_FunctionInt2Function != NULL)
	{
		local_Callback_FunctionInt2Function();
	}
}
