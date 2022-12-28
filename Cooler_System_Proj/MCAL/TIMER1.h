/*
 * PWM.c
 *
 * Created: 21/08/2022 11:55:21 ã
 * Author : Zakaria Yahia 
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_macros.h"

void TIMER1_PWM_oc1A_init(void);
void TIMER1_PWM_oc1A_duty(uint8_t duty );
void TIMER1_PWM_oc1A_stop(void);


#endif /* TIMER1_H_ */