/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 10, 2022                                   */
/* 						Description	 : Program file for APP layer                     */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../HAL/Button/Button_Interface.h"
#include "APP_Auxiliary_Functions.h"
#include "APP.h"

void APP_vidAppInit()
{
	LED_vidLEDInit();
	Button_vidButtonInit();
	EXT_INT0_vidRegisterCallback(&APP_AUX_voidPedestriansMode);
	EXTI_u8INT0SenseControlConfiguration(EXTI_INT0_RISING_EGDE);
	EXTI_u8EnableINT0(EXTI_INT0_ENABLE);
	GIE_u8EnableGlobalInterrupt(GIE_ENABLE);
	while(1)
	{
		APP_AUX_voidNormalMode();
	}
}
