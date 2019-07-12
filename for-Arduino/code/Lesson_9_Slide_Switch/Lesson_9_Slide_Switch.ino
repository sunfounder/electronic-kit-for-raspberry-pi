//Controlling Led By slide switch
//Turns on and off a LED ,when slide the switch
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
/**********************************/
const int switchPin = 12; //the switch connect to pin 12
const int ledPin = 6;//the led connect to pin 6
/**********************************/
int switchState = 0;         // variable for reading the pushbutton status

void setup()
{
  pinMode(switchPin, INPUT); //initialize thebuttonPin as input
  pinMode(ledPin, OUTPUT); //initialize the led pin as output
}
/**********************************/
void loop()
{
  //read the state of the switch value
  switchState = digitalRead(switchPin);
  if (switchState == HIGH ) //if it is,the state is HIGH
  {
    digitalWrite(ledPin, HIGH); //turn the led on
  }
  else
  {
    digitalWrite(ledPin, LOW); //turn the led off
  }
}
/************************************/
