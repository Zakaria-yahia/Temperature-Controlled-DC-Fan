/*
 * ADC.c
 *
 * Created: 22/08/2022 01:57:47 Õ
 * Author : Zakaria yahia
 */
#include "ADC.h"

void ADC_int(void){
	SETBIT(ADMUX,REFS0); // AVCC will be the ref.
	SETBIT(ADCSRA,ADEN); // enable ADC
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);
	
}

uint16_t ADC_read(void){
	
	SETBIT(ADCSRA,ADSC); // start single conversion
	while(READBIT(ADCSRA,ADSC) == 1); // conversion not completed
	
	return  ADC;
}

