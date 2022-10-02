/******************************************************************************************/
/* 						Author   	 : Mark Ehab                                          */
/* 						Date     	 : Sep 10, 2022                                       */
/* 						Description	 : Header file for APP layer auxiliary functions      */
/*                      Version      : V1.0                                       	      */
/******************************************************************************************/

#ifndef APP_APP_AUXILIARY_FUNCTIONS_H_
#define APP_APP_AUXILIARY_FUNCTIONS_H_

                            /* Interface Macros */

/* Defining LED States */
#define APP_AUX_LED_ON        (u8)0
#define APP_AUX_LED_OFF       (u8)1

							/* Functions Prototypes */

void APP_AUX_vidCarBlinkYellowLed(void);
void APP_AUX_vidCarAndPedBlinkYellowLed(void);
void APP_AUX_vidCarTurnOnOrOffGreenLed(u8 Copy_u8State);
void APP_AUX_vidCarTurnOnOrOffRedLed(u8 Copy_u8State);
void APP_AUX_vidPedTurnOnOrOffGreenLed(u8 Copy_u8State);
void APP_AUX_vidPedTurnOnOrOffRedLed(u8 Copy_u8State);
void APP_AUX_voidNormalMode(void);
void APP_AUX_voidPedestriansMode(void);

#endif /* APP_APP_AUXILIARY_FUNCTIONS_H_ */
