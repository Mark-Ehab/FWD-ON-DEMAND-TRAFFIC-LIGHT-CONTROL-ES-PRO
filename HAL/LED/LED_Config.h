/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : LED Configuration                              */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

/* Configure LEDs port and pins for cars traffic light */
/* Port */
#define LED_CONFIG_CARS_PORT       PORT_A
/* Pins */
#define LED_CONFIG_CARS_GREEN_LED  PIN_0
#define LED_CONFIG_CARS_YELLOW_LED PIN_1
#define LED_CONFIG_CARS_RED_LED    PIN_2

/* Configure LEDs port and pins for pedestrians traffic light */
/* Port */
#define LED_CONFIG_PEDS_PORT       PORT_B
/* Pins */
#define LED_CONFIG_PEDS_GREEN_LED  PIN_0
#define LED_CONFIG_PEDS_YELLOW_LED PIN_1
#define LED_CONFIG_PEDS_RED_LED    PIN_2

#endif /* HAL_LED_LED_CONFIG_H_ */
