//Turn on a led by 4n35
//turn on the LED for half a second,then off for half a second,repeatedly
//support@sunfounder.com
//www.sunfounder.com
//2015.5.7

int OptoPin=7; //attach the input of the 4n35 to pin 7

void setup()
{
  pinMode(OptoPin, OUTPUT);  //set it as OUTPUT
  
}
void loop()
{
  digitalWrite(OptoPin, LOW);  //set the OptoPin as LOW level,then the led connected on the output of 4n35 will be light
  delay(500);  //delay 500ms
  digitalWrite(OptoPin, HIGH);  //turn off the led
  delay(500);  //delay 500ms
}
