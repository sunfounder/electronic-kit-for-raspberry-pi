#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time
# Set #17 as LED pin
LedPin = 17
# Set #12 as button pin
BtnPin = 12

# Set Led status to False(OFF)
Led_status = False

# Define a function to print message at the beginning
def print_message():
	print ("========================================")
	print ("|          Button control LED          |")
	print ("|    ------------------------------    |")
	print ("|         LED connect to BCM 17        |")
	print ("|        Button connect to BCM 12      |")
	print ("|                                      |")
	print ("|   Press button to turn on/off LED.   |")
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
	GPIO.setup(BtnPin, GPIO.IN)
	# Set LedPin's mode to output, 
	# and initial level to LOW (0v)
	GPIO.setup(LedPin, GPIO.OUT, initial=GPIO.LOW)
	
	# Set up a falling detect on BtnPin, 
	# and callback function to swLed
	GPIO.add_event_detect(BtnPin, GPIO.FALLING, callback=swLed)

# Define a callback function for button callback
def swLed(ev=None):
	global Led_status
	# Switch led status(on-->off; off-->on)
	Led_status = not Led_status
	GPIO.output(LedPin, Led_status)
	
	#if Led_status:
	#	print 'LED OFF...'
	#else:
	#	print '...LED ON'

# Define a main function for main process
def main():
	# Print messages
	print_message()
	while True:
		# Don't do anything.
		time.sleep(1)

# Define a destroy function for clean up everything after
# the script finished 
def destroy():
	# Turn off LED
	GPIO.output(LedPin, GPIO.LOW)
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

