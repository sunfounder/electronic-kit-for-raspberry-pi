/**********************************************************************
* Filename    : 12_Doorbell.c
* Description : Make a buzzer beep by a button.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define BeepPin 0
#define ButtonPin 	2

int main(void){
	if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(BeepPin, OUTPUT);   
	pinMode(ButtonPin, INPUT);
	pullUpDnControl(ButtonPin, PUD_DOWN);
	
	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                Doorbell              |\n");
	printf("|    ------------------------------    |\n");
	printf("|        Buzzer connect to GPIO 0      |\n");
	printf("|        Button connect to GPIO 2      |\n");
	printf("|                                      |\n");
	printf("|            Make a Doorbell           |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		// Indicate that button has pressed down
		if(digitalRead(ButtonPin) == 1){
			delay(10);
			if(digitalRead(ButtonPin) == 1){
			//beep on
			printf("Buzzer on\n");
			digitalWrite(BeepPin, HIGH);
			delay(100);
			}
		}
		else{
			printf("Buzzer off\n");
			//beep off
			digitalWrite(BeepPin, LOW);
			delay(100);
		}
		
		
	}

	return 0;
}

