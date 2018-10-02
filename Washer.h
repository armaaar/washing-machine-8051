#ifndef _WASHER_H
#define _WASHER_H
// ------ Public function prototype ---------------------------
#define ON (bit) 0
#define OFF (bit) 1

#define FALSE 0
#define TRUE 1

#define SENSOR_OFF (bit) 1
#define SENSOR_ON (bit) 0

void washer_off_all();
void washer_program_features(tByte program_number, tByte *features);
tByte washer_get_program_step(tByte program_number, int step_number);

// PROGRAM STATES
#define FINISH 0
#define ADD_DETERGENT 1
#define ADD_WATER 2
#define HEAT 3
#define SPIN_MOTOR 4
#define TOGGLE_MOTOR 5
#define DRY 6
#define DRAIN_WATER 7
#define REPEAT 8

#endif
/*------------------------------------------------------------*-
---- END OF FILE --------------------------------------------
-*------------------------------------------------------------*/