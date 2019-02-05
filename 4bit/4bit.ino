/*
 * 4 bit binary counter
 */

int ledState=0;
int buttonState=LOW;
int count=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(8,OUTPUT); digitalWrite(8,LOW);
  pinMode(9,OUTPUT); digitalWrite(9,LOW);
  pinMode(10,OUTPUT); digitalWrite(10,LOW);
  pinMode(11,OUTPUT); digitalWrite(11,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int v1=digitalRead(2);
  delay(10);
  int v2=digitalRead(2);
  if(v1==v2)
  {
    if(v1!=buttonState && v1==HIGH)
    {
      int temp=count;
      for(int i=0;i<4;i++)
      {
        digitalWrite(8+i,(count%2));
        count=count/2;
      }
      count=temp++;
      if(count==16) count=0;
    }
    buttonState=v1;
  }
}
