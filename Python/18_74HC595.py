#!/usr/bin/env python3

#================================================
#
#   This program is for SunFounder SuperKit for Rpi.
#
#   Extend use of 8 LED with 74HC595.
#
#   Change the  WhichLeds and sleeptime value under
#   loop() function to change LED mode and speed.
#
#=================================================

import RPi.GPIO as GPIO
import time

SDI   = 17
RCLK  = 18
SRCLK = 27

#===============   LED Mode Defne ================
#   You can define yourself, in binay, and convert it to Hex 
#   8 bits a group, 0 means off, 1 means on
#   like : 0101 0101, means LED1, 3, 5, 7 are on.(from left to right)
#   and convert to 0x55.

LED0 = [0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80]    #original mode
BLINK = [0xff,0x00,0xff,0x00,0xff,0x00]         #blink
#=================================================

def print_message():
    print ("========================================")
    print ("|           LEDs with 74HC595          |")
    print ("|    ------------------------------    |")
    print ("|         SDI connect to GPIO 0        |")
    print ("|         RCLK connect to GPIO 1       |")
    print ("|        SRCLK connect to GPIO 2       |")
    print ("|                                      |")
    print ("|       Control LEDs with 74HC595      |")
    print ("|                                      |")
    print ("|                            SunFounder|")
    print ("========================================\n")
    print ('Program is running...')
    print ('Please press Ctrl+C to end the program...')
    input ("Press Enter to begin\n")

def setup():
    GPIO.setmode(GPIO.BCM)    # Number GPIOs by its BCM location
    GPIO.setup(SDI, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(RCLK, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(SRCLK, GPIO.OUT, initial=GPIO.LOW)

# Shift the data to 74HC595
def hc595_shift(dat):
    for bit in range(0, 8): 
        GPIO.output(SDI, 0x80 & (dat << bit))
        GPIO.output(SRCLK, GPIO.HIGH)
        time.sleep(0.001)
        GPIO.output(SRCLK, GPIO.LOW)
    GPIO.output(RCLK, GPIO.HIGH)
    time.sleep(0.001)
    GPIO.output(RCLK, GPIO.LOW)

def main():
    print_message()
    mode = LED0 
    sleeptime = 0.15        # Change speed, lower value, faster speed
    blink_sleeptime = 0.15
    
    while True:
        # Change LED status from mode
        for onoff in mode:
            hc595_shift(onoff)           
            time.sleep(sleeptime)          
        
        for onoff in BLINK:
            hc595_shift(onoff)
            time.sleep(blink_sleeptime)

        # Change LED status from mode reverse
        for onoff in reversed(mode):
            hc595_shift(onoff)          
            time.sleep(sleeptime)         

        for onoff in BLINK:
            hc595_shift(onoff)           
            time.sleep(blink_sleeptime)

def destroy():
    GPIO.cleanup()

if __name__ == '__main__':
    setup()
    try:
        main()
    except KeyboardInterrupt:
        destroy()
