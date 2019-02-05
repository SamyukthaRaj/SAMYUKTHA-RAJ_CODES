/*
 * pusbuttonnew.c
 *
 * Created: 05-11-2018 19:15:03
 * Author : Samyuktha Raj
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB |=1<<PINB1;
	PORTB^=1<<PINB1;
	DDRD |=1<<PIND7;
	DDRD &=~(1<<PIND7);
	PORTD|=1<<PIND7;
	int Pressed=0;
	int cr=0;
	int cp=0;
	
    /* Replace with your application code */
    while (1) 
    {
		if((((1<<PIND7)&PIND7)>>PIND7)==0)
		{
			cp++;
			if(cp>500)
			{
				
			
			if(Pressed==0)
			{ 
				Pressed=1;
			    PORTB^=1<<PINB1;
             }
			}
		}
	else 
	{
		cr++;
		if(cr>500)
		Pressed=0;
	}
}
}
