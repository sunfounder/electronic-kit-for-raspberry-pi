#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time

BeepPin = 17
ResetBtnPin = 18
BtnPin =(27,22,23)
LedPin =(5,6,13,19)


def print_message():
    print ("========================================")
    print ("|            Answer Machine            |")
    print ("|    ------------------------------    |")
    print ("|        Buzzer connect to BCM 17      |")
    print ("|  Buttons connect to BCM 18 27 22 23  |")
    print ("|    LEDs connect to BCM 5 6 13 19     |")
    print ("|                                      |")
    print ("|         Make a Answer Machine        |")
    print ("|                                      |")
    print ("|                            SunFounder|")
    print ("========================================\n")
    print ('Program is running...')
    print ('Please press Ctrl+C to end the program...')
    input ("Press Enter to begin\n")

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(BeepPin, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(ResetBtnPin, GPIO.IN)
    GPIO.setup(LedPin[0], GPIO.OUT, initial=GPIO.HIGH)
    for i in range(1,4):
        GPIO.setup(LedPin[i], GPIO.OUT, initial=GPIO.LOW)
    for i in range(0,3):
        GPIO.setup(BtnPin[i], GPIO.IN)

def Alarm():
    for i in range(0,50):
        GPIO.output(BeepPin,GPIO.HIGH)
        time.sleep(0.003)
        GPIO.output(BeepPin,GPIO.LOW)
        time.sleep(0.003)


def loop():
    print_message()
    flag = 1
    while True:
        if GPIO.input(ResetBtnPin) == 1:
            flag = 1
            GPIO.output(LedPin[0],GPIO.HIGH)
            GPIO.output(LedPin[1],GPIO.LOW)
            GPIO.output(LedPin[2],GPIO.LOW)
            GPIO.output(LedPin[3],GPIO.LOW)
        if flag == 1:
            if GPIO.input(BtnPin[0]) == 1:
                flag = 0
                GPIO.output(LedPin[0],GPIO.LOW)
                Alarm()
                GPIO.output(LedPin[1],GPIO.HIGH)
                GPIO.output(LedPin[2],GPIO.LOW)
                GPIO.output(LedPin[3],GPIO.LOW)
            elif GPIO.input(BtnPin[1]) == 1:
                flag = 0
                GPIO.output(LedPin[0],GPIO.LOW)
                Alarm()
                GPIO.output(LedPin[1],GPIO.LOW)
                GPIO.output(LedPin[2],GPIO.HIGH)
                GPIO.output(LedPin[3],GPIO.LOW)
            elif GPIO.input(BtnPin[2]) == 1:
                flag = 0
                GPIO.output(LedPin[0],GPIO.LOW)
                Alarm()
                GPIO.output(LedPin[1],GPIO.LOW)
                GPIO.output(LedPin[2],GPIO.LOW)
                GPIO.output(LedPin[3],GPIO.HIGH)
            



def destroy():
    # Turn off buzzer
    GPIO.output(BeepPin, GPIO.LOW)
    GPIO.output(LedPin[0],GPIO.LOW)
    GPIO.output(LedPin[1],GPIO.LOW)
    GPIO.output(LedPin[2],GPIO.LOW)
    GPIO.output(LedPin[3],GPIO.HIGH)
    # Release resource
    GPIO.cleanup()    

# If run this script directly, do:
if __name__ == '__main__':
    setup()
    try:
        loop()
    # When 'Ctrl+C' is pressed, the child program 
    # destroy() will be  executed.
    except KeyboardInterrupt:
        destroy()