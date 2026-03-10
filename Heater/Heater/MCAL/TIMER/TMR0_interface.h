#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

/* 
 * Timer0 Driver Interface
 * Supports both Interrupt and Polling modes
 */
#define NULL ((void *) 0)
/* ========== Basic Functions ========== */

/*
 * Initialize Timer0 based on configuration
 * Call this once at startup
 */
void TMR0_voidInit(void);

/*
 * Start Timer0 (Apply prescaler)
 */
void TMR0_voidStart(void);

/*
 * Stop Timer0 (Remove prescaler)
 */
void TMR0_voidStop(void);

/* ========== Interrupt Mode Functions ========== */

/*
 * Set callback function for overflow/compare match
 * Used in INTERRUPT_MODE only
 * 
 * Parameters:
 *   - ptpFunCallBack: Pointer to callback function
 */
void TMR0_voidSetCallBackOVF(void(*ptpFunCallBack)(void));

/* ========== Polling Mode Functions ========== */

/*
 * Get overflow flag status (for polling)
 * Used in POLLING_MODE
 * 
 * Parameters:
 *   - copy_pu8Flag: Pointer to store flag status
 *                   (TMR0_FLAG_SET or TMR0_FLAG_NOT_SET)
 * 
 * Returns:
 *   - Flag status (0 = not set, 1 = set)
 */
u8 TMR0_u8GetOverflowFlag(u8 *copy_pu8Flag);

/*
 * Clear overflow flag (after handling in polling mode)
 * Used in POLLING_MODE
 */
void TMR0_voidClearOverflowFlag(void);

/*
 * Get current timer counter value
 * 
 * Returns:
 *   - Current TCNT0 value
 */
u8 TMR0_u8GetCounterValue(void);

/*
 * Set timer counter value
 * 
 * Parameters:
 *   - copy_u8Value: Value to set in TCNT0
 */
void TMR0_voidSetCounterValue(u8 copy_u8Value);

#endif /* TMR0_INTERFACE_H_ */