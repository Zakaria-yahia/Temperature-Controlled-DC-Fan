/*
 * SEVEN_SEG.c
 *
 * Created: 8/18/2022 8:32:20 PM
 *  Author: Zakaria yahia 
 */ 



#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRC |= 0xff;

void SEVEN_SEG_init(void);
void SEVEN_SEG_write_First_Num(uint8_t data);
void SEVEN_SEG_write_Second_Num(uint8_t data);

#define EN1(x) if(x == 1) SETBIT(PORTC,4); else CLRBIT(PORTC,4);
#define EN2(x) if(x == 1) SETBIT(PORTC,5); else CLRBIT(PORTC,5);
#define A(x)  if(x == 1) SETBIT(PORTC,0); else CLRBIT(PORTC,0);
#define B(x)  if(x == 1) SETBIT(PORTC,1); else CLRBIT(PORTC,1);
#define C(x)  if(x == 1) SETBIT(PORTC,2); else CLRBIT(PORTC,2);
#define D(x)  if(x == 1) SETBIT(PORTC,3); else CLRBIT(PORTC,3);



#endif /* SEVEN_SEG_H_ */