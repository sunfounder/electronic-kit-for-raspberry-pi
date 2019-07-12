#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time

Buzzer = 17

CL = [0, 131, 147, 165, 175, 196, 211, 248]        # Frequency of Low C notes
CM = [0, 262, 294, 330, 350, 393, 441, 495]        # Frequency of Middle C notes
CH = [1, 525, 589, 661, 700, 786, 882, 990]        # Frequency of High C notes

song = [    CH[5], CH[2], CM[6], CH[2], CH[3], CH[6],CH[0], CH[3], # Notes of song
            CH[5], CH[3], CM[6], CH[2],CH[0]]

beat = [    1,1,1,1,1,1,2,1,1,1,1,1,3    ]

def print_message():
    print ("========================================")
    print ("|            Passive Buzzer            |")
    print ("|    ------------------------------    |")
    print ("|        Buzzer connect to BCM 17      |")
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
    GPIO.setup(Buzzer, GPIO.OUT)    # Set pins' mode is output
    global Buzz                        # Assign a global variable to replace GPIO.PWM 
    Buzz = GPIO.PWM(Buzzer, 440)    # 440 is initial frequency.
    Buzz.start(50)                    # Start Buzzer pin with 50% duty ration

def loop():
    while True:
        print ('\n    Playing song...')
        for i in range(1, len(song)):        # Play song 
            if  song[i] == 1 :
                time.sleep(beat[i] *0.25)
            else:
                #Buzz.ChangeFrequency(song[i])    # Change the frequency along the song note
                Buzz = GPIO.PWM(Buzzer, song[i])    # 440 is initial frequency.
                Buzz.start(50)
                time.sleep(beat[i] * 0.25)        # delay a note for beat * 0.5s
                Buzz.stop()
        time.sleep(1)                        # Wait a second for next song.
        
def destory():
    Buzz.stop()                    # Stop the buzzer
    GPIO.output(Buzzer, LOW)        # Set Buzzer pin to low
    GPIO.cleanup()                # Release resource

if __name__ == '__main__':        # Program start from here
    setup()
    try:
        loop()
    except KeyboardInterrupt:      # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
        destory()
