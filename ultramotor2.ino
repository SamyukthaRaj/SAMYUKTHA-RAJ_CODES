
int echopin1=5;
  int trig1=4;
  int echopin2=3;
  int trig2=2;
  int t1,t2,t3,t4,t1_,t2_;
  
  int distancel,distancer;
  int mlf=11;
  int mrf=9;
  int mlb=10;
  int mrb=8;
  void tr();
  void tl();
  void bk();
  void frd();
  
  void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(echopin1,INPUT);
  pinMode(trig1,OUTPUT);
   pinMode(echopin2,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(mlf,OUTPUT);
  pinMode(mrf,OUTPUT);
  pinMode(mlb,OUTPUT);
  pinMode(mrb,OUTPUT);
 

}
void loop() 
{
digitalWrite(trig1,HIGH);
  digitalWrite(trig1,LOW);
   while(digitalRead(echopin1)==LOW);
  t1=micros();
  while(digitalRead(echopin1)==HIGH);
  t2=micros();
  t1_=t2-t1;

distancel=(t1_*0.0340)/2;
 Serial.println(distancel);
 digitalWrite(trig2,HIGH);
  digitalWrite(trig2,LOW);
 while(digitalRead(echopin2)==LOW);
  t3=micros();
  while(digitalRead(echopin2)==HIGH);
  t4=micros();
  t2_=t4-t3;
  distancer=(t2_*0.0340)/2;

 Serial.println(distancer);
 if(distancel>15&&distancer>15)
 {
  frd();
 }
  if(distancel<=15&&distancer>15)
 {
  tr();
 }
 if(distancel<15&& distancer<15)
 {
  bk();
  
 }
  if(distancer<=15&&distancel>15)
 {
  tl();
 }
 

}
 void bk()
{
  digitalWrite(mlf,LOW);
  digitalWrite(mrf,LOW);
  digitalWrite(mlb,HIGH);
  digitalWrite(mrb,HIGH);
  
}
 
 void frd()
{
  digitalWrite(mlf,HIGH);
  digitalWrite(mrf,HIGH);
  digitalWrite(mlb,LOW);
  digitalWrite(mrb,LOW);
  
}
void tl()
{
  digitalWrite(mrf,LOW);
  digitalWrite(mrb,HIGH);
  digitalWrite(mlf,HIGH);
  digitalWrite(mlb,LOW);
  
}
void tr()
{
  digitalWrite(mlb,HIGH);
  digitalWrite(mlf,LOW);
  digitalWrite(mrb,LOW);
  digitalWrite(mrf,HIGH);
  
}
 
  
