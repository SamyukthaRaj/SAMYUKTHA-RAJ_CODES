int led=9;
int brightness=0;
int fadeamount=5;
int a=0;
int b=1;

void setup() 
{
 pinMode(led,OUTPUT);
 
}

void loop() {
  
 analogWrite(led,a);
while(brightness<255)
{
  brightness=a+b;
  a=b;
  b=brightness;
  
  analogWrite(led,brightness);
  
  
 }

 
 delay(30);
 

}
