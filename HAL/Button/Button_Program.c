/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : Button Program                                 */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_ERRORS.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "Button_Interface.h"
#include "Button_Config.h"

/**********************************************************************************/
/* Description     : A function to initialize port and pin to which pedestrians   */
/*                   button is connected                                          */
/* Input Arguments : void										                  */
/* Return          : void                       					              */
/**********************************************************************************/
void Button_vidButtonInit(void)
{
	/* Configure data direction of pedestrians button pin as INPUT */
	DIO_u8setPinDir(BTN_PED_PORT,BTN_PED_PIN,INPUT);
	/* Configure pedestrians button pin as PULLUP resistor */
	DIO_u8setPinVal(BTN_PED_PORT,BTN_PED_PIN,HIGH);
}

