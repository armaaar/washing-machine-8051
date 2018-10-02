/*------------------------------------------------------------*-
seven_segment.C (v1.00)
-------------------------------------------------------------
Simple library for displaying digits on 7 segment.

-*------------------------------------------------------------*/
#include "Main.h"
#include "Port.h"
#include "Switch.h"
#include "Delay.h"


bit SWITCH_state(int switch_number, tByte debounce_period)
{
	
	bit Return_value = SWITCH_NOT_PRESSED;
	
	if (SWITCH_current_state(switch_number) == 0)
	{
		// Switch is pressed
		// Debounce – just wait...
		DELAY_loop_ms(debounce_period);
		// Check switch again
		if (SWITCH_current_state(switch_number) == 0)
		{
			Return_value = SWITCH_PRESSED;
		}
	}
	// Now return switch value
	return Return_value;
}

bit SWITCH_current_state(int switch_number)
{
	if(switch_number == 1)
	{
		up_pin = 1;
		return	up_pin;	
	} else if(switch_number == 2)
	{
		down_pin = 1;
		return	down_pin;	
	} else if(switch_number == 3)
	{
		start_pin = 1;
		return	start_pin;	
	} else {
		return 0;
	}

}

//------------------- END OF FILE --------------------------------