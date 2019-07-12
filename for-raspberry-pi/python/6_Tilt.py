#!/usr/bin/env python3
import RPi.GPIO as GPIO

TiltPin = 17
Gpin   = 27
Rpin   = 22

def print_message():
	print ("========================================")
	print ("|           Tilt control LED           |")
	print ("|    ------------------------------    |")
	print ("|         Tilt connect to BCM 17       |")
	print ("|      Green LED connect to BCM 27     |")
	print ("|        Red LED connect to BCM 22     |")
	print ("|                                      |")
	print ("|       User Tilt to control LED       |")
	print ("|                                      |")
	print ("|                            SunFounder|")
	print ("========================================\n")
	print ('Program is running...')
	print ('Please press Ctrl+C to end the program...')
	input ("Press Enter to begin\n")

def setup():
	GPIO.setmode(GPIO.BCM)       # Numbers GPIOs by BCM
	GPIO.setup(Gpin, GPIO.OUT,initial=GPIO.HIGH)     # Set Green Led Pin mode to output
	GPIO.setup(Rpin, GPIO.OUT,initial=GPIO.LOW)     # Set Red Led Pin mode to output
	GPIO.setup(TiltPin, GPIO.IN)    # Set BtnPin's mode is input
	GPIO.add_event_detect(TiltPin, GPIO.BOTH, callback=detect, bouncetime=200)

def Led(x):
	if x == 0:
		GPIO.output(Rpin, 1)
		GPIO.output(Gpin, 0)
	if x == 1:
		GPIO.output(Rpin, 0)
		GPIO.output(Gpin, 1)

def Print(x):
	if x == 0:
		print ('    *************')
		print ('    *   Tilt!   *')
		print ('    *************')

def detect(chn):
	Led(GPIO.input(TiltPin))
	Print(GPIO.input(TiltPin))

def loop():
	while True:
		pass

def destroy():
	GPIO.output(Gpin, GPIO.LOW)       # Green led off
	GPIO.output(Rpin, GPIO.LOW)       # Red led off
	GPIO.cleanup()                     # Release resource

if __name__ == '__main__':     # Program start from here
	print_message()
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()

