/*------------------------------------------------------------*-
Main.H (v1.00)
-------------------------------------------------------------
'Project Header' .
-*------------------------------------------------------------*/
#ifndef _MAIN_H
#define _MAIN_H

// header file for 8051
#include <reg52.h>

// Oscillator / resonator frequency (in Hz) e.g. (11059200UL)
#define OSC_FREQ (12000000UL)
// Number of oscillations per instruction (12, etc)
// 12 – Original 8051 / 8052 and numerous modern versions
// 6 – Various Infineon and Philips devices, etc.
// 4 – Dallas 320, 520 etc.
// 1 – Dallas 420, etc.
#define OSC_PER_INST (12)

// Typedefs 
typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;

// Interrupts
#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_Timer_2_Overflow 5

#define DEBOUNCE_PERIOD 100
#define IS_ANODE (bit) 1
#define seg7_number 2

void run();

// Main states
#define INIT 0
#define PROGRAM_SELECT 1
#define RUN_PROGRAM 2
 

#endif
/*------------------------------------------------------------*-
---- END OF FILE --------------------------------------------
-*------------------------------------------------------------*/