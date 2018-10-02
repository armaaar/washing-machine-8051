/*------------------------------------------------------------*-
seven_segment.C (v1.00)
-------------------------------------------------------------
Simple library for displaying digits on 7 segment.

-*------------------------------------------------------------*/
#include "Main.h"
#include "Port.h"
#include "Seven_segment.h"
#include "Delay.h"

// Values to be sent to the port depending on the selected index(DIGIT)
static const tByte bcd_to_7_anode[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
static const tByte bcd_to_7_cathode[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

// Display digits on the 7 segment
void seg7_display_1_digit(tByte digit, bit is_anode)
{  	
	if(is_anode == 1)
	{
	 	port_7_segment = bcd_to_7_anode[digit];
	} else {
		port_7_segment = bcd_to_7_cathode[digit];
	}
	DELAY_loop_ns(2);
}
void seg7_enable(int segment_number, bit is_anode, bit disable_rest)
{
 	if(segment_number == 1)
	{
		if(is_anode)
		{
		  	seg7_enable_1 = 1;
			if(disable_rest)
			{
			   seg7_enable_2 = 0;
			   
			}
		} else {
			seg7_enable_1 = 0;
			if(disable_rest)
			{
			   seg7_enable_2 = 1;
			}
		} 
	} else if(segment_number == 2)
	{
		if(is_anode)
		{
		  	seg7_enable_2 = 1;
			if(disable_rest)
			{
			   seg7_enable_1 = 0;
			}
		} else {
			seg7_enable_2 = 0;
			if(disable_rest)
			{
			   seg7_enable_1 = 1;
			}
		} 
	}
}
void seg7_display_digits(tByte digits[seg7_number], bit is_anode)
{
	int i;
	for(i=0; i<seg7_number; i++)
    {
   		seg7_enable(i+1, is_anode, 1);
		seg7_display_1_digit(digits[i], is_anode);
		DELAY_loop_ms(50);	
    }
}

int array_to_value(tByte *container_array, int array_size)
{
	tByte result=0;
	int i, j,  multiplier=1;
	for(i=0; i<array_size; i++)
	{
		for(j=0; j<i;j++)
		{
		 	multiplier *= 10;
		}
		result += container_array[i] *  multiplier;
		multiplier = 1;	
	}
	return result;
}
//------------------- END OF FILE --------------------------------