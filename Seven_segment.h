/*------------------------------------------------------------*-
seven_segment.H (v1.00)
-------------------------------------------------------------
– See seven_segment.C for details.
-*------------------------------------------------------------*/
#ifndef _SEVEN_SEGMENT_H
#define _SEVEN_SEGMENT_H

// ------ Public function prototype ---------------------------

void seg7_display_1_digit(tByte digit, bit is_anode);
void seg7_display_digits(tByte digits[seg7_number], bit is_anode);
void seg7_enable(int segment_number, bit is_anode, bit disable_rest);
int array_to_value(tByte *container_array, int array_size);
#endif

//-------------- END OF FILE --------------------------

