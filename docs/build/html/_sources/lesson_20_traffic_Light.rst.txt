**Lesson 20 Traffic Light**
=================================

**Introduction**
-------------------

In last lesson, we learned how to use a 74HC595 chip to drive 
a 7-Segment Display. Based on that, we can apply it more widely 
now, such as making a simple traffic light. Now let's get started!

**Newly Added Components**
-----------------------------

.. image:: media_pi/image251.png
    :width: 800
    :align: center

**Schematic Diagram**
----------------------------

.. image:: media_pi/image252.png
    :width: 800
    :align: center

.. image:: media_pi/image261.png
    :width: 800
    :align: center

**Build the Circuit**
---------------------------

.. image:: media_pi/image253.png
    :width: 800
    :align: center

**For C Language Users**
----------------------------

**Command**
^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_20_TrafficLight

**2.** Compile the code.

.. code-block::

    gcc 20_TrafficLight.c -lwiringPi

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

You can see the following phenomenon of traffic lights. The red LED
lights up for 9 seconds, green LED for 5s, and yellow LED for 3s.

**Code**
^^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>  
    2.#include <stdio.h>  
    3.#include <wiringShift.h>  
    4.#include <signal.h>  
    5.#include <unistd.h>  
    6.#define     SDI     0   //serial data input(DS)  
    7.#define     RCLK    1   //memory clock input(STCP)  
    8.#define     SRCLK    2    //shift register clock input(SHCP)  
    9.const int ledPin[]={3,4,5};   //Define 3 LED pin(Red, Green, Yellow)  
    10.unsigned char SegCode[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80};  
    11.  
    12.int greentime = 5;  
    13.int yellowtime = 3;  
    14.int redtime = 9;  
    15.int colorState = 0;  
    16.char *lightColor[]={"Red","Green","Yellow"};  
    17.int counter = 9;  
    18.  
    19.void init(void){  
    20.    pinMode(SDI, OUTPUT);   
    21.    pinMode(RCLK, OUTPUT);   
    22.    pinMode(SRCLK, OUTPUT);   
    23.  
    24.    digitalWrite(SDI, 0);  
    25.    digitalWrite(RCLK, 0);  
    26.    digitalWrite(SRCLK, 0);  
    27.  
    28.      for(int i=0;i<3;i++){         
    29.        pinMode(ledPin[i],OUTPUT);  
    30.        digitalWrite(ledPin[i],LOW);  
    31.    }  
    32.}  
    33.  
    34.void hc595_shift(unsigned char dat){  
    35.    int i;  
    36.    for(i=0;i<8;i++){  
    37.        digitalWrite(SDI, 0x80 & (dat << i));  
    38.        digitalWrite(SRCLK, 1);  
    39.        delay(1);  
    40.        digitalWrite(SRCLK, 0);  
    41.    }  
    42.        digitalWrite(RCLK, 1);  
    43.        delay(1);  
    44.        digitalWrite(RCLK, 0);  
    45.}  
    46.  
    47.void timer(int  sig){       //Timer function  
    48.    if(sig == SIGALRM){     
    49.        counter --;           
    50.        alarm(1);   
    51.        if(counter == 0){  
    52.            if(colorState == 0) counter = greentime;  
    53.            if(colorState == 1) counter = yellowtime;  
    54.            if(colorState == 2) counter = redtime;  
    55.            colorState = (colorState+1)%3;   
    56.        }  
    57.        printf("counter : %d \t light color: %s \n",counter,lightColor[colorState]);  
    58.    }  
    59.}  
    60.  
    61.void display(int num)  
    62.{             
    63.    hc595_shift(SegCode[num%10]);   
    64.    delay(1);      
    65.}  
    66.  
    67.void lightup(int state)  
    68.{  
    69.    for(int i=0;i<3;i++){  
    70.        digitalWrite(ledPin[i],LOW);  
    71.    }  
    72.        digitalWrite(ledPin[state],HIGH);      
    73.}  
    74.  
    75.int main(void)  
    76.{  
    77.    int i;  
    78.  
    79.    if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen  
    80.        printf("setup wiringPi failed !");  
    81.        return 1;   
    82.    }  
    83.  
    84.    init();  
    85.  
    86.    signal(SIGALRM,timer);  //configure the timer  
    87.    alarm(1);               //set the time of timer to 1s  
    88.    while(1){  
    89.          
    90.            display(counter);  
    91.        lightup(colorState);         
    92.         }  
    93.    return 0;  
    94.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    12.int greentime = 5;  
    13.int yellowtime = 3;  
    14.int redtime = 9;  

Define the duration of lighting of three LEDs. Since 
what we use is a 7-Segment Display here, we shorten 
the length of seconds of lighting of traffic lights, 
setting the green LED to light up for 5 seconds, the 
yellow LED to 3 seconds, and the red LED to 9 seconds.

.. code-block::

    15.int colorState = 0;  
    16.int counter = 9;

The variable colorState corresponds to the state of 
the traffic lights, and we only need to do a simple 
calculation of colorState to indicate the order change 
of the state of the traffic lights. The Variable counter 
is used to count down the time to each traffic light 
status and will be output on a 7-Segment Display.

.. code-block::

    19.void init(void){  
    20.    pinMode(SDI, OUTPUT);  
    21.    pinMode(RCLK, OUTPUT);  
    22.    pinMode(SRCLK, OUTPUT); 
    23.  
    24.    digitalWrite(SDI, 0);  
    25.    digitalWrite(RCLK, 0);  
    26.    digitalWrite(SRCLK, 0);  
    27.  
    28.      for(int i=0;i<3;i++){         
    29.        pinMode(ledPin[i],OUTPUT);  
    30.        digitalWrite(ledPin[i],LOW);  
    31.    }  
    32.}  

Initialize pins. Set all control pins of 74HC595 to output 
mode and initialize them to low level. At the same time, 
the LEDs are set to output mode, default low level.

.. code-block::

    47.void timer(int  sig){         
    48.    if(sig == SIGALRM){     
    49.        counter --;           
    50.        alarm(1);   
    51.        if(counter == 0){  
    52.            if(colorState == 0) counter = greentime;  
    53.            if(colorState == 1) counter = yellowtime;  
    54.            if(colorState == 2) counter = redtime;  
    55.            colorState = (colorState+1)%3;   
    56.        }  
    57.        printf("counter : %d \t light color: %s \n",counter,lightColor[colorState]);  
    58.    }  
    59.}  

On this timer, counter decreases gradually with every second passing, 
and when it goes to 0, the state of the traffic light changes accordingly.

.. code-block::

    67.void lightup(int state)  
    68.{  
    69.    for(int i=0;i<3;i++){  
    70.        digitalWrite(ledPin[i],LOW);  
    71.    }  
    72.        digitalWrite(ledPin[state],HIGH);      
    73.}  
    
The function is to turn off all the lights first, and then light 
up the corresponding LED according to the value of the traffic light state.

**For Python Language Users**
------------------------------------

**Command**
^^^^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

**2.** Run the code.

.. code-block::

    sudo python3 20_TrafficLight.py


You can see the following phenomenon of traffic lights. The red LED
lights up for 9 seconds, green LED for 5s, and yellow LED for 3s.

**Code**
^^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.import time  
    3.import threading  
    4.  
    5.#define the pins connect to 74HC595  
    6.SDI   = 17      #serial data input(DS)  
    7.RCLK  = 18      #memory clock input(STCP)  
    8.SRCLK = 27       #shift register clock input(SHCP)  
    9.number = (0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80)  
    10.   
    11.ledPin =(22,23,24)   
    12.  
    13.greenLight = 5  
    14.yellowLight = 3  
    15.redLight = 9  
    16.lightColor=("Red","Green","Yellow")  
    17.  
    18.colorState=0  
    19.counter = 9        
    20.t = 0           
    21.     
    22.def setup():  
    23.    GPIO.setmode(GPIO.BCM)     
    24.    GPIO.setup(SDI, GPIO.OUT)     
    25.    GPIO.setup(RCLK, GPIO.OUT)  
    26.    GPIO.setup(SRCLK, GPIO.OUT)  
    27.    for pin in ledPin:  
    28.        GPIO.setup(pin,GPIO.OUT)  
    29.      
    30.              
    31.def hc595_shift(dat):       
    32.    for bit in range(0, 8):      
    33.        GPIO.output(SDI, 0x80 & (dat << bit))  
    34.        GPIO.output(SRCLK, GPIO.HIGH)  
    35.        GPIO.output(SRCLK, GPIO.LOW)  
    36.    GPIO.output(RCLK, GPIO.HIGH)  
    37.    GPIO.output(RCLK, GPIO.LOW)  
    38.  
    39.def display(num):    
    40.    hc595_shift(0xff)     
    41.    hc595_shift(number[num%10])   
    42.    time.sleep(0.003)     
    43.      
    44.  
    45.def timer():        #timer function  
    46.    global counter  
    47.    global colorState  
    48.    global t  
    49.    t = threading.Timer(1.0,timer)    
    50.    t.start()       
    51.    counter-=1                            
    52.    if (counter is 0):  
    53.        if(colorState is 0):  
    54.            counter= greenLight  
    55.        if(colorState is 1):  
    56.            counter=yellowLight  
    57.        if (colorState is 2):  
    58.            counter=redLight  
    59.        colorState=(colorState+1)%3  
    60.    print ("counter : %d    color: %s "%(counter,lightColor[colorState]))  
    61.  
    62.def lightup(state):  
    63.    for i in range(0,3):  
    64.        GPIO.output(ledPin[i], GPIO.LOW)  
    65.    GPIO.output(ledPin[state], GPIO.HIGH)  
    66.  
    67.def loop():  
    68.    global t  
    69.    global counter  
    70.    global colorState  
    71.    t = threading.Timer(1.0,timer)     
    72.    t.start()                            
    73.    while True:  
    74.        display(counter)  
    75.        lightup(colorState)  
    76.          
    77.def destroy():   # When "Ctrl+C" is pressed, the function is executed.   
    78.    global t  
    79.    GPIO.cleanup()        
    80.    t.cancel()      #cancel the timer  
    81.  
    82.if __name__ == '__main__': # Program starting from here   
    83.    setup()   
    84.    try:  
    85.        loop()    
    86.    except KeyboardInterrupt:    
    87.        destroy()    

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    13.greenLight = 5  
    14.yellowLight = 3  
    15.redLight = 9  

Define the duration of lighting of three LEDs. 
Since what we use is a 7-Segment Display here, 
we shorten the length of seconds of lighting of 
traffic LEDs, setting the green LED to light up for 
5 seconds, the yellow LED to 3 seconds, and the red 
LED to 9 seconds.

.. code-block::

    18.colorState=0  
    19.counter = 9        

The variable colorState corresponds to the state of the traffic LEDs, 
and we only need to do a simple calculation of colorState to indicate 
the order change of the state of the traffic LEDs.
counter is used to count down the time to each traffic LED status 
and will be output on a 7-Segment Display.

.. code-block::

    45.def timer():        #timer function  
    46.    global counter  
    47.    global colorState  
    48.    global t  
    49.    t = threading.Timer(1.0,timer)    
    50.    t.start()       
    51.    counter-=1                            
    52.    if (counter is 0):  
    53.        if(colorState is 0):  
    54.            counter= greenLight  
    55.        if(colorState is 1):  
    56.            counter=yellowLight  
    57.        if (colorState is 2):  
    58.            counter=redLight  
    59.        colorState=(colorState+1)%3  
    60.    print ("counter : %d    color: %s "%(counter,lightColor[colorState]))  
On this timer, counter decreases gradually with every second passing, 
and when it goes to 0, the state of the traffic LED changes accordingly.

.. code-block::

    62.def lightup(state):  
    63.    for i in range(0,3):  
    64.        GPIO.output(ledPin[i], GPIO.LOW)  
    65.    GPIO.output(ledPin[state], GPIO.HIGH)  

The function is to turn off all the LEDs first, and then 
light up the corresponding LED according to the value of the 
traffic LED state.

**Phenomenon Picture**
-----------------------------

.. image:: media_pi/image192.jpeg
    :width: 600
    :align: center
