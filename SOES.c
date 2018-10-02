#include "Main.h"
#include "SOES.h"

tByte TL0_Reload = 0;
tByte TH0_Reload = 0;

extern void SOES_voidInitialize(){
	TMOD |= 0x01;
	TL0 = 0xB0;
	TH0 = 0x3C;
	EA = 1;		//enable global interrupts
	ET0 = 1;	//enable timer0 interrupt_
	TF0 = 0;	//clear timer0 ov flag
	TR0 = 1;	//start timer0
}

extern void SOES_voidGoToSleep(void){
	PCON |= 0x01;
}

void SOES_ISR() interrupt INTERRUPT_Timer_0_Overflow {
	TL0 = 0xB0;
	TH0 = 0x3C;
	//TF0 = 0;
	//TR0 = 1;
	run();
}