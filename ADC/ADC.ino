int main(void)
{
  TCCR0 |= 1<<WGM00 | 1<<WGM01 | 1<<COM01 | 1<<CS00;
  DDRB |= 1<<PINB3;
  ADMUX |= 1<<ADLAR;
  ADCSRA |= 1<<ADIE;
  ADMUX |= 1<<REFS0;
  ADCSRA |= 1<<ADEN;
  sei();
  ADCSRA |= 1<<ADSC;
  
  while (1)
  {
  }
}

ISR(ADC_vect)
{
  uint8_t res= ADCH;
  
  OCR0 = res;
  ADCSRA |= 1<<ADSC;
