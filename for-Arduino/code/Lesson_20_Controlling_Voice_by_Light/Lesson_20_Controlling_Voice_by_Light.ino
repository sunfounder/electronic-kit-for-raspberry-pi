/*************************
 * name:Controlling Buzzer by Photoresistor
 * function: if you place the photoresistor in a dark environment, the buzzer will beep sharply; if you shine a flashlight on the photoresistor, the buzzer beeping will slow down.
 ****************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com

/*******************************/
const int photocellPin = A0;  //photocell attach to
int sensorValue = 0;        // value read from the sensor
const int buzzerPin = 9;  //buzzer attach to

void setup()
{
  pinMode(buzzerPin, OUTPUT);  //initialize buzzer as an output
}
void loop()
{
  sensorValue = analogRead(photocellPin); //read the value of A0
  digitalWrite(buzzerPin, HIGH); //
  delay(sensorValue);  //wait for a while,and the delay time depend on the sensorValue
  digitalWrite(buzzerPin, LOW);
  delay(sensorValue);
}

