int led=9;
int brightness=0;
int fadeamount=5;

void setup() 
{
 pinMode(led,OUTPUT);
 
}

void loop() {
 analogWrite(led,brightness);
 brightness=brightness+fadeamount;
 if(brightness==0||brightness==255)
 { fadeamount=-fadeamount; }
 delay(30);
 

}
