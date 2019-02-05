/*
 * ledpush2.c
 *
 * Created: 31-10-2018 19:17:47
 * Author : Samyuktha Raj
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB |= 1<< PINB1;
	PORTB^=1<<PINB1;
	DDRD &=~(1<<PIND7);
	PORTD |=1<<PIND7;
	int Pressed=0;
	int Pressed_Confidence_level=0;
	int Released_Confidence_level=0;
	
    /* Replace with your application code */
    while (1) 
    
	{
		if(bit_is_clear(PIND,7))
		{
			Pressed_Confidence_level++;
			if(Pressed_Confidence_level>500)
			{
				if(Pressed==0)
				{
					PORTB^=1<<PINB1;
					PORTD^=1<<PINB7;
					Pressed =1;
				}
			}
		}
		else
		{
			Released_Confidence_level++;
			if(Released_Confidence_level>500)
			{
				Pressed=0;
			}
		}
		
    }
}

