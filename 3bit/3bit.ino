/*
 * 3 bit binary counter
 */

int cntr=0,v1,v2,a,b,c,d;
int buttonState=LOW;
int switchPin=2;

void setup() 
{
 pinMode(switchPin,INPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 digitalWrite(11,LOW);
 digitalWrite(12,LOW);
 digitalWrite(13,LOW);
}

void loop()
{
  v1 = digitalRead(switchPin);      
  delay(10);                        
  v2 = digitalRead(switchPin);     
  if (v1 == v2) 
  {                
    if (v1 != buttonState && v1==HIGH) 
    {          
          d=cntr;
          c=cntr%2;
          cntr=cntr/2;
          b=cntr%2;
          cntr=cntr/2;
          a=cntr%2;
          cntr=cntr/2;

          digitalWrite(11,a);
          digitalWrite(12,b);
          digitalWrite(13,c);
          
          cntr=d+1;
          if(cntr==8)cntr=0; 
    }
    buttonState = v1;
  }
}
