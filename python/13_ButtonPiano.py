#!/usr/bin/env python3


import RPi.GPIO as GPIO
import time

Buzzer = 17
BtnPin = [18,27,22,23,24,25,8,7]

CL = [0, 131, 147, 165, 175, 196, 211, 248]        # Frequency of Low C notes
CM = [0, 262, 294, 330, 350, 393, 441, 495]        # Frequency of Middle C notes
CH = [1, 525, 589, 661, 700, 786, 882, 990]        # Frequency of High C notes

song = [     0,CM[1],CM[2],CM[3],CM[4],CM[5],CM[6],CM[7]    ]
beat = [    1,1, 1, 1, 1, 1, 1,  1]

def print_message():
    print ("========================================")
    print ("|            Button Piano            |")
    print ("|    ------------------------------    |")
    print ("|        Buzzer connect to BCM 17      |")
    print ("|   Buttons connect to BCM 18,27,22,   |")
    print ("|           23,24,25,8,7               |")
    print ("|                                      |")
    print ("|          Make Buzzer playing         |")
    print ("|                                      |")
    print ("|                            SunFounder|")
    print ("========================================\n")
    print ('Program is running...')
    print ('Please press Ctrl+C to end the program...')

def setup():
    print_message()
    GPIO.setmode(GPIO.BCM)        # Numbers GPIOs by physical location
    for i in range(1, len(BtnPin)):
        GPIO.setup(BtnPin[i],GPIO.IN)
    GPIO.setup(Buzzer, GPIO.OUT)    # Set pins' mode is output

def loop():
    global Buzz  
    while True:
        #print ('\n    Please playing piano...')
        for i in range(1, len(BtnPin)):        # Play song 1
            if GPIO.input(BtnPin[i]) == 1:
                Buzz = GPIO.PWM(Buzzer, song[i])    # 440 is initial frequency.
                Buzz.start(50)
                time.sleep(beat[i] * 0.25)        # delay a note for beat * 0.5s
                Buzz.stop()
       
                   
def destory():
    Buzz.stop()                    # Stop the buzzer
    GPIO.output(Buzzer, 0)        # Set Buzzer pin to low
    GPIO.cleanup()                # Release resource

if __name__ == '__main__':        # Program start from here
    setup()
    try:
        loop()
    except KeyboardInterrupt:      # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
        destory()
