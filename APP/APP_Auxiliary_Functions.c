/*********************************************************************************************/
/* 						Author   	 : Mark Ehab                                             */
/* 						Date     	 : Sep 10, 2022                                          */
/* 						Description	 : Program file for APP layer auxiliary functions        */
/*                      Version      : V1.0                                       	         */
/*********************************************************************************************/

#include "../LIB/STD_TYPES.h"
#include "../LIB/STD_ERRORS.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "APP_Auxiliary_Functions.h"

/* Declaring Some Global Variables */
u8 Global_u8CarGreenLedCurrentState  = APP_AUX_LED_OFF;
u8 Global_u8CarYellowLedCurrentState = APP_AUX_LED_OFF;
u8 Global_u8CarRedLedCurrentState    = APP_AUX_LED_OFF;

/**********************************************************************************/
/* Description     : A function to blink yellow led of car traffic light		  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_vidCarBlinkYellowLed(void)
{
	/* Set Car Yellow LED Current State */
	Global_u8CarYellowLedCurrentState = APP_AUX_LED_ON;
	/* Blink Yellow Led of Car Traffic for 5 Secs */
	for(u8 Local_u8SecCounter = 0 ; Local_u8SecCounter < 5 ; Local_u8SecCounter++)
	{
		LED_u8TurnOnLed(LED_CARS_PORT , LED_CARS_YELLOW_LED_PIN);
		Timer_u8Timer0SetBusyWait(500);
		//_delay_ms (500);
		LED_u8TurnOffLed(LED_CARS_PORT , LED_CARS_YELLOW_LED_PIN);
		Timer_u8Timer0SetBusyWait(500);
		//_delay_ms (500);
	}
	/* Set Car Yellow LED Current State */
	Global_u8CarYellowLedCurrentState = APP_AUX_LED_OFF;
}
/**********************************************************************************/
/* Description     : A function to blink yellow led of both car and pedestrians   */
/* 					 traffic lights 											  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_vidCarAndPedBlinkYellowLed(void)
{
	/* Blink Yellow Led of Car Traffic for 5 Secs */
	for(u8 Local_u8SecCounter = 0 ; Local_u8SecCounter < 5 ; Local_u8SecCounter++)
	{
		LED_u8TurnOnLed(LED_CARS_PORT , LED_CARS_YELLOW_LED_PIN);
		LED_u8TurnOnLed(LED_PEDS_PORT , LED_PEDS_YELLOW_LED_PIN);
		Timer_u8Timer0SetBusyWait(500);
		//_delay_ms (500);
		LED_u8TurnOffLed(LED_CARS_PORT , LED_CARS_YELLOW_LED_PIN);
		LED_u8TurnOffLed(LED_PEDS_PORT , LED_PEDS_YELLOW_LED_PIN);
		Timer_u8Timer0SetBusyWait(500);
		//_delay_ms (500);
	}
}
/**********************************************************************************/
/* Description     : A function to either turn on or off green led of car traffic */
/* 					 light based on state passed to the function				  */
/* Input Arguments : u8 Copy_u8State			                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_vidCarTurnOnOrOffGreenLed(u8 Copy_u8State)
{
	if(Copy_u8State == APP_AUX_LED_ON)
	{
		LED_u8TurnOnLed(LED_CARS_PORT , LED_CARS_GREEN_LED_PIN);
	}
	else
	{
		LED_u8TurnOffLed(LED_CARS_PORT , LED_CARS_GREEN_LED_PIN);
	}
	/* Set Car Green LED Current State */
	Global_u8CarGreenLedCurrentState = Copy_u8State;
}
/**********************************************************************************/
/* Description     : A function to either turn on or off red led of car traffic   */
/* 					 light based on state passed to the function				  */
/* Input Arguments : u8 Copy_u8State			                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_vidCarTurnOnOrOffRedLed(u8 Copy_u8State)
{
	if(Copy_u8State == APP_AUX_LED_ON)
	{
		LED_u8TurnOnLed(LED_CARS_PORT , LED_CARS_RED_LED_PIN);
	}
	else
	{
		LED_u8TurnOffLed(LED_CARS_PORT , LED_CARS_RED_LED_PIN);
	}
	/* Set Car Red LED Current State */
	Global_u8CarRedLedCurrentState = Copy_u8State;
}
/**********************************************************************************/
/* Description     : A function to either turn on or off green led of Pedestrians */
/* 					 traffic light based on state passed to the function	   	  */
/* Input Arguments : u8 Copy_u8State			                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_vidPedTurnOnOrOffGreenLed(u8 Copy_u8State)
{
	if(Copy_u8State == APP_AUX_LED_ON)
	{
		LED_u8TurnOnLed(LED_PEDS_PORT , LED_PEDS_GREEN_LED_PIN);
	}
	else
	{
		LED_u8TurnOffLed(LED_PEDS_PORT , LED_PEDS_GREEN_LED_PIN);
	}
}
/**********************************************************************************/
/* Description     : A function to either turn on or off red led of Pedestrians   */
/* 					 traffic light based on state passed to the function	   	  */
/* Input Arguments : u8 Copy_u8State			                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_vidPedTurnOnOrOffRedLed(u8 Copy_u8State)
{
	if(Copy_u8State == APP_AUX_LED_ON)
	{
		LED_u8TurnOnLed(LED_PEDS_PORT , LED_PEDS_RED_LED_PIN);
	}
	else
	{
		LED_u8TurnOffLed(LED_PEDS_PORT , LED_PEDS_RED_LED_PIN);
	}
}
/**********************************************************************************/
/* Description     : A function to start Normal Mode (Car Traffic Lights)		  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_voidNormalMode(void)
{
	/* Turn On Car Green Led for 5 Secs */
	APP_AUX_vidCarTurnOnOrOffGreenLed(APP_AUX_LED_ON);
	Timer_u8Timer0SetBusyWait(5000);
	//_delay_ms (5000);
	APP_AUX_vidCarTurnOnOrOffGreenLed(APP_AUX_LED_OFF);

	/* Blink Car Yellow Led for 5 Secs */
	APP_AUX_vidCarBlinkYellowLed();

	/* Turn On Car Red Led for 5 Secs */
	APP_AUX_vidCarTurnOnOrOffRedLed(APP_AUX_LED_ON);
	Timer_u8Timer0SetBusyWait(5000);
	//_delay_ms (5000);
	APP_AUX_vidCarTurnOnOrOffRedLed(APP_AUX_LED_OFF);

	/* Blink Car Yellow Led for 5 Secs */
	APP_AUX_vidCarBlinkYellowLed();
}
/**********************************************************************************/
/* Description     : A function to start Pedestrians Mode						  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void APP_AUX_voidPedestriansMode(void)
{
	if(Global_u8CarRedLedCurrentState == APP_AUX_LED_ON)
	{
		/* Turn On Pedestrians Green LED for 5 Secs */
		APP_AUX_vidPedTurnOnOrOffGreenLed(APP_AUX_LED_ON);
		Timer_u8Timer0SetBusyWait(5000);
		//_delay_ms (5000);
	}
	else if(Global_u8CarGreenLedCurrentState == APP_AUX_LED_ON || Global_u8CarYellowLedCurrentState == APP_AUX_LED_ON)
	{
		/* Turn On Pedestrians Red LED and Both Yellow LEDs Blink for 5 Secs */
		APP_AUX_vidCarTurnOnOrOffGreenLed(APP_AUX_LED_OFF);
		APP_AUX_vidPedTurnOnOrOffRedLed(APP_AUX_LED_ON);
		APP_AUX_vidCarAndPedBlinkYellowLed();
		/* Turn Off Pedestrian Red LED and Turn On both Pedestrian Red LED and Car Green LED for 5 Secs */
		APP_AUX_vidPedTurnOnOrOffRedLed(APP_AUX_LED_OFF);
		APP_AUX_vidPedTurnOnOrOffGreenLed(APP_AUX_LED_ON);
		APP_AUX_vidCarTurnOnOrOffRedLed(APP_AUX_LED_ON);
		Timer_u8Timer0SetBusyWait(5000);
		//_delay_ms (5000);
	}
	/* Turn Off Car Red LED then Blink Both Yellow LEDs for 5 Secs while Pedestrian Green LED is still On */
	APP_AUX_vidCarTurnOnOrOffRedLed(APP_AUX_LED_OFF);
	APP_AUX_vidCarAndPedBlinkYellowLed();
	/* Turn Off Pedestrian Green LED and Turn On both Pedestrian Red LED and Car Green LED for 5 Secs then exit Pedestrians Mode */
	APP_AUX_vidPedTurnOnOrOffGreenLed(APP_AUX_LED_OFF);
	APP_AUX_vidPedTurnOnOrOffRedLed(APP_AUX_LED_ON);
	APP_AUX_vidCarTurnOnOrOffGreenLed(APP_AUX_LED_ON);
	Timer_u8Timer0SetBusyWait(5000);
	//_delay_ms (5000);
	APP_AUX_vidPedTurnOnOrOffRedLed(APP_AUX_LED_OFF);
	APP_AUX_vidCarTurnOnOrOffGreenLed(APP_AUX_LED_OFF);
}
