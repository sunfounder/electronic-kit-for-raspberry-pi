/**********************************************************************
* Filename    : 20_TrafficLight.c
* Description : Make a traffic light.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <wiringShift.h>
#include <signal.h>
#include <unistd.h>
#define     SDI     0   //serial data input(DS)
#define     RCLK    1   //memory clock input(STCP)
#define     SRCLK    2    //shift register clock input(SHCP)
const int ledPin[]={3,4,5};   //Define 3 LED pin(Red, Green, Yellow)
unsigned char SegCode[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80};

int greentime = 5;
int yellowtime = 3;
int redtime = 9;
int colorState = 0;
char *lightColor[]={"Red","Green","Yellow"};
int counter = 9;



void init(void){
	pinMode(SDI, OUTPUT); 
	pinMode(RCLK, OUTPUT); 
	pinMode(SRCLK, OUTPUT); 

	digitalWrite(SDI, 0);
	digitalWrite(RCLK, 0);
	digitalWrite(SRCLK, 0);

      for(int i=0;i<3;i++){       
        pinMode(ledPin[i],OUTPUT);
        digitalWrite(ledPin[i],LOW);
    }
}

void hc595_shift(unsigned char dat){
	int i;

	for(i=0;i<8;i++){
		digitalWrite(SDI, 0x80 & (dat << i));
		digitalWrite(SRCLK, 1);
		delay(1);
		digitalWrite(SRCLK, 0);
	}
		digitalWrite(RCLK, 1);
		delay(1);
		digitalWrite(RCLK, 0);
}

void timer(int  sig){       //Timer function
    if(sig == SIGALRM){   //If the signal is SIGALRM, the value of counter plus 1, and update the number displayed by 7-segment display
        counter --;         
        alarm(1); 
        if(counter == 0){
            if(colorState == 0) counter = greentime;
            if(colorState == 1) counter = yellowtime;
            if(colorState == 2) counter = redtime;
            colorState = (colorState+1)%3; 
        }
        printf("counter : %d \t light color: %s \n",counter,lightColor[colorState]);
    }
}

void display(int num)
{          
    hc595_shift(SegCode[num%10]); 
    delay(1);
    
}

void lightup(int state)
{
    for(int i=0;i<3;i++){
        digitalWrite(ledPin[i],LOW);
    }
        digitalWrite(ledPin[state],HIGH);    
}

int main(void)
{
    int i;
    
    printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|             Traffic Light            |\n");
	printf("|    ------------------------------    |\n");
	printf("|         DS connect to GPIO 0         |\n");
	printf("|         STCP connect to GPIO 1       |\n");
	printf("|        SHCP connect to GPIO 2        |\n");
    printf("|       Red Pin connect to GPIO 3      |\n");
	printf("|      Green Pin connect to GPIO 4     |\n");
	printf("|      Yellow Pin connect to GPIO 5    |\n");
	printf("|                                      |\n");
	printf("|          Make a Traffic Light        |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

    if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
        printf("setup wiringPi failed !");
        return 1; 
    }

    init();

    signal(SIGALRM,timer);  //configure the timer
    alarm(1);               //set the time of timer to 1s
    while(1){        
            display(counter);
            lightup(colorState); //turn on the traffic light        
         }
    return 0;
}