/**********************************************************************
* Filename    : 9_4N35.c
* Description : 
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>   
#include <stdio.h>

#define OptoPin  0

int main(void)
{
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(OptoPin,OUTPUT);
	//pinMode(LedPin, OUTPUT);// Set LedPin as output to write value to it. 

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                  4N35                |\n");
	printf("|    ------------------------------    |\n");
	printf("|       LED connect to GPIO 0(pin11)   |\n");
	printf("|                                      |\n");
	printf("|        LED will Blink at 500ms       |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================");
	printf("\n");
	printf("\n");
	
	while(1){
		// Turn LED off
		digitalWrite(OptoPin, HIGH);//set the OptoPin as high level,then the led connected on the output of 4n35 will be off
		delay(500);
		// Turn LED on
		digitalWrite(OptoPin, LOW);
		delay(500);
	}

	return 0;
}
