void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if(c%1==0)
ledOn1=!ledOn1;
if(c%2==0)
leadOn2=!ledOn2;
digitalWrite(ledPin1,ledOn1);
digitalWrite(ledPin2,ledOn2);
}
