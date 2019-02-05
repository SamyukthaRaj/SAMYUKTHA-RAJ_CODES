int echopin1=2;
  int trig1=4;
  int echopin2=3;
  int trig2=5;
  int t1,t2;
  int led1=11,led2=10;
  int c1=0,c2=0,c3=0,brightness=0;
   
  
  int distance1,distance2,dmin;
  int cntr=0;
  
  void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(echopin1,INPUT);
  pinMode(trig1,OUTPUT);
   pinMode(echopin2,INPUT);
  pinMode(trig2,OUTPUT);
 

}
void loop() 
{
digitalWrite(trig1,HIGH);
  delayMicroseconds(50);
  digitalWrite(trig1,LOW);
 t1=pulseIn(echopin1,HIGH);
 distance1=(t1*0.0340)/2;
 Serial.println(distance1);
 digitalWrite(trig2,HIGH);
  delayMicroseconds(50);
  digitalWrite(trig2,LOW);
 t2=pulseIn(echopin2,HIGH);
 distance2=(t2*0.0340)/2;
 Serial.println(distance2);

 if(distance1>distance2)
{
  dmin=distance2;
  c1++;
}
 else if(distance2>distance1)
 {dmin=distance1;
 c2++;
 }
 else if(distance1==distance2)
 {
  c3++;
 }

 if(c1==1&&c2==0)
 {
  if(dmin>=50)
 digitalWrite(led1,HIGH);
 else
 {
  cntr=map(dmin,5,50,0,255);
  brightness=brightness+cntr;
  analogWrite(led1,brightness);
  
 }
 }
 else if(c2==1&&c1==0)
 {
   if(dmin>=50)
 digitalWrite(led2,HIGH);
 else
 {
  cntr=map(dmin,5,50,0,255);
  brightness=brightness+cntr;
  analogWrite(led2,brightness);
  
 }
 }
 else if(c3==1)
 {
  if(distance1>=50)
  {
    digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
    
  }
  else
  {
   cntr=map(distance1,5,50,0,255);
  brightness=brightness+cntr;
  analogWrite(led1,brightness);
   cntr=map(distance2,5,50,0,255);
  brightness=brightness+cntr;
  analogWrite(led2,brightness);
  }
 }
 }
