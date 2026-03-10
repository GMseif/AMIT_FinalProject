/* UTILES_LIB */
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"
#include "TMR0_private.h"
#include "TMR0_register.h"

/* Static callback pointer for interrupt mode */
static void(*PRV_ptoFunCallBackOVF)(void) = NULL;

/* ========== INITIALIZATION ========== */
void TMR0_voidInit(void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
	
	/* Select Normal Mode */
	CLR_BIT(TCCR0_REG, WGM00);
	CLR_BIT(TCCR0_REG, WGM01);
	
	/* Set Preload Value */
	TCNT0_REG = TMR0_PRELOAD_VALUE;
	
	#if TMR0_USAGE_MODE == TMR0_INTERRUPT_MODE
	/* Enable Overflow Interrupt */
	SET_BIT(TIMSK_REG, TOIE0);
	#endif
	
	#elif TMR0_MODE == TMR0_CTC_MODE
	
	/* Select CTC Mode */
	CLR_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);
	
	/* Set Compare Value */
	OCR0_REG = TMR0_OUTPUT_COMPARE_VALUE;
	
	#if TMR0_USAGE_MODE == TMR0_INTERRUPT_MODE
	/* Enable Compare Match Interrupt */
	SET_BIT(TIMSK_REG, OCIE0);
	#endif
	
	#endif
}

/* ========== START TIMER ========== */
void TMR0_voidStart(void)
{
	/* Select Prescaler Value = 64 */
	SET_BIT(TCCR0_REG, CS00);
	SET_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
}

/* ========== STOP TIMER ========== */
void TMR0_voidStop(void)
{
	/* Clear all prescaler bits (No clock source) */
	CLR_BIT(TCCR0_REG, CS00);
	CLR_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
}

/* ========== SET CALLBACK (For Interrupt Mode) ========== */
void TMR0_voidSetCallBackOVF(void(*ptpFunCallBack)(void))
{
	if(ptpFunCallBack != NULL)
	{
		PRV_ptoFunCallBackOVF = ptpFunCallBack;
	}
}

/* ========== GET OVERFLOW FLAG (For Polling Mode) ========== */
u8 TMR0_u8GetOverflowFlag(u8 *copy_pu8Flag)
{
	u8 local_u8FlagStatus;
	
	#if TMR0_MODE == TMR0_NORMAL_MODE
	/* In Normal Mode, check TOV0 flag */
	local_u8FlagStatus = GET_BIT(TIFR_REG, TOV0);
	
	#elif TMR0_MODE == TMR0_CTC_MODE
	/* In CTC Mode, check OCF0 flag */
	local_u8FlagStatus = GET_BIT(TIFR_REG, OCF0);
	
	#endif
	
	/* Store flag status */
	if(copy_pu8Flag != NULL)
	{
		*copy_pu8Flag = local_u8FlagStatus;
	}
	
	return local_u8FlagStatus;
}

/* ========== CLEAR OVERFLOW FLAG (For Polling Mode) ========== */
void TMR0_voidClearOverflowFlag(void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
	/* Clear TOV0 flag by writing 1 to it */
	SET_BIT(TIFR_REG, TOV0);
	
	#elif TMR0_MODE == TMR0_CTC_MODE
	/* Clear OCF0 flag by writing 1 to it */
	SET_BIT(TIFR_REG, OCF0);
	
	#endif
}

/* ========== GET COUNTER VALUE ========== */
u8 TMR0_u8GetCounterValue(void)
{
	return TCNT0_REG;
}

/* ========== SET COUNTER VALUE ========== */
void TMR0_voidSetCounterValue(u8 copy_u8Value)
{
	TCNT0_REG = copy_u8Value;
}

/* ========== INTERRUPT SERVICE ROUTINE ========== */
#if TMR0_USAGE_MODE == TMR0_INTERRUPT_MODE

/* ISR for Timer0 Compare Match (CTC) or Overflow (Normal) */
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u16 local_u16Counter = 0;
	local_u16Counter++;
	
	if(local_u16Counter == TMR0_OVERFLOW_COUNTER)
	{
		/* Reload Value if in Normal Mode */
		#if TMR0_MODE == TMR0_NORMAL_MODE
		TCNT0_REG = TMR0_PRELOAD_VALUE;
		#endif
		
		/* Clear Counter */
		local_u16Counter = 0;

		/* Call callback function */
		if(PRV_ptoFunCallBackOVF != NULL)
		{
			PRV_ptoFunCallBackOVF();
		}
	}
}

#endif /* TMR0_USAGE_MODE == TMR0_INTERRUPT_MODE */