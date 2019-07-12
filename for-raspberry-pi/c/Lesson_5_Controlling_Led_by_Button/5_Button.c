/**********************************************************************
* Filename    : 5_Button.c
* Description : Controlling an led with button.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin		0
#define ButtonPin 	26
int state = 0;


int main(void){
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);
	// Pull down to 0V,make GPIO0 a stable level
	pullUpDnControl(ButtonPin, PUD_DOWN);

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|          Button control LED          |\n");
	printf("|    ------------------------------    |\n");
	printf("|      LED connect to GPIO 0(pin 11)   |\n");
	printf("|    Button connect to GPIO 26(pin 32) |\n");
	printf("|                                      |\n");
	printf("|     Press button to turn on LED.     |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	
	
	while(1){
		// Indicate that button has pressed down
		if(digitalRead(ButtonPin) == 1)
		{
			delay(10);
			if(digitalRead(ButtonPin) == 1)
			{
				state ++;
				if(state%2 == 1)
				{
					digitalWrite(LedPin,HIGH);
					delay(100);
				}
				if(state%2 == 0)
				{
					digitalWrite(LedPin,LOW);
					delay(100);
				}
			}
		}
		
	}
	return 0;
}

