#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time

# Set #17 as slide switch pin, #18 as led1 pin, #27 as led2 pin
slidePin = 17
led1Pin = 27
led2Pin = 22

# Define a function to print message at the beginning
def print_message():
	print ("========================================")
	print ("|              Slide Switch            |")
	print ("|    ------------------------------    |")
	print ("|      Middle pin of slide switch      |")
	print ("|           connect to GPIO 0;         |")
	print ("|                                      |")
	print ("|slide switch to contral which led on. |")
	print ("|                                      |")
	print ("|                            SunFounder|")
	print ("========================================\n")
	print ('Program is running...')
	print ('Please press Ctrl+C to end the program...')
	input ("Press Enter to begin\n")

# Define a setup function for some setup
def setup():
	# Set the GPIO modes to BCM Numbering
	GPIO.setmode(GPIO.BCM)
	# Set slidePin input
	# Set ledPin output, 
	# and initial level to LOW(0v)
	GPIO.setup(slidePin, GPIO.IN)
	GPIO.setup(led1Pin, GPIO.OUT, initial=GPIO.LOW)
	GPIO.setup(led2Pin, GPIO.OUT, initial=GPIO.LOW)

# Define a main function for main process
def main():
	# Print messages
	print_message()
	while True:
		# slide switch high, led1 on
		if GPIO.input(slidePin) == 1:
			print ('LED1 ON ')
			GPIO.output(led2Pin, GPIO.LOW)
			GPIO.output(led1Pin, GPIO.HIGH)

		# slide switch low, led2 on
		if GPIO.input(slidePin) == 0:
			print ('    LED2 ON ')
			GPIO.output(led1Pin, GPIO.LOW)
			GPIO.output(led2Pin, GPIO.HIGH)

		time.sleep(0.5)
# Define a destroy function for clean up everything after
# the script finished 
def destroy():
	# Turn off LED
	GPIO.output(led1Pin, GPIO.LOW)
	GPIO.output(led2Pin, GPIO.LOW)
	# Release resource
	GPIO.cleanup()                     

# If run this script directly, do:
if __name__ == '__main__':
	setup()
	try:
		main()
	# When 'Ctrl+C' is pressed, the child program 
	# destroy() will be  executed.
	except KeyboardInterrupt:
		destroy()	
		
