/**********************************************************************
* Filename    : 14_AnswerMachine.c
* Description : Make a AnswerMachine.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define BeepPin 0
#define ResetBtnPin 1
const int BtnPin[] = {2,3,4};
const int LedPin[] = {21,22,23,24};

void Alarm()
{
    for(int i=0;i<50;i++){
    digitalWrite(BeepPin,HIGH); //the buzzer sound
    delay(2); //delay 2ms
    digitalWrite(BeepPin,LOW);  //without sound
    delay(2);       //when delay time changed,the frequency changed
  }
}

int main(void){
	if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	 pinMode(BeepPin, OUTPUT);   //set GPIO0 output
	for(int j=1;j<4;j++)
    {
        pinMode(LedPin[j], OUTPUT);
        digitalWrite(LedPin[j],LOW);
    }
    pinMode(LedPin[0], OUTPUT);
    digitalWrite(LedPin[0],HIGH);
    for(int k;k<3;k++)
    {
        pinMode(BtnPin[k], INPUT);
    }

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|            Answer Machine            |\n");
	printf("|    ------------------------------    |\n");
	printf("|        Buzzer connect to GPIO 0      |\n");
	printf("|    Buttons connect to GPIO 1 to 4    |\n");
    printf("|    LEDs connect to GPIO 21 to 24     |\n");
	printf("|                                      |\n");
	printf("|         Make a Answer Machine        |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

    int flag = 1;
    
	while(1){
        // if reset button is pressed
        if(digitalRead(ResetBtnPin) == 1)
        {
                flag = 1;              
                digitalWrite(LedPin[0], HIGH);//Reset Led turns on
                digitalWrite(LedPin[1],LOW);
                digitalWrite(LedPin[2],LOW);
                digitalWrite(LedPin[3],LOW);           
        }
        if(flag==1)
        {       
            //If the button1 press the first
            if(digitalRead(BtnPin[0]) == 1)
            {
                    flag = 0;
                    digitalWrite(LedPin[0],LOW);
                    Alarm();  //buzzer sound
                    digitalWrite(LedPin[1],HIGH);//turn the LED1 on only
                    digitalWrite(LedPin[2],LOW);
                    digitalWrite(LedPin[3],LOW);
                    while(digitalRead(ResetBtnPin));//detect the resetbtn,if pressed,out of the while loop           
            }
             if(digitalRead(BtnPin[1]) == 1)
            {        
                    flag = 0;
                    digitalWrite(LedPin[0],LOW);
                    Alarm();  //buzzer sound
                    digitalWrite(LedPin[1],LOW);
                    digitalWrite(LedPin[2],HIGH);//turn the LED2 on only
                    digitalWrite(LedPin[3],LOW);
                    while(digitalRead(ResetBtnPin));             
            }
             if(digitalRead(BtnPin[2]) == 1)
            {                              
                    flag = 0;
                    digitalWrite(LedPin[0],LOW);
                    Alarm();  //buzzer sound
                    digitalWrite(LedPin[1],LOW);
                    digitalWrite(LedPin[2],LOW);
                    digitalWrite(LedPin[3],HIGH);//turn the LED3 on only
                    while(digitalRead(ResetBtnPin));                
            }          
        }		
	}
	return 0;
}

