import RPi.GPIO as GPIO
import time
import threading

#define the pins connect to 74HC595
SDI   = 17      #serial data input(DS)
RCLK  = 18      #memory clock input(STCP)
SRCLK = 27       #shift register clock input(SHCP)
number = (0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80)
 
ledPin =(22,23,24) 

greenLight = 5
yellowLight = 3
redLight = 9
lightColor=("Red","Green","Yellow")

colorState=0
counter = 9      
t = 0         

def print_msg():
    print ("========================================")
    print ("|             Traffic Light            |")
    print ("|    ------------------------------    |")
    print ("|         SDI connect to BCM 17        |")
    print ("|         RCLK connect to BCM 18       |")
    print ("|        SRCLK connect to BCM 27       |")
    print ("|       Red Pin connect to BCM 22      |")
    print ("|      Green Pin connect to BCM 23     |")
    print ("|      Yellow Pin connect to BCM 24    |")
    print ("|                                      |")
    print ("|          Make a Traffic Light        |")
    print ("|                                      |")
    print ("|                            SunFounder|")
    print ("========================================\n")
    print ('Program is running...')
    print ('Please press Ctrl+C to end the program...')
    input ("Press Enter to begin\n")
    
def setup():
    print_msg()
    GPIO.setmode(GPIO.BCM)   
    GPIO.setup(SDI, GPIO.OUT)   
    GPIO.setup(RCLK, GPIO.OUT)
    GPIO.setup(SRCLK, GPIO.OUT)
    for pin in ledPin:
        GPIO.setup(pin,GPIO.OUT)
    
            
def hc595_shift(dat):     
    for bit in range(0, 8):    
        GPIO.output(SDI, 0x80 & (dat << bit))
        GPIO.output(SRCLK, GPIO.HIGH)
        GPIO.output(SRCLK, GPIO.LOW)
    GPIO.output(RCLK, GPIO.HIGH)
    GPIO.output(RCLK, GPIO.LOW)

def display(num):  
    hc595_shift(0xff)   
    hc595_shift(number[num%10]) 
    time.sleep(0.003)   
    

def timer():        #timer function
    global counter
    global colorState
    global t
    t = threading.Timer(1.0,timer)  
    t.start()     
    counter-=1                          
    if (counter is 0):
        if(colorState is 0):
            counter= greenLight
        if(colorState is 1):
            counter=yellowLight
        if (colorState is 2):
            counter=redLight
        colorState=(colorState+1)%3
    print ("counter : %d    color: %s "%(counter,lightColor[colorState]))

def lightup(state):
    for i in range(0,3):
        GPIO.output(ledPin[i], GPIO.LOW)
    GPIO.output(ledPin[state], GPIO.HIGH)

def loop():
    global t
    global counter
    global colorState
    t = threading.Timer(1.0,timer)   
    t.start()                          
    while True:
        display(counter)
        lightup(colorState)
        
def destroy():   # When "Ctrl+C" is pressed, the function is executed. 
    global t
    GPIO.cleanup()      
    t.cancel()      #cancel the timer

if __name__ == '__main__': # Program starting from here 
    setup() 
    try:
        loop()  
    except KeyboardInterrupt:  
        destroy()  