/**********************************************************************
* Filename    : 3_BreathingLed.c
* Description : Make potentiometer to contral a led.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
 // library used for realizing the pwm function of the software. 

#define LedPin 1 


int main (void)
{
// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	
	softPwmCreate(LedPin,  0, 100);
	// LedPin refers to one pin. 0 is the minimum value and 100 is the maximum (as a percentage). The function is to use software to create a PWM pin, set its value between 0-100%. 

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|             Breathing Led            |\n");
	printf("|    ------------------------------    |\n");
	printf("|    LED connect to GPIO 1(pin12)      |\n");
	printf("|                                      |\n");
	printf("| 		Make a breathing led.          |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");
	int i;

	while(1) // loop forever
	{
		for(i=0;i<100;i++){  // i,as the value of pwm, increases progressively during 0-1024.  
			softPwmWrite(LedPin, i); 
			delay(10);  // wait for 2ms, interval time between the changes indicates the speed of breathing. 
		} // the value of pwm add 1 every 2ms, when the value of pwm increases, the luminance of the LED increases. 

		for(i=100;i>=0;i--){
			softPwmWrite(LedPin, i);
			delay(10);
		} // the value of pwm minus 1 every 2ms, when the value of pwm decreases, the luminance of the LED decreases.
	}
	return 0 ;
}
