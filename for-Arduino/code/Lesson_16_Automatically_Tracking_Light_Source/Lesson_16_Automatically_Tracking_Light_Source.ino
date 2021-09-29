/********************************************************************
 * name : Automatically Tracking Light Source
 * function :  if you use a flashlight to shine the photoresistor,
 * you will see the servo motor and the photoresistor rotate, 
 * and finally stop at the direction of light source.
 ***********************************************************************/
//Email: support@sunfounder.com
//Website: www.sunfounder.com

#include <Servo.h>
const int photocellPin = A0;  //The photoresistor is connected to A0
/************************************************/
Servo myservo;//create servo object to control a servo

int outputValue = 0;  //Save the value read from A0
int angle[] = {0,10, 20, 30, 40, 50, 60,70, 80, 90, 100,110,120,130,140,150,160,170,180};  //Define the angle of servo
int maxVal = 0;  //Record the maximum value of A0
int maxPos = 0;  //Record the angle of the servo when the read the maximum number of photoresistor.
/*************************************************/
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);//attachs the servo on pin 9 to servo object
}
/*************************************************/
void loop()
{
  for(int i = 0; i < 19; i ++)
  {
    myservo.write(angle[i]);//write the angle to servo
    outputValue = analogRead(photocellPin);//read the value of A0
    Serial.println(outputValue);//print it
    if(outputValue > maxVal)//if the current value of A0 is greater than previous
    {
      maxVal = outputValue;//write down the value
      maxPos =i;//write down the angle
    }
    delay(200); //delay 200ms
  }
  myservo.write(angle[ maxPos]);//write the angle to servo which A0 has greatest value 
 delay(1000);  //delay 1s
}
