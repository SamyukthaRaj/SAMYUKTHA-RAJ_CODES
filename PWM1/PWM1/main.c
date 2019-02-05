/*
 * PWM1.c
 *
 * Created: 07-11-2018 19:26:33
 * Author : Samyuktha Raj
 */ 



#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	
	DDRB = 0b00001000;
	TCCR0 |=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	OCR0 = 0;
	while(1)
	{    OCR0++;
		_delay_ms(50);
		
	}
}
