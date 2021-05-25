**Lesson 7 Slide Switch**
===============================

**Introduction**
-------------------

In this lesson, we are going to use a slide switch to turn on the 2
LEDs. The slide switch is a device to connect or disconnect the circuit
by sliding its handle. They are quite common in our surroundings. Now
let's see how it works.

**Newly Added Components**
---------------------------------

.. image:: media_pi/image215.png
    :width: 800
    :align: center

**Principle**
------------------

Slide Switch

.. image:: media_pi/image115.jpeg
    :width: 150
    :align: center

Just as its name suggests, slide switch is to connect or disconnect the
circuit by sliding its switch handle so as to switch the circuit. The
common types of slide switch include single pole double throw, single
pole triple throw, double pole double throw, and double pole triple
throw and so on. Generally, it is used in circuits with a low voltage
and features flexibility and stabilization. Slide switches are commonly
used in all kinds of instruments/meters equipment, electronic toys and
other fields related.

How it works: The middle pin is fixed. When the handle is pushed to the
left, the left two pins are connected; when push it to the right, the
two pins on the right connect, thus switching circuits.

Just as its name suggests, slide switch is to connect or disconnect the
circuit by sliding its switch handle so as to switch the circuit. The
common types of slide switch include single pole double throw, single
pole triple throw, double pole double throw, and double pole triple
throw and so on. Generally, it is used in circuits with a low voltage
and features flexibility and stabilization. Slide switches are commonly
used in all kinds of instruments/meters equipment, electronic toys and
other fields related.

How it works: The middle pin is fixed. When the handle is pushed to the
left, the left two pins are connected; when push it to the right, the
two pins on the right connect, thus switching circuits.

.. image:: media_pi/image216.png
    :width: 600
    :align: center

See the circuit symbol of slide switch and 2 is the middle pin.

.. image:: media_pi/image254.png
    :width: 400
    :align: center

**Schematic Diagram**
-----------------------------

Here we use a slide switch to turn the LED on/off, which is simple.
Connect the middle pin of the switch to pin 11. Connect the left pin of
the switch to **GND**, the right to **3.3V**. Attach the anode pins (the
longer pins) of the two LEDs to pin **13** and pin **15** respectively
after getting them connected with two **220Ω** resistors. In addition,
insert the cathodes of the two LEDs into **GND**. Get the slide switch
connected to the left, the signal read on pin 11 is 0 (a low level), so
the LED 1 lights up; to the right, the signal read on pin 11 is 1 (a
high level), then the LED 2 turns on.

.. image:: media_pi/image217.png
    :width: 800
    :align: center

**Build the Circuit**
-----------------------------

.. image:: media_pi/image120.png
    :width: 800
    :align: center

**For C Language Users**
----------------------------

**Command**
^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_7_SlideSwitch

**2.** Compile the code.

.. code-block::

    gcc 7_Slider.c -lwiringPi

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

When the slide is pulled to the right, the LED2 is on and LED1 off. If
the slide is pulled to the left, the LED1 is on and LED2 off.

**Code**
^^^^^^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>  
    2.#include <stdio.h>  
    3.  
    4.#define slidePin        0  
    5.#define led1            2  
    6.#define led2            3  
    7.  
    8.int main(void)  
    9.{  
    10.    // When initialize wiring failed, print message to screen  
    11.    if(wiringPiSetup() == -1){  
    12.        printf("setup wiringPi failed !");  
    13.        return 1;   
    14.    }  
    15.      
    16.    pinMode(slidePin, INPUT);  
    17.    pinMode(led1, OUTPUT);  
    18.    pinMode(led2, OUTPUT);  
    19.      
    20.    while(1){  
    21.        // slide switch high, led1 on  
    22.        if(digitalRead(slidePin) == 1){  
    23.            digitalWrite(led1, HIGH);  
    24.            digitalWrite(led2, LOW);  
    25.            printf("LED1 on\n");  
    26.            delay(100);  
    27.        }  
    28.        // slide switch low, led2 on  
    29.        if(digitalRead(slidePin) == 0){  
    30.            digitalWrite(led2, HIGH);  
    31.            digitalWrite(led1, LOW);  
    32.            printf(".....LED2 on\n");  
    33.            delay(100);  
    34.        }  
    35.    }  
    36.    return 0;  
    37.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    16.    pinMode(slidePin, INPUT);  
    17.    pinMode(led1, OUTPUT);  
    18.    pinMode(led2, OUTPUT);  

Initialize the pins connected to slide switch to the 
INPUT mode, and initialize the LED lights to the OUTPUT mode.

.. code-block::

    22.  if(digitalRead(slidePin) == 1){  
    23.            digitalWrite(led1, HIGH);  
    24.            digitalWrite(led2, LOW);  
    25.            printf("LED1 on\n");  
    26.            delay(100);  
    27.        }  

When the slide is pulled to the left, the middle pin and 
left one are connected; the Raspberry Pi reads a high level at 
the middle pin, so the LED1 is on and LED2 off.

.. code-block::

    28.        if(digitalRead(slidePin) == 0){  
    29.            digitalWrite(led2, HIGH);  
    30.            digitalWrite(led1, LOW);  
    31.            printf(".....LED2 on\n");  
    32.            delay(100);  
    33.        }  

When the slide is pulled to the right, the middle pin 
and right one are connected; the Raspberry Pi reads a 
low, so the LED2 is on and LED1 off.

**For Python Language Users**
-------------------------------

**Command**
^^^^^^^^^^^^^^^

1. Go to the folder of the code

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

2. Run the code

.. code-block::

    sudo python3 7_Slider.py

When the slide is pulled to the right, the LED2 is on and LED1 off. If
the slide is pulled to the left, the LED1 is on and LED2 off.

**Code**
^^^^^^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.import time  
    3.  
    4.slidePin = 17  
    5.led1Pin = 27  
    6.led2Pin = 22  
    7.  
    8.# Define a setup function for some setup  
    9.def setup():  
    10.    GPIO.setmode(GPIO.BCM)  
    11.    GPIO.setup(slidePin, GPIO.IN)  
    12.    GPIO.setup(led1Pin, GPIO.OUT, initial=GPIO.LOW)  
    13.    GPIO.setup(led2Pin, GPIO.OUT, initial=GPIO.LOW)  
    14.  
    15.def main():  
    16.    while True:  
    17.        # slide switch high, led1 on  
    18.        if GPIO.input(slidePin) == 1:  
    19.            print ('LED1 ON ')  
    20.            GPIO.output(led2Pin, GPIO.LOW)  
    21.            GPIO.output(led1Pin, GPIO.HIGH)  
    22.  
    23.        # slide switch low, led2 on  
    24.        if GPIO.input(slidePin) == 0:  
    25.            print ('    LED2 ON ')  
    26.            GPIO.output(led1Pin, GPIO.LOW)  
    27.            GPIO.output(led2Pin, GPIO.HIGH)  
    28.        time.sleep(0.5)  
    29.  
    30.def destroy():  
    31.    # Turn off LED  
    32.    GPIO.output(led1Pin, GPIO.LOW)  
    33.    GPIO.output(led2Pin, GPIO.LOW)  
    34.    # Release resource  
    35.    GPIO.cleanup()                       
    36.  
    37.# If run this script directly, do:  
    38.if __name__ == '__main__':  
    39.    setup()  
    40.    try:  
    41.        main()  
    42.    # When 'Ctrl+C' is pressed, the child program   
    43.    # destroy() will be  executed.  
    44.    except KeyboardInterrupt:  
    45.        destroy()      

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    11.    GPIO.setup(slidePin, GPIO.IN)  
    12.    GPIO.setup(led1Pin, GPIO.OUT, initial=GPIO.LOW)  
    13.    GPIO.setup(led2Pin, GPIO.OUT, initial=GPIO.LOW)  

Initialize the pin, then set the pin connected to 
slide switch to the input mode and LEDs to the output mode.

.. code-block::

    18.    if GPIO.input(slidePin) == 1:  
    19.            GPIO.output(led2Pin, GPIO.LOW)  
    20.            GPIO.output(led1Pin, GPIO.HIGH)  

When the slide is pulled to the left, the middle 
pin and left one are connected; 
the Raspberry Pi reads a high level at the middle pin, 
so the LED1 is on and LED2 off.

.. code-block::

    24.       if GPIO.input(slidePin) == 0:  
    25.            GPIO.output(led1Pin, GPIO.LOW)  
    26.            GPIO.output(led2Pin, GPIO.HIGH)  

When the slide is pulled to the right, the 
middle pin and right one are connected; the 
Raspberry Pi reads a low, so the LED2 is 
on and LED1 off.

**Phenomenon Picture**
-------------------------

.. image:: media_pi/image121.jpeg
    :width: 800
    :align: center
