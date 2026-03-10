#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

/* 
 * Timer0 Configuration File
 * 
 * CTC Mode Configuration:
 * - Clock: 16MHz
 * - Prescaler: 64
 * - OCR0: 249
 * - Result: 1ms per overflow (250 * 64 / 16MHz = 1ms)
 * - Overflow counter: 977 = ~977ms ? 1 second
 */

#define TMR0_PRELOAD_VALUE           112
#define TMR0_OVERFLOW_COUNTER        977
#define TMR0_OUTPUT_COMPARE_VALUE    249

/*
 * Options for TMR0 Operation Mode:
 * 1- TMR0_NORMAL_MODE
 * 2- TMR0_CTC_MODE
 */
#define TMR0_MODE                    TMR0_CTC_MODE

/*
 * Timer0 Usage Mode:
 * 1- TMR0_INTERRUPT_MODE (Uses ISR - requires GIE)
 * 2- TMR0_POLLING_MODE   (Manual flag checking - NO GIE needed)
 */
#define TMR0_USAGE_MODE              TMR0_POLLING_MODE

#endif /* TMR0_CONFIG_H_ */