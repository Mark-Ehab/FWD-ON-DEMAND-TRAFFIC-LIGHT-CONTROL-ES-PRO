/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 25, 2022                                   */
/* 						Description	 : Timer Program                                  */
/*                      Version      : V1.0                                       	  */
/**************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_ERRORS.h"

#include "Timer_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"


/* Declaring Global Variables */
f32 Global_f32Timer0TickTime     = (f32)TIMER_TIMER0_PRESCALER/(f32)TIMER_MCU_CLK_FREQ ;
f32 Global_f32Timer0OverflowTime = ((f32)TIMER_TIMER0_PRESCALER/(f32)TIMER_MCU_CLK_FREQ) * (f32)256 ;

/* Declaring and initializing OVF and CTC callback functions as NULL */
static fptr Global_CBFOvfCallBackFunc = NULL ;
static fptr Global_CBFCtcCallBackFunc = NULL ;

/**********************************************************************************/
/* Description     : A function to initialize Timer0 according to configurations  */
/*                   provided in Timer_Config.h file                              */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0Init(void)
{
	/* Check Timer0 mode of operation based on configurations */
#if   TIMER_TIMER0_MODE == OVERFLOW_MODE
	/* Set Timer0 mode of operation to Normal (OverFlow) mode */
	CLR_BIT(TCCR0,TIMER_TIMER0_TCCR0_WGM00);
	CLR_BIT(TCCR0,TIMER_TIMER0_TCCR0_WGM01);
	//	/* Set overflow Preload value based on configurations*/
	//	TCNT0_REG = TIMER_TIMER0_PRELOAD_VAL ;
	/* Enable Timer0 overflow interrupt */
	//SET_BIT(TIMSK_REG,TIMER_TIMER0_TIMSK_TOIE0);
#elif TIMER_TIMER0_MODE == CTC_MODE
	/* To Be Continued */
#elif TIMER_TIMER0_MODE == FAST_PWM_MODE
	/* To Be Continued */
#elif TIMER_TIMER0_MODE == PWM_PHASE_CORRECT_MODE
	/* To Be Continued */
#else
#error "Wrong Timer0 mode configuration !"
#endif

	/* Check whether the clock provided to Timer0 is pre-scaled or not based on configurations */
#if   TIMER_TIMER0_PRESCALER == 1
	/* Select Input CLK to Timer0 the same as MCU CLK (No Prescaler) */
	TCCR0 |= TIMER_TIMER0_TCCR0_PRESCALER_1;
#elif TIMER_TIMER0_PRESCALER == 8
	/* Select Input CLK to Timer0 as MCU CLK divided by 8 Presacler */
	TCCR0 |= TIMER_TIMER0_TCCR0_PRESCALER_8;
#elif TIMER_TIMER0_PRESCALER == 64
	/* Select Input CLK to Timer0 as MCU CLK divided by 64 Presacler */
	TCCR0 |= TIMER_TIMER0_TCCR0_PRESCALER_64;
#elif TIMER_TIMER0_PRESCALER == 256
	/* Select Input CLK to Timer0 as MCU CLK divided by 256 Presacler */
	TCCR0 |= TIMER_TIMER0_TCCR0_PRESCALER_256;
#elif TIMER_TIMER0_PRESCALER == 1024
	/* Select Input CLK to Timer0 as MCU CLK divided by 1024 Presacler */
	TCCR0 |= TIMER_TIMER0_TCCR0_PRESCALER_1024;
#else
#error "Wrong Timer0 Prescaler configuration !"
#endif
}
/**********************************************************************************/
/* Description     : A function to stop Timer0									  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0Stop(void)
{
	/* Stop CLK source that enters Timer0 */
	TCCR0 &= TIMER_TIMER0_TCCR0_NO_CLOCK_SRC;
}
///**********************************************************************************/
///* Description     : A function used to delay the processor for a while           */
///* Input Arguments : u16 Copy_u32DelayTime_ms					                  */
///* Return          : u8                                                           */
///**********************************************************************************/
u8 Timer_u8Timer0SetBusyWait(u32 Copy_u32DelayTime_ms)
{
	u8 Local_u8Status = RT_OK ;
	if(Copy_u32DelayTime_ms < 4294967296)
	{
		/* Declaring some local variables */
		f32 Local_f32DelayTime_s = (Copy_u32DelayTime_ms * 0.001f);								// Calculate delay time in sec
		u32 Local_u32Timer0RequiredTicks = (Local_f32DelayTime_s/Global_f32Timer0TickTime);     // Number of required ticks
		u32 Local_u32Timer0OverflowCounter = 0 ;  											    // Timer0 overflow counter

		/* Calculate number of overflows required for desired delay */
		u32 Local_u32Timer0OverflowNum = 1+(Local_f32DelayTime_s/Global_f32Timer0OverflowTime) ;

		/* Set Timer0 Preload Value */
		TCNT0 = 256-(Local_u32Timer0RequiredTicks/Local_u32Timer0OverflowNum);

		/* Start Timer0 */
		Timer_vidTimer0Init();

		/* Wait until the delay is finished */
		while(Local_u32Timer0OverflowCounter < Local_u32Timer0OverflowNum)
		{
			/* Wait until TOV0 Flag is set by hardware */
			while(GET_BIT(TIFR,TIMER_TIMER0_TIFR_TOV0) != 1);
			/* Clear TOV0 Flag by writing 1 to its bit in TIFR Register */
			SET_BIT(TIFR,TIMER_TIMER0_TIFR_TOV0);
			Local_u32Timer0OverflowCounter++;
		}
	}
	else
	{
		Local_u8Status = RT_NOK;
	}

	return Local_u8Status;
}
/**********************************************************************************/
/* Description     : Enable Timer0 Overflow Interrupt							  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0EnableOvfInterrupt(void)
{
	SET_BIT(TIMSK,TIMER_TIMER0_TIMSK_TOIE0);
}
/**********************************************************************************/
/* Description     : Disable Timer0 Overflow Interrupt  						  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0DisableOvfInterrupt(void)
{
	CLR_BIT(TIMSK,TIMER_TIMER0_TIMSK_TOIE0);
}
/**********************************************************************************/
/* Description     : Enable Timer0 Output Compare Match Interrupt				  */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0EnableOcmInterrupt(void)
{
	SET_BIT(TIMSK,TIMER_TIMER0_TIMSK_OCIE0);
}
/**********************************************************************************/
/* Description     : Disable Timer0 Output Compare Match Interrupt	              */
/* Input Arguments : void						                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0DisableOcmIterrupt(void)
{
	CLR_BIT(TIMSK,TIMER_TIMER0_TIMSK_OCIE0);
}
/**********************************************************************************/
/* Description     : A function to register OverFlow callback function		      */
/* Input Arguments : CBF Copy_CBFFunc			                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0SetOvfCallbackFunction(fptr Copy_CBFFunc)
{
	Global_CBFOvfCallBackFunc = Copy_CBFFunc;
}
/**********************************************************************************/
/* Description     : A function to register CTC callback function    		      */
/* Input Arguments : CBF Copy_CBFFunc			                                  */
/* Return          : void                                                         */
/**********************************************************************************/
void Timer_vidTimer0SetCtcCallbackFunction(fptr Copy_CBFFunc)
{
	Global_CBFCtcCallBackFunc = Copy_CBFFunc;
}
/* Timer/Counter0 Compare Match Interrupt */
void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void)
{
	if(Global_CBFCtcCallBackFunc != NULL)
	{
		Global_CBFCtcCallBackFunc();
	}
}
/* Timer/Counter0 Overflow Interrupt */
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void)
{
	if(Global_CBFOvfCallBackFunc != NULL)
	{
		Global_CBFOvfCallBackFunc();
	}
}
