//NE555 Timer
//After burning the program, open the serial monitor,you can see that if you rotate the potentiometer, the length of the pulse (in microsecond) displayed will change accordingly.
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
int ne555 = 7;  //attach to the third pin of NE555
unsigned long duration1;  //the variable to store the HIGH length of the pulse
unsigned long duration2;  //the variable to store the LOW length of the pulse
float dc;  //the variable to store the duty cycle
void setup()
{
  pinMode(ne555, INPUT);  //set the ne555 as an input
  Serial.begin(9600);  // start serial port at 9600 bps:
}

void loop()
{
  duration1 = pulseIn(ne555, HIGH);  //Reads a pulse on ne555
  duration2 = pulseIn(ne555, LOW);  //Reads a pulse on ne555
  dc = float (duration1) / (duration1 + duration2) * 100;
  Serial.print("Duty cycle: ");
  Serial.print(dc);  //print the length of the pulse on the serial monitor
  Serial.print(" %");
  Serial.println();  //print an blank on serial monitor
  delay(500);  //wait for 500 microseconds
}
