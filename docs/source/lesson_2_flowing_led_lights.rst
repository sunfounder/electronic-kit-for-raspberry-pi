**Lesson 2 Flowing LED Lights**
=================================

**Introduction**
------------------

In this lesson, we will learn how to make eight LEDs blink as flowing
water based on Raspberry Pi.

**Newly Added Components**
-----------------------------

.. image:: media_pi/image200.png
    :width: 800
    :align: center

**Schematic Diagram**
-------------------------

In this experiment, connect **220Ω**\ resistors to the anode (the longer
pin of the LED) respectively, then the resistors to Pin **11, 12, 13,
15, 16, 18, 22** and **24** of Raspberry Pi, and connect the cathode
(the short pin) of the LEDs to **GND**. We can see from the schematic
diagram that the anode of LED connect to a current-limiting resistor and
then to Raspberry Pi. Therefore, to turn on an LED, we need to make pins
high level. This process can be realized by programming.

.. image:: media_pi/image201.png
    :width: 800
    :align: center

Build the Circuit
--------------------

.. image:: media_pi/image202.png
    :width: 800
    :align: center

**For C Language Users:**
--------------------------

**Command**
^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_2_FlowingLedLights

**2.** Compile the code.

.. code-block::

    gcc 2_FlowingLedLights.c -lwiringPi

.. note::

    When using the gcc command, if you do not use -o,
    it will automatically output as a.out.

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

Now, you will see these 8 LEDs are lit one by one from left
to right, and then one by one from right to left.

**Code**
^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>   
    2.#include <stdio.h>  
    3.  
    4.const int LedPin[]={0,1,2,3,4,5,6,10};   //Define 8 LED pin   
    5.  
    6.int main(void)  
    7.{  
    8.    // When initialize wiring failed, print message to screen  
    9.    if(wiringPiSetup() == -1){  
    10.        printf("setup wiringPi failed !");  
    11.        return 1;   
    12.    }  
    13.      
    14.    for(int j=0;j<8;j++)  
    15.    {  
    16.        pinMode(LedPin[j], OUTPUT);// Set LedPin as output to write value to it.  
    17.        digitalWrite(LedPin[j], LOW);  
    18.    }  
    19.      
    20.    while(1){  
    21.        for(int i=0;i<8;i++)  
    22.        {  
    23.            // LED on  
    24.            digitalWrite(LedPin[i], HIGH);                    
    25.            delay(100);            
    26.        }  
    27.        for(int i=7;i>-1;i--)  
    28.        {         
    29.            // LED off  
    30.            digitalWrite(LedPin[i], LOW);  
    31.            delay(100);  
    32.        }  
    33.    }  
    34.  
    35.    return 0;  
    36.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    4.const int LedPin[]={0,1,2,3,4,5,6,10}; 

Create an array, LedPin to define the eight LEDs then 
connect them to GPIO0~GPIO6, GPIO10 respectively.

.. code-block::

    14.    for(int j=0;j<8;j++)  
    15.    {  
    16.        pinMode(LedPin[j], OUTPUT); 
    17.        digitalWrite(LedPin[j], LOW);  
    18.    }  

Use a for loop to set all 8 pins connected 
to LEDs to OUTPUT mode and LOW level.

.. code-block::

    21.        for(int i=0;i<8;i++)  
    22.        {  
    23.            // LED on  
    24.            digitalWrite(LedPin[i], HIGH);                    
    25.            delay(100);           
    26.        }  

Light up the LEDs in GPIO0~6 and GPIO10 successively. 
i increases progressively from 0 to 7, LED0 to LED7 
changes accordingly, making it like a flowing LED light 
from left to right. 

.. code-block::

    27.        for(int i=7;i>-1;i--)  
    28.        {         
    29.            // LED off  
    30.            digitalWrite(LedPin[i], LOW);  
    31.            delay(100);  
    32.        }  

Close the LEDs in GPIO0~6 and GPIO10 successively. i 
increases progressively from 7 
to 0, LED0 to LED7 changes accordingly, 
making it like a flowing LED light from right to left. 

.. code-block::

**For Python Language Users:**
---------------------------------

**Command**
^^^^^^^^^^^^^^^^^

**1.** Go to the folder of the code

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

**2.** Run the code.

.. code-block::

    sudo python3 2_FlowingLed.py

Now, you will see these 8 LEDs are lit one by one from left to right,
and then one by one from right to left.

**Code**
^^^^^^^^^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO    
    2.import time     
    3.  
    4.pins = [17,18,27,22,23,24,25,8]  
    5.  
    6.# Define a setup function for some setup  
    7.def setup():  
    8.    GPIO.setmode(GPIO.BCM)     
    9.    for i in range(0, 8, 1):  
    10.        GPIO.setup(pins[i], GPIO.OUT, initial=GPIO.LOW)  
    11.  
    12.# Define a main function for main process  
    13.def main():  
    14.    while True:  
    15.        # print ('...LED ON')  
    16.        # Turn on LED  
    17.        for i in range(0, 8, 1):  
    18.            GPIO.output(pins[i], GPIO.HIGH)  
    19.            time.sleep(0.1)  
    20.             
    21.        # print ('LED OFF...')  
    22.        # Turn off LED  
    23.        for i in range(7, -1, -1):  
    24.            GPIO.output(pins[i], GPIO.LOW)  
    25.            time.sleep(0.1)  
    26.  
    27.# Define a destroy function for clean up everything after the script finished   
    28.def destroy():  
    29.    # Turn off LED     
    30.    for i in range(0, 8, 1):  
    31.            GPIO.output(pins[i], GPIO.LOW)  
    32.    # Release resource  
    33.    GPIO.cleanup()                      
    34.  
    35.# If run this script directly, do:  
    36.if __name__ == '__main__':  
    37.    setup()  
    38.    try:  
    39.        main()  
    40.    # When 'Ctrl+C' is pressed, the child program   
    41.    # destroy() will be  executed.  
    42.    except KeyboardInterrupt:  
    43.        destroy()  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    9.    for i in range(0, 8, 1):  
    10.        GPIO.setup(pins[i], GPIO.OUT, initial=GPIO.LOW)

Use a **for** loop to set all 8 pins connected to LEDs to output mode 
and LOW level.

.. code-block::

    17.        for i in range(0, 8, 1):  
    18.            GPIO.output(pins[i], GPIO.HIGH) 
    19. 			time.sleep(0.1)

Variable **i** increases progressively from **0** to **8**,
increasing by 1 every time. Accordingly, set the pins in the array
**pins[i]** to **HIGH** respectively to light up the LEDs and the
lighting time is **0.1**\ s. Then, you will see 8 LEDs light up one
by one.

.. code-block::

    23.        for i in range(7, -1, -1):  
    24.            GPIO.output(pins[i], GPIO.LOW)  
    25.            time.sleep(0.1)  

Variable **i** decreases progressively from **7** to **-1**,
decreasing by 1 every time. Then LED0~LED7 change accordingly, making
it like a flowing LED light from right to left.

**Phenomenon Picture**
-----------------------------

.. image:: media_pi/image203.png
    :width: 800
    :align: center
