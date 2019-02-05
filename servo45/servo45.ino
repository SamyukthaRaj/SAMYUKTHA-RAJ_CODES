
int servo0=600;
int servo45=975;
int inc=5;
int pos=servo0;
int servoPin=9;




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
  if(pos>servo45)
  {
    pos=servo45;
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
