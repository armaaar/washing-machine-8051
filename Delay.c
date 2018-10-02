/*------------------------------------------------------------*-
Delay.C (v1.00)
-------------------------------------------------------------
Create a simple software delay using a loop.
-*------------------------------------------------------------*/
#include "Main.h"
#include "Port.h"
#include "Delay.h"

void DELAY_T0_ms(tWord N)
{
	tWord ms;
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01; // Set required T0 bits (T1 left unchanged)
	ET0 = 0; // No interupts

	// Delay value is *approximately* 1 ms per loop
	for (ms = 0; ms < N; ms++)	
	{
		TH0 = PRELOAD01H;
		TL0 = PRELOAD01L;
		TF0 = 0; // clear overflow flag
		TR0 = 1; // start timer 0
		while (TF0 == 0); // Loop until Timer 0 overflows (TF0 == 1)
		TR0 = 0; // Stop Timer 0
	}
}

void DELAY_T1_ms(tWord N)
{
	tWord ms;
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0x0F; // Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x10; // Set required T0 bits (T1 left unchanged)
	ET1 = 0; // No interupts

	// Delay value is *approximately* 1 ms per loop
	for (ms = 0; ms < N; ms++)	
	{
		TH1 = PRELOAD01H;
		TL1 = PRELOAD01L;
		TF1 = 0; // clear overflow flag
		TR1 = 1; // start timer 0
		while (TF1 == 0); // Loop until Timer 0 overflows (TF0 == 1)
		TR1 = 0; // Stop Timer 0
	}
}

void DELAY_loop_ms(tWord ms)
{
 tWord counter1;
 tByte counter2;
 for(counter1=0;counter1<ms;counter1++)
 for( counter2 =0;counter2<250;counter2++);
}

void DELAY_loop_ns(tWord ns)
{
 int counter;
 for(counter=0;counter<ns;counter++);
}

/*------------------------------------------------------------*-
---- END OF FILE --------------------------------------------
-*------------------------------------------------------------*/