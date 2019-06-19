/**********************************************************************
* Filename 		: 7_SlideSwitch.c
* Description 	: Make a slide switch to contral which led on
* Author 		: Dream
* E-mail 		: support@sunfounder.com
* Website 		: www.sunfounder.com
* Update 		: Dream    <2016-07-26>
* Detail		: <update details>
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define slidePin		0
#define led1			2
#define led2 			3

int main(void)
{
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(slidePin, INPUT);
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|              Slide Switch            |\n");
	printf("|    ------------------------------    |\n");
	printf("|      Middle pin of slide switch      |\n");
	printf("|       connect to GPIO 0(pin 11)      |\n");
	printf("|   LED1 connect to GPIO 2(pin 13)     |\n");
	printf("|    LED2 connect to GPIO 3(pin 15)    |\n");
	printf("|                                      |\n");
	printf("|slide switch to contral which led on. |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================");
	printf("\n");
	printf("\n");
	
	while(1){
		// slide switch high, led1 on
		if(digitalRead(slidePin) == 1){
			digitalWrite(led1, HIGH);
			digitalWrite(led2, LOW);
			printf("LED1 on\n");
			delay(100);
		}
		// slide switch low, led2 on
		if(digitalRead(slidePin) == 0){
			digitalWrite(led2, HIGH);
			digitalWrite(led1, LOW);
			printf(".....LED2 on\n");
			delay(100);
		}
	}

	return 0;
}


