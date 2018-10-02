#include "Main.h"
#include "Seven_segment.h"
#include "Port.h"
#include "Switch.h"
#include "Delay.h"
#include "SOES.h"
#include "Washer.h"

#define ONE_SEC 2
tByte program_number[seg7_number] = {0};
int time_ticks = 0;
int time_ticks_internal = 0;
tByte program_selected = 0;
int program_step = 0;
int program_state = 0;
int curret_state = INIT;
	
tByte features[3] = {FALSE};

void program_inc(tByte *displayed_array, bit is_dec);


void main()
{
	seg7_enable(1,IS_ANODE,1);
	finished = OFF;
	SOES_voidInitialize	();
	SOES_voidGoToSleep();
	
}

void program_inc(tByte *displayed_array, bit is_dec)
{
	if(is_dec)
	{
		if(displayed_array[0] > 0)
		{
		 	displayed_array[0]--;
		}else if(displayed_array[1] >0)
		{
			displayed_array[0] = 9;
		 	displayed_array[1]--;	
		}
	} else {
	 	if(displayed_array[0] < 9 && displayed_array[1] == 0 || displayed_array[0] < 8 && displayed_array[1] == 1)
		{
		 	displayed_array[0]++;
		}else if(displayed_array[1] == 0)
		{
			displayed_array[0] = 0;
		 	displayed_array[1] = 1;	
		}
	}
}

void run()
{
	seg7_display_digits(program_number,IS_ANODE);
	switch (curret_state)
	{
		case INIT:
		{
			washer_off_all();
			program_step=0;
			time_ticks = 0;
			time_ticks_internal = 0;
			program_selected = 0; 	

			curret_state = PROGRAM_SELECT;
			break;
		}
		case PROGRAM_SELECT:
		{
		  	// switch Up is pressed
			if(SWITCH_state(1, DEBOUNCE_PERIOD) == SWITCH_PRESSED)
			{
				program_inc(program_number, 0);	
			}	
			// switch Down is pressed
			if(SWITCH_state(2, DEBOUNCE_PERIOD) == SWITCH_PRESSED)
			{
				program_inc(program_number, 1);	
			}
			// switch Start is pressed
			if(SWITCH_state(3, DEBOUNCE_PERIOD) == SWITCH_PRESSED)
			{
				if(door_closed_pin ==  SWITCH_PRESSED)
				{
				 	program_selected = array_to_value(program_number, seg7_number);
					if(program_selected != 0)
					{
						door_lock = ON;
					 	curret_state = RUN_PROGRAM;
						washer_program_features(program_selected, features); 
					}
				}	
			}
			break;
		}
		case RUN_PROGRAM:
		{
			if(door_closed_pin != SWITCH_PRESSED ||  SWITCH_state(3, DEBOUNCE_PERIOD) != SWITCH_PRESSED)
			{
				washer_off_all();
				error = ON;
				break;	
			} else {
			   error = OFF;
			   finished = OFF;
			   door_lock = ON;
			}

			program_state = washer_get_program_step(program_selected, program_step);
			switch (program_state)
			{
			 	case FINISH:
				{
					washer_off_all();
					finished = ON;
					program_number[0] = 0;
					program_number[1] = 0;
					curret_state = INIT;
					break;
				}
				case ADD_DETERGENT:
				{
					detergent_valve = ON;
					if (++time_ticks >= (5*ONE_SEC)){
						detergent_valve = OFF;
						time_ticks = 0;
						program_step++;
					}
					break;
				}
				case ADD_WATER:
				{
					water_valve = ON;
					if (water_level_full == SENSOR_ON){
						water_valve = OFF;
						program_step++;
					}
					break;
				}
				case HEAT:
				{
					if(features[0] == FALSE)
					{
					 	program_step++;
						break;	
					}
					heater = ON;
					if (temprature_sensor == SENSOR_ON){
						heater = OFF;
						program_step++;
					}
					break;
				}
				case SPIN_MOTOR:
				{
					motor_slow = ON;
					if (++time_ticks >= (5*ONE_SEC)){
						motor_slow = OFF;
						time_ticks = 0;
						program_step++;
					}
					break;
				}
				case TOGGLE_MOTOR:
				{
					if(time_ticks_internal < (2*ONE_SEC)) {
					 	// spin forward
						motor_reverse = OFF;
						DELAY_loop_ms(10);
						motor_slow = ON;

						time_ticks_internal++;
					} else if(time_ticks_internal < (4*ONE_SEC)) {
					 	// spin backwards
						motor_slow = OFF;
						DELAY_loop_ms(10);
						motor_reverse = ON;

						time_ticks_internal++;
					} else {
					  time_ticks_internal = 0;
					  motor_reverse = OFF;
					  motor_slow = ON;
					}

					if (++time_ticks >= (8*ONE_SEC)){
						motor_reverse = OFF;
						motor_slow = OFF;
						time_ticks = 0;
						program_step++;
					}
					break;
				}
				case DRY:
				{
					if(features[1] == FALSE)
					{
					 	program_step++;
						break;	
					}
					if (time_ticks_internal < (5*ONE_SEC)){
						motor_fast = ON;
						time_ticks_internal++;
						break;
					} else {
						motor_fast = OFF;
					}
					// yes there is no break here 3:)
					// so that the program start draining right after finishing
				}
				case DRAIN_WATER:
				{
					water_drain = ON;
					if (water_level_empty == SENSOR_ON){
						water_drain = OFF;
						time_ticks_internal=0;
						program_step++;
					}
					break;
				} 
				case REPEAT:
				{
					// if feature_double == false, we finished repeating
					if(features[2] == FALSE)
					{	
					  	program_step++;
					} else {
					  	features[2] = FALSE;	
					  	program_step=0;
					}
					break;	
				} 
			}
			break;
		}
	}
}