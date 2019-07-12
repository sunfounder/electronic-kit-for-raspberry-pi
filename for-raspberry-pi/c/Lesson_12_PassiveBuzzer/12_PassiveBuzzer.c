/**********************************************************************
* Filename    : 11_PassiveBuzzer.c
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


#define  CL1  131
#define  CL2  147
#define  CL3  165
#define  CL4  175
#define  CL5  196
#define  CL6  221
#define  CL7  248

#define  CM1  262
#define  CM2  294
#define  CM3  330
#define  CM4  350
#define  CM5  393
#define  CM6  441
#define  CM7  495

#define  CH1  525
#define  CH2  589
#define  CH3  661
#define  CH4  700
#define  CH5  786
#define  CH6  882
#define  CH7  990



int song[] = {CH5,CH2,CM6,CH2,CH3,CH6,0,CH3,CH5,CH3,CM6,CH2,0};

int beat[] = {1,1,1,1,1,1,2,1,1,1,1,1,3};

int main(void)
{
	int i, j;
	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|            Passive Buzzer            |\n");
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

	while(1){
		printf("music is being played...\n");
		

		for(int i=0;i<sizeof(song)/4;i++){
			softToneWrite(BuzPin, song[i]);	
			delay(beat[i] * 250);
		}
	
	}

	return 0;
}
