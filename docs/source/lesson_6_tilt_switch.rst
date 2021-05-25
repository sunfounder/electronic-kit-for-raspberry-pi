**Lesson 6 Tilt Switch**
============================

**Introduction**
---------------------

In this lesson, we'll learn a new switch component, tilt switch. Here we
apply two LEDs to indicate the current state of tilt switch. You can
also use this kind of switch to make a sense light with the clamshell
box.

Newly Added Components
--------------------------

.. image:: media_pi/image213.png
    :width: 800
    :align: center

**Principle**
----------------

The principle is very simple. When the switch is tilted in a certain
angle, the ball inside rolls down and touches the two contacts connected
to the pins outside, thus triggering circuits. Otherwise the ball will
stay away from the contacts, thus breaking the circuits.

.. image:: media_pi/image110.jpeg
    :width: 800
    :align: center

**Schematic Diagram**
-----------------------------

.. image:: media_pi/image214.png
    :width: 800
    :align: center

**Build the Circuit**
-------------------------

.. image:: media_pi/image112.png
    :width: 800
    :align: center

**For C Language Users**
----------------------------

**Command**
^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_6_TiltSwitch

**2.** Compile the code.

.. code-block::

    gcc 6_Tilt.c -lwiringPi

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

When the tilt switch is level, the green LED turns on. 
If you tilt the switch, the red LED will turn on.

**Code**
^^^^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>  
    2.#include <stdio.h>  
    3.  
    4.#define TiltPin     0  
    5.#define Gpin        2  
    6.#define Rpin        3  
    7.  
    8.int main(void)  
    9.{     
    10.    if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen  
    11.        printf("setup wiringPi failed !");  
    12.        return 1;   
    13.    }  
    14.  
    15.    pinMode(TiltPin, INPUT);  
    16.    pinMode(Gpin, OUTPUT);  
    17.    pinMode(Rpin, OUTPUT);  
    18.  
    19.    while(1){  
    20.          
    21.        if(1 == digitalRead(TiltPin)){  
    22.            delay(10);  
    23.            if(1 == digitalRead(TiltPin)){  
    24.                digitalWrite(Rpin, HIGH);  
    25.                digitalWrite(Gpin, LOW);  
    26.                printf("RED\n");  
    27.            }  
    28.        }  
    29.        else if(0 == digitalRead(TiltPin)){  
    30.            delay(10);  
    31.            if(0 == digitalRead(TiltPin)){  
    32.                while(!digitalRead(TiltPin));                 
    33.                digitalWrite(Rpin, LOW);  
    34.                digitalWrite(Gpin, HIGH);  
    35.                printf("GREEN\n");  
    36.            }  
    37.        }  
    38.    }  
    39.    return 0;  
    40.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    15.    pinMode(TiltPin, INPUT);  
    16.    pinMode(Gpin, OUTPUT);  
    17.    pinMode(Rpin, OUTPUT);  

Initialize pins, then set the 
pin of tilt switch to INPUT mode, 
and LEDs to OUTPUT mode.

.. code-block::

    21.        if(1 == digitalRead(TiltPin)){

It is used to judge whether the tilt switch is tilted 
or not. The value of TiltPin is firstly read, if it is 
equal to 1, the codes inside the if() statement run; 
otherwise, the codes of if are skipped.

.. code-block::

    21.    if(1 == digitalRead(TiltPin)){  
    22.            delay(10);  
    23.            if(1 == digitalRead(TiltPin)){  
    24.                digitalWrite(Rpin, HIGH);  
    25.                digitalWrite(Gpin, LOW);  
    26.                printf("RED\n");  
    27.            }  
    28.        }  

When the tilt is tilted, the tilt switch 
is on; the Raspberry Pi reads a high level at the tilt 
pin, so the red LED is on and green LED off.

.. code-block::

    29.        else if(0 == digitalRead(TiltPin)){  
    30.            delay(10);  
    31.            if(0 == digitalRead(TiltPin)){  
    32.                while(!digitalRead(TiltPin));                 
    33.                digitalWrite(Rpin, LOW);  
    34.                digitalWrite(Gpin, HIGH);  
    35.                printf("GREEN\n");  
    36.            }  
    37.        }  

When the tilt is level, the tilt switch is off; 
the Raspberry Pi reads a low level at the tilt pin, 
so the red LED is off and green LED on.

**For Python Language Users**
--------------------------------

**Command**
^^^^^^^^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

**2.** Run the code.

.. code-block::

    sudo python3 6_Tilt.py

When the tilt switch is level, the green LED turns on. If you tilt the
switch, the red LED will turn on.

**code**
^^^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.  
    3.TiltPin = 17  
    4.Gpin   = 27  
    5.Rpin   = 22  
    6.  
    7.def setup():  
    8.    GPIO.setmode(GPIO.BCM)       
    9.    GPIO.setup(Gpin, GPIO.OUT,initial=GPIO.HIGH)      
    10.    GPIO.setup(Rpin, GPIO.OUT,initial=GPIO.LOW)      
    11.    GPIO.setup(TiltPin, GPIO.IN)     
    12.    GPIO.add_event_detect(TiltPin, GPIO.BOTH, callback=detect, bouncetime=200)  
    13.  
    14.def Led(x):  
    15.    if x == 0:  
    16.        GPIO.output(Rpin, 1)  
    17.        GPIO.output(Gpin, 0)  
    18.    if x == 1:  
    19.        GPIO.output(Rpin, 0)  
    20.        GPIO.output(Gpin, 1)  
    21.  
    22.def Print(x):  
    23.    if x == 0:  
    24.        print ('    *************')  
    25.        print ('    *   Tilt!   *')  
    26.        print ('    *************')  
    27.  
    28.def detect(chn):  
    29.    Led(GPIO.input(TiltPin))  
    30.    Print(GPIO.input(TiltPin))  
    31.  
    32.def loop():  
    33.    while True:  
    34.        pass  
    35.  
    36.def destroy():  
    37.    GPIO.output(Gpin, GPIO.LOW)       # Green LED off  
    38.    GPIO.output(Rpin, GPIO.LOW)       # Red LED off  
    39.    GPIO.cleanup()                     # Release resource  
    40.  
    41.if __name__ == '__main__':     # Program start from here  
    42.    setup()  
    43.    try:  
    44.        loop()  
    45.        # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.  
    46.    except KeyboardInterrupt:    
    47.        destroy()  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    12.    GPIO.add_event_detect(TiltPin, GPIO.BOTH, callback=detect, bouncetime=200)

Set up a falling detect on TiltPin, and callback function to detect. 
Here bouncetime is to add rise threshold detection on the 
channel and ignore edge operations less than 200ms caused by switch jitter.

.. code-block::

    13.def Led(x):  
    14.    if x == 0:  
    15.        GPIO.output(Rpin, 1)  
    16.        GPIO.output(Gpin, 0)  
    17.    if x == 1:  
    18.        GPIO.output(Rpin, 0)  
    19.        GPIO.output(Gpin, 1)  

Define a Led() function to set the mode of the two LEDs. 
When x = 0, the red LED goes on and the green light goes off; 
when x = 1, the red LED goes off, the green LED goes on. 
When the function is called, the mode of the LED can be set 
directly with the statement Led(1) or Led(0).

.. code-block::

    28.def detect(chn):  
    29.    Led(GPIO.input(TiltPin))  
    30.    Print(GPIO.input(TiltPin))  

This is a callback function that executes when a 
trigger is detected. Assign the current TiltPin state (0 or 1) 
to the Led function, that is, pass parameters to the 
Led function. The Led function then performs the 
corresponding operation on the LEDs.

**Phenomenon Picture**
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: media_pi/image113.jpeg
    :width: 800
    :align: center







