/**********************************************************************
* Filename    : 6_VibrationTilt.c
* Description : Use Tilt to control LED.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/

#include <wiringPi.h>
#include <stdio.h>

#define TiltPin		0
#define Gpin		2
#define Rpin		3

int main(void)
{
	

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|              Tilt Switch             |\n");
	printf("|    ------------------------------    |\n");
	printf("|      Tilt connect to GPIO 0(pin 11)  |\n");
	printf("|   Green LED connect to GPIO 2(pin 13)|\n");
	printf("|    Red LED connect to GPIO 3(pin 15) |\n");
	printf("|                                      |\n");
	printf("|        Use Tilt to control LED       |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	pinMode(TiltPin, INPUT);
	pinMode(Gpin, OUTPUT,);
	pinMode(Rpin, OUTPUT);


	while(1){
		
		if(1 == digitalRead(TiltPin)){
			delay(10);
			if(1 == digitalRead(TiltPin)){
				digitalWrite(Rpin, HIGH);
				digitalWrite(Gpin, LOW);
				printf("RED\n");
			}
		}
		else if(0 == digitalRead(TiltPin)){
			delay(10);
			if(0 == digitalRead(TiltPin)){
				while(!digitalRead(TiltPin));				
				digitalWrite(Rpin, LOW);
				digitalWrite(Gpin, HIGH);
				printf("GREEN\n");
			}
		}
	}
	return 0;
}
