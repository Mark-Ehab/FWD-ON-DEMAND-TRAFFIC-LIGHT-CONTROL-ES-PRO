/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : LED Interface 	                              */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

								/* Interface Macros */

/* Cars Traffic Interface Macros */
/* Port */
#define LED_CARS_PORT       	  PORT_A
/* Pins */
#define LED_CARS_GREEN_LED_PIN    PIN_0
#define LED_CARS_YELLOW_LED_PIN   PIN_1
#define LED_CARS_RED_LED_PIN      PIN_2

/* Pedestrians Traffic Interface Macros */
/* Port */
#define LED_PEDS_PORT       	  PORT_B
/* Pins */
#define LED_PEDS_GREEN_LED_PIN    PIN_0
#define LED_PEDS_YELLOW_LED_PIN   PIN_1
#define LED_PEDS_RED_LED_PIN      PIN_2

								/* Function Prototypes */
void LED_vidLEDInit(void);
u8 LED_u8TurnOnLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);
u8 LED_u8TurnOffLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);
u8 LED_u8ToggleLed(u8 Copy_u8LEDPort , u8 Copy_u8LEDPin);

#endif /* HAL_LED_LED_INTERFACE_H_ */
