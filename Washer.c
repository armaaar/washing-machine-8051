#include "Main.h"
#include "Port.h"
#include "Washer.h"

// PROGRAMS AVAILABLE
tByte program_dry[] = {DRY, REPEAT, FINISH};

tByte program_wash[] = {ADD_DETERGENT, ADD_WATER, HEAT, SPIN_MOTOR, TOGGLE_MOTOR, DRAIN_WATER, DRY, REPEAT, FINISH};

tByte program_light_wash[] = {ADD_DETERGENT, ADD_WATER, HEAT, TOGGLE_MOTOR, DRAIN_WATER, DRY, REPEAT, FINISH};

tByte program_very_light_wash[] = {ADD_DETERGENT, ADD_WATER, HEAT, SPIN_MOTOR, DRAIN_WATER, DRY, REPEAT, FINISH};


bit feature_heat;
bit feature_dry;
bit feature_double;

void washer_off_all() {
	motor_fast = OFF;
	motor_slow = OFF;
	motor_reverse = OFF;
	water_drain = OFF;
	
	door_lock = OFF;
	heater = OFF;
	water_valve = OFF;
	detergent_valve = OFF;

	error = OFF;
}

void washer_program_features(tByte program_number, tByte *features)
{  
	if(program_number == 6
	|| program_number == 14
	|| program_number == 18) { // -- COLD WET -- //
		features[0] = FALSE;  	// heat
		features[1] = FALSE;	// dry
		features[2] = FALSE; 	// double
 
	}  else if(program_number == 5
	|| program_number == 13
	|| program_number == 17) { // -- WET -- //
		features[0] = TRUE;  	// heat
		features[1] = FALSE;	 // dry
		features[2] = FALSE; 	// double
	} else if(program_number == 1
	|| program_number == 4
	|| program_number == 12
	|| program_number == 16) { // -- COLD -- //
		features[0] = FALSE;  	// heat
		features[1] = TRUE;	 	// dry
		features[2] = FALSE; 	// double

	} else if(program_number == 3
	|| program_number == 11
	|| program_number == 15) { // -- NORMAL -- //
		features[0] = TRUE;  	// heat
		features[1] = TRUE;	 	// dry
		features[2] = FALSE; 	// double

	} else if(program_number == 10) { // -- HEAVY COLD WET -- //
		features[0] = FALSE;  	// heat
		features[1] = FALSE;	// dry
		features[2] = TRUE; 	// double
 
	}  else if(program_number == 9) { // -- HEAVY WET -- //
		features[0] = TRUE;  	// heat
		features[1] = FALSE;	// dry
		features[2] = TRUE; 	// double

	} else if(program_number == 2
	|| program_number == 8) { // -- HEAVY COLD -- //
		features[0] = FALSE;  	// heat
		features[1] = TRUE;	 	// dry
		features[2] = TRUE; 	// double

	} else if(program_number == 7) { // -- HEAVY -- //
		features[0] = TRUE;  	// heat
		features[1] = TRUE;	 	// dry
		features[2] = TRUE; 	// double

	}
}
tByte washer_get_program_step(tByte program_number, int step_number) {
	if(program_number == 1
	|| program_number == 2) {
		return program_dry[step_number];
 
	} else if(program_number == 3
	|| program_number == 4
	|| program_number == 5
	|| program_number == 6
	|| program_number == 7
	|| program_number == 8
	|| program_number == 9
	|| program_number == 10) {
		return program_wash[step_number];
 
	} else if(program_number == 11
	|| program_number == 12
	|| program_number == 13
	|| program_number == 14) {
		return program_light_wash[step_number];

	} else if(program_number == 15
	|| program_number == 16
	|| program_number == 17
	|| program_number == 18) {
		return program_very_light_wash[step_number];

	}
}



/*------------------------------------------------------------*-
---- END OF FILE --------------------------------------------
-*------------------------------------------------------------*/