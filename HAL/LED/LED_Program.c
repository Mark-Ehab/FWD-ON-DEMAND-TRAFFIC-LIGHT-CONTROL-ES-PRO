/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : LED Configuration                              */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_ERRORS.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED_Interface.h"
#include "LED_Config.h"

/**********************************************************************************/
/* Description     : A function to initialize ports and pins to which cars and    */
/*					 pedestrians traffic light LEDs are connected 			      */
/* Input Arguments : void										                  */
/* Return          : void                       					              */
/**********************************************************************************/
void LED_vidLEDInit(void)
{
	/* Configure data direction of both cars and pedestrians traffic light LEDs pins as OUTPUT */
	/* Cars Traffic Light */
	DIO_u8setPinDir(LED_CARS_PORT,LED_CONFIG_CARS_GREEN_LED,OUTPUT);  // Cars Green LED
	DIO_u8setPinDir(LED_CARS_PORT,LED_CONFIG_CARS_YELLOW_LED,OUTPUT); // Cars Yellow LED
	DIO_u8setPinDir(LED_CARS_PORT,LED_CONFIG_CARS_RED_LED,OUTPUT);    // Cars Red LED
	/* Pedestrians Traffic Light */
	DIO_u8setPinDir(LED_PEDS_PORT,LED_CONFIG_PEDS_GREEN_LED,OUTPUT);  // PEDs Green LED
	DIO_u8setPinDir(LED_PEDS_PORT,LED_CONFIG_PEDS_YELLOW_LED,OUTPUT); // PEDs Yellow LED
	DIO_u8setPinDir(LED_PEDS_PORT,LED_CONFIG_PEDS_RED_LED,OUTPUT);    // PEDs Red LED

	/* Configure both cars and pedestrians traffic light LEDs pins as LOW */
	/* Cars Traffic Light */
   	DIO_u8setPinVal(LED_CARS_PORT,LED_CONFIG_CARS_GREEN_LED,LOW);      // Cars Green LED
   	DIO_u8setPinVal(LED_CARS_PORT,LED_CONFIG_CARS_YELLOW_LED,LOW);	   // Cars Yellow LED
   	DIO_u8setPinVal(LED_CARS_PORT,LED_CONFIG_CARS_RED_LED,LOW);   	   // Cars Red LED
   	/* Pedestrians Traffic Light */
   	DIO_u8setPinVal(LED_PEDS_PORT,LED_CONFIG_PEDS_GREEN_LED,LOW); 	   // PEDs Green LED
   	DIO_u8setPinVal(LED_PEDS_PORT,LED_CONFIG_PEDS_YELLOW_LED,LOW);	   // PEDs Yellow LED
    DIO_u8setPinVal(LED_PEDS_PORT,LED_CONFIG_PEDS_RED_LED,LOW);   	   // PEDs Red LED
}
/**********************************************************************************/
/* Description     : A function to turn on a LED							      */
/* Input Arguments : u8 Copy_u8LEDPort , u8 Copy_u8LEDP			                  */
/* Return          : u8 	                      					              */
/**********************************************************************************/
u8 LED_u8TurnOnLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	u8 Local_u8Status = RT_OK;
	if((Copy_u8LEDPort >= PORT_A && Copy_u8LEDPort <= PORT_D )||(Copy_u8LEDPin >= PIN_0 && Copy_u8LEDPin <= PIN_7 ))
	{
		DIO_u8setPinVal(Copy_u8LEDPort,Copy_u8LEDPin,HIGH);
	}
	else
	{
		Local_u8Status = RT_NOK ;
	}
	return Local_u8Status;
}
/**********************************************************************************/
/* Description     : A function to turn off a LED							      */
/* Input Arguments : u8 Copy_u8LEDPort , u8 Copy_u8LEDP			                  */
/* Return          : u8 	                      					              */
/**********************************************************************************/
u8 LED_u8TurnOffLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	u8 Local_u8Status = RT_OK;
	if((Copy_u8LEDPort >= PORT_A && Copy_u8LEDPort <= PORT_D )||(Copy_u8LEDPin >= PIN_0 && Copy_u8LEDPin <= PIN_7 ))
	{
		DIO_u8setPinVal(Copy_u8LEDPort,Copy_u8LEDPin,LOW);
	}
	else
	{
		Local_u8Status = RT_NOK ;
	}
	return Local_u8Status;
}
/**********************************************************************************/
/* Description     : A function to toggle a LED state						      */
/* Input Arguments : u8 Copy_u8LEDPort , u8 Copy_u8LEDP			                  */
/* Return          : u8 	                      					              */
/**********************************************************************************/
u8 LED_u8ToggleLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin)
{
	u8 Local_u8Status = RT_OK;
	if((Copy_u8LEDPort >= PORT_A && Copy_u8LEDPort <= PORT_D )||(Copy_u8LEDPin >= PIN_0 && Copy_u8LEDPin <= PIN_7 ))
	{
		DIO_u8togglePin(Copy_u8LEDPort,Copy_u8LEDPin);
	}
	else
	{
		Local_u8Status = RT_NOK ;
	}
	return Local_u8Status;
}
