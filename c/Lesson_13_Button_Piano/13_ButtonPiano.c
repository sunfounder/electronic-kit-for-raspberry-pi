/**********************************************************************
* Filename    : 13_ButtonPiano.c
* Description : Use buzzer to play music.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>

#define BuzPin    0

const int Tone[] = {262,294,330,350,393,441,495};//define DO, RE, MI, FA, SO, LA, TI
int beat[] = {1,1,1,1,1,1,1};
const int Btn[] = {2,3,4,5,6,10,11};//define 7 buttons

int main(void)
{
	int i, j;
	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|            Button Piano              |\n");
	printf("|    ------------------------------    |\n");
	printf("|         Buzzer connect to GPIO 0     |\n");
	printf("|                                      |\n");
	printf("|          Make Buzzer playing         |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	if(softToneCreate(BuzPin) == -1){
		printf("setup softTone failed !");
		return 1; 
	}

	//set the buttons mode
	for(int j=0;j<7;j++)
	{
		pinMode(Btn[j], INPUT);
	}
		

	while(1){
		//printf("Please press button to play the piano\n");
		// Indicate that button has pressed down	
		for(i=0;i<7;i++)
		{
			if(digitalRead(Btn[i])==1)
			{
				delay(10);//Prevent the button' s vibration
				if(digitalRead(Btn[i])==1)
				{
					softToneWrite(BuzPin, Tone[i]);	
					delay(beat[i]*250);
					printf("1");
				}
			}
			else
			softToneWrite(BuzPin, 0);
			if(i==7)
			i=0;
		}			
	}
	return 0;
}
