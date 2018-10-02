#ifndef _DELAY_H
#define _DELAY_H
// ------ Public function prototype ---------------------------

// Timer preload values for use in simple (hardware) delays
// – Timers are 16-bit, manual reload ('one shot').
//
// NOTE: These values are portable but timings are *approximate*
// and *must* be checked by hand if accurate timing is
// required.
//

// Define Timer 0 / Timer 1 reload values for ~1 msec delay
// NOTE:
// Adjustment made to allow for function call overheard etc.
#define PRELOAD01 (65536 - (tWord)(OSC_FREQ / (OSC_PER_INST * 1020)))
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)

void Timer_set_value(bit timer, tWord ms);

void DELAY_T0_ms(tWord N);
void DELAY_T1_ms(tWord N);

void DELAY_loop_ms(tWord ms);
void DELAY_loop_ns(tWord ns);
#endif
/*------------------------------------------------------------*-
---- END OF FILE --------------------------------------------
-*------------------------------------------------------------*/