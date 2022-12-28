/*
 * Cooler_System_Proj.c
 *
 * Created: 07/09/2022 07:20:07 م
 * Author : Zakaraia yahia 
 */ 

#include "ADC.h"
#include "TIMER1.h"
#include "SEVEN_SEG.h"
#include "LCD.h"
#include "TIMER0.h"

#define Min_Temp 35
#define Max_Temp 50
#define Min_Duty 50
#define Max_Duty 100
#define First_line 0x80
#define Second_line 0xc0
#define Buzzer_Led_pin 6
#define OC_Value  155            // for interrupt every 10ms

uint8_t Temp=0;

uint8_t Map(uint8_t temp);
static void ctc_isr(void);

int main(void)
{
	SEVEN_SEG_init();
	timer0_ctc_isr = ctc_isr;
	TIMER0_CTC_init(OC_Value);                  
	LCD_init();
    ADC_int();
	
    while (1) 
    {
		Temp= ((ADC_read()*100) / 206.0 )+ 0.5;
		LCD_write_command(First_line);
		LCD_write_string(" Temp = ");
		LCD_write_num( Temp);
		
		if (Temp >=35)
		{
			SETBIT(PORTC,Buzzer_Led_pin);
			TIMER1_PWM_oc1A_init();
			TIMER1_PWM_oc1A_duty(Map(Temp));
			LCD_write_command(Second_line);
			LCD_write_string(" Duty = ");
			LCD_write_num( Map(Temp));
			LCD_write_string(" %");
		}else
		{
			CLRBIT(PORTC,Buzzer_Led_pin);
			TIMER1_PWM_oc1A_stop();
			LCD_write_command(Second_line);
			LCD_write_string(" Duty = ");
			LCD_write_num(0);
			LCD_write_string("  %");
		}
    }
}

uint8_t Map(uint8_t temp)
{
	uint8_t Min_Current_Range = Min_Temp;
	uint8_t Max_Current_Range = Max_Temp;
	uint8_t Min_Target_Range = Min_Duty;
	uint8_t Max_Target_Range = Max_Duty;
	uint8_t Result  = (temp - Min_Current_Range) * (Max_Target_Range - Min_Target_Range) / (Max_Current_Range - Min_Current_Range) + Min_Target_Range;
	return Result;
} 


static void ctc_isr(void){
	static uint8_t count = 0;
	
	if(count == 0 ){
		
		SEVEN_SEG_write_First_Num(Temp);
		count ++;
	}else
	{
		SEVEN_SEG_write_Second_Num(Temp);
		count=0;
	}

	
}