/*
 * SEVEN_SEG.c
 *
 * Created: 8/18/2022 8:32:20 PM
 *  Author: Zakaria yahia 
 */ 
#include "SEVEN_SEG.h"

void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;
}
void SEVEN_SEG_write_First_Num(uint8_t data){ 
	uint8_t x = data % 10; // 
	
	EN2(1);
	EN1(0);
	A(READBIT(x,0));
	B(READBIT(x,1));
	C(READBIT(x,2));
	D(READBIT(x,3));
	
	
}

void SEVEN_SEG_write_Second_Num(uint8_t data){
	uint8_t x = data / 10; //
	
	EN2(0);
	EN1(1);
	A(READBIT(x,0));
	B(READBIT(x,1));
	C(READBIT(x,2));
	D(READBIT(x,3));
	
	
}

