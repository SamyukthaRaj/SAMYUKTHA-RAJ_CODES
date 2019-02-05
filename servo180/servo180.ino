
int servo0=500;
int servo180=2600;
int inc=20;
int pos=servo0;
int servoPin=8;




void setup()
{
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servoPin,OUTPUT);
  

}

void loop() 
{
  // put your main code here, to run repeatedly:
  int i;
  pos+=inc;
  if(pos>servo180)
  {
    pos=servo180;
    inc*=-1;
    delay(500);
  }
  else if(pos<servo0)
  {
    pos=servo0;
    inc*=-1;
    delay(500);
  }
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pos);
  digitalWrite(servoPin,LOW);
  delay(20);

}
