**Lesson 9 4N35**
=====================

**Introduction**
--------------------

In this lesson, let's learn the operational principle of 4N35 chip. We
analyze the principle in this way: using 4N35 chip to drive a LED, and
then explaining the phenomenon of LED and the internal structure of the
chip.

**Newly Added Components**
-------------------------------

.. image:: media_pi/image220.png
    :width: 800
    :align: center

**Principle**
-----------------

4N35

4N35 is a general-purpose optocoupler. It consists of gallium arsenide
infrared LED and a silicon NPN phototransistor. What an optocoupler does
is to break the connection between signal source and signal receiver, so
as to stop electrical interference. 4N35 can be used in AV conversion
audio circuits that is widely used in electrical isolation of a general
optocoupler.

.. image:: media_pi/image221.png
    :width: 800
    :align: center

See the internal structure of the 4N35 above. Pin 1 and 2 are connected
to an infrared LED. When the LED is electrified, it'll emit infrared
rays. To protect the LED from burning, usually a resistor (about 1K) is
connected to pin 1. Then the NPN phototransistor is power on when
receiving the rays, and then it can control the load connected to the
phototransistor. Even when the load short circuit occurs, it won't
affect the control board, thus realizing good electrical isolation.

**Schematic Diagram**
---------------------------

In this experiment, use an LED as the load connected to the NPN
phototransistor. In program, a LOW level is given to **Pin 11**, then
the infrared LED will emit infrared rays. After that, the
phototransistor receives infrared rays and gets electrified, and the LED
cathode is LOW, thus turning on the LED.

.. image:: media_pi/image222.png
    :width: 800
    :align: center

**Build the Circuit**
-------------------------

.. note:: 
    pay attention to the direction of the chip by the concave on it.

.. image:: media_pi/image136.png
    :width: 800
    :align: center

**For C Language Users**
-------------------------

**Command**
--------------------

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_9_4N35

**2.** Compile the code.

.. code-block::

    gcc 9_4N35.c -lwiringPi

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

You will see the LED blinking.

**Code**
^^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>     
    2.#include <stdio.h>  
    3.  
    4.#define OptoPin  0  
    5.  
    6.int main(void)  
    7.{  
    8.    // When initialize wiring failed, print message to screen  
    9.    if(wiringPiSetup() == -1){  
    10.        printf("setup wiringPi failed !");  
    11.        return 1;   
    12.    }  
    13.      
    14.    pinMode(OptoPin,OUTPUT);  
    15.      
    16.    while(1){  
    17.        // Turn LED off  
    18.        digitalWrite(OptoPin, HIGH);  
    19.        delay(500);  
    20.        // Turn LED on  
    21.        digitalWrite(OptoPin, LOW);  
    22.        delay(500);  
    23.    }  
    24.    return 0;  
    25.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    14.    pinMode(OptoPin,OUTPUT);

Initialize pins. Set the output pin of 4N35, 
Optopin to OUTPUT mode.

.. code-block::

    18.        digitalWrite(OptoPin, HIGH);

Set OptoPin as LOW (0V), thus the optocoupler is energized, 
and the pin connected to LED conduct to low level. 
Then the LED will light up. 

.. code-block::

    21.        digitalWrite(OptoPin, LOW); 

Set OptoPin as HIGH (3.3V), thus the optocoupler is not 
energized, and the pin connected to LED cannot conduct to 
low level. Then the LED goes out. 

**For Python Language Users**
------------------------------

**Command**
^^^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

**2.** Run the code.

.. code-block::

    sudo python3 9_4N35.py

You will see the LED blinking.

**Code**
^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.import time  
    3.  
    4.Pin_4N35 = 17  
    5.  
    6.# Define a setup function for some setup  
    7.def setup():  
    8.    GPIO.setmode(GPIO.BCM)  
    9.    GPIO.setup(Pin_4N35, GPIO.OUT, initial=GPIO.LOW)  
    10.  
    11.# Define a main function for main process  
    12.def main():  
    13.    while True:  
    14.        # Turn off LED  
    15.        GPIO.output(Pin_4N35, GPIO.HIGH)  
    16.        time.sleep(0.5)  
    17.        # Turn on LED  
    18.        GPIO.output(Pin_4N35, GPIO.LOW)   
    19.        time.sleep(0.5)  
    20.  
    21.def destroy():  
    22.    # Turn off LED  
    23.    GPIO.output(Pin_4N35, GPIO.HIGH)  
    24.    # Release resource  
    25.    GPIO.cleanup()                       
    26.  
    27.# If run this script directly, do:  
    28.if __name__ == '__main__':  
    29.    setup()  
    30.    try:  
    31.        main()  
    32.    # When 'Ctrl+C' is pressed, the child program   
    33.    # destroy() will be  executed.  
    34.    except KeyboardInterrupt:  
    35.        destroy()  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    15.        GPIO.output(Pin_4N35, GPIO.HIGH)

Set OptoPin as high level (3.3V), 
thus the optocoupler is not energized, 
and the pin connected to LED cannot conduct 
to low level. Then the LED goes out.

.. code-block::

    16.        time.sleep(0.5)

Wait for 0.5 second. The on-off frequency of the optocoupler 
can be changed by modifying this parameter.

.. code-block::

    18.        GPIO.output(Pin_4N35, GPIO.LOW)

Set OptoPin as low level (0V), thus the optocoupler is energized, 
and the pin connected to LED conduct to low level. 
Then the LED will light up.

**Phenomenon Picture**
--------------------------

.. image:: media_pi/image137.jpeg
    :width: 800
    :align: center

