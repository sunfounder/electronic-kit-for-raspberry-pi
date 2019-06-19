/**********************************************************************
* Filename    : 2_FlowingLedLight.c
* Description : Make an Flowiing Led Light.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
//The hardware drive library designed for the C language of Raspberry Pi. Adding this library is convenient for hardware initialization, I/O ports, PWM outputs, etc.   
#include <stdio.h>
// Standard I/O library. The pintf function used for printing the data displayed on the screen is realized by this library.  There are many other performance functions for you to explore. 


const int LedPin[]={0,1,2,3,4,5,6,10};   //Define 8 LED pin 

int main(void)
{
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	for(int j=0;j<8;j++)
	{
		pinMode(LedPin[j], OUTPUT);// Set LedPin as output to write value to it.
		digitalWrite(LedPin[j], LOW);
	}
	 

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|           Flowing LED Light          |\n");
	printf("|    ------------------------------    |\n");
	printf("|       LED connect to GPIO 0 to 7     |\n");
	printf("|                                      |\n");
	printf("|        Make a flowing led light      |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================");
	printf("\n");
	printf("\n");
	
	while(1){
        for(int i=0;i<8;i++)
        {
			// LED on
			digitalWrite(LedPin[i], HIGH);			 		
			delay(100);
		
        }
		for(int i=7;i>-1;i--)
        {       
			// LED off
			digitalWrite(LedPin[i], LOW);
			delay(100);
        }
	}

	return 0;
}

