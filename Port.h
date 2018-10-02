/*-------------------------------------------------

	Port.h (v1.00)
	
	-------------------------------------------------
	
	'Port Header' for project 7SEG_COUNTER
	
------------------------------------------------*/

#ifndef _PORT_H
#define _PORT_H

//-------- 7SEG.C ---------------------------

//  port for the 7 segment 8 LEDs
#define port_7_segment P1
sbit seg7_enable_1 = P2^0;
sbit seg7_enable_2 = P2^1;

// switch
sbit up_pin = P2^2;
sbit down_pin = P2^3;
sbit start_pin = P2^4;
sbit door_closed_pin = P2^5;


// sensors
sbit water_level_full = P2^6;
sbit water_level_empty = P2^7;
sbit temprature_sensor = P3^0;

// actuators
sbit motor_fast = P0^5;
sbit motor_slow = P0^6;
sbit motor_reverse = P0^7;
sbit water_drain = P0^4;

sbit door_lock = P3^1;
sbit heater = P3^2;
sbit water_valve = P3^3;
sbit detergent_valve = P3^4;

sbit error = P3^5;
sbit finished = P3^6;


#endif
/*------------------------------------------------------*-
-*--------------- END OF FILE --------------------------*/