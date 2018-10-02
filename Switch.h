/*------------------------------------------------------------*-
seven_segment.H (v1.00)
-------------------------------------------------------------
– See seven_segment.C for details.
-*------------------------------------------------------------*/
#ifndef _SWITCH_H
#define _SWITCH_H

// ------ Public function prototype ---------------------------

#define SWITCH_NOT_PRESSED (bit) 1
#define SWITCH_PRESSED (bit) 0	

bit SWITCH_state(int switch_number, tByte debounce_period);
bit SWITCH_current_state(int switch_number);

#endif

//-------------- END OF FILE --------------------------

