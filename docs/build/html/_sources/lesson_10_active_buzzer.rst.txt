**Lesson 10 Active Buzzer**
==================================================

**Introduction**
----------------------

A buzzer is a great tool in your experiments whenever you want to make
sounds.

**Newly Added Components**
-----------------------------

.. image:: media_pi/image223.png
    :width: 800
    :align: center

**Principle**
------------------

As a type of electronic buzzer with an integrated structure, buzzers,
which are supplied by DC power, are widely used in computers, printers,
photocopiers, alarms, electronic toys, automotive electronic devices,
telephones, timers and other electronic products or voice devices.
Buzzers can be categorized as active and passive ones (see the following
picture). Turn the buzzer so that its pins are facing up, and the
buzzers with a green circuit board is a passive buzzer, while the one
enclosed with a black tape is an active one.

The difference between an active buzzer and a passive buzzer:

.. image:: media_pi/image139.png
    :width: 400
    :align: center

An active buzzer has a built-in oscillating source, so it will make
sounds when electrified. But a passive buzzer does not have such source,
so it will not tweet if DC signals are used; instead, you need to use
square waves whose frequency is between 2K and 5K to drive it. The
active buzzer is often more expensive than the passive one because of
multiple built-in oscillating circuits.

In this experiment, we use an active buzzer.

**Schematic Diagram**
--------------------------

When **Pin11** is input into high voltage, the transistor will be
switched on, and the collector will output low level. When there is a
level difference between the two pins of the buzzer, the buzzer is
ringing. When **Pin11** inputs low power level, the transistor is cut
off and the collector is at high level, here, both ends of the buzzer
are at high level, the buzzer will be silent.

.. image:: media_pi/image224.png
    :width: 800
    :align: center

**Build the Circuit**
------------------------

.. image:: media_pi/image141.png
    :width: 800
    :align: center

**For C Language Users**
---------------------------

**Command**
^^^^^^^^^^^^

1. Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_10_ActiveBuzzer

2. Compile the code.

.. code-block::

    gcc 10_ActiveBuzzer.c -lwiringPi

3. Run the executable file.

.. code-block::

    sudo ./a.out

Now, you may hear the buzzer beep.

**Code**
^^^^^^^^^^^


.. code-block::

    1.#include <wiringPi.h>  
    2.#include <stdio.h>  
    3.  
    4.#define BeepPin 0  
    5.  
    6.int main(void){  
    7.    if(wiringPiSetup() == -1){ //when initialize wiring failed, print message to screen  
    8.        printf("setup wiringPi failed !");  
    9.        return 1;   
    10.    }  
    11.      
    12.    pinMode(BeepPin, OUTPUT);     
    13.  
    14.    while(1){  
    15.        //beep on  
    16.        digitalWrite(BeepPin, HIGH);  
    17.        delay(100);  
    18.        //beep off  
    19.        digitalWrite(BeepPin, LOW);  
    20.        delay(100);  
    21.    }  
    22.    return 0;  
    23.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^

.. code-block::

 12.    pinMode(BeepPin, OUTPUT); 

Set the pin connected to the buzzer to OUTPUT mode.

.. code-block::

    16.        digitalWrite(BeepPin, HIGH);

When BeepPin is at high level, the base pin(b pin) of the 
connected transistor inputs high level and the collector pin(c pin) 
output low level. That is, when the cathode of the buzzer is at low 
level and the anode of the buzzer is connected to a 5V high 
level, the buzzer sounds.

.. code-block::

    19.        digitalWrite(BeepPin, LOW);

The BeepPin is connected to the transistor and then to the 
cathode of the buzzer. When BeepPin is low level, the base pin 
(b pin) of the connected transistor inputs low level, then the 
collector pin(c pin) outputs high level; that is, when the level 
at both ends of the connected buzzer is high, the buzzer is silent.

**For Python Language Users**
-------------------------------

**Command**
^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

**2.** Run the code.

.. code-block::

    sudo python3 10_ActiveBuzzer.py

Now, you should hear the buzzer beep.

**Code**
^^^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.import time  
    3.  
    4.BeepPin = 17  
    5.  
    6.def setup():  
    7.    GPIO.setmode(GPIO.BCM)  
    8.    GPIO.setup(BeepPin, GPIO.OUT, initial=GPIO.LOW)  
    9.  
    10.def main():  
    11.    while True:  
    12.        # Buzzer on (Beep)  
    13.        GPIO.output(BeepPin, GPIO.HIGH)  
    14.        time.sleep(0.1)  
    15.        # Buzzer off  
    16.        GPIO.output(BeepPin, GPIO.LOW)  
    17.        time.sleep(0.1)  
    18.  
    19.def destroy():  
    20.    # Turn off buzzer  
    21.    GPIO.output(BeepPin, GPIO.LOW)  
    22.    # Release resource  
    23.    GPIO.cleanup()      
    24.  
    25.# If run this script directly, do:  
    26.if __name__ == '__main__':  
    27.    setup()  
    28.    try:  
    29.        main()  
    30.    # When 'Ctrl+C' is pressed, the child program   
    31.    # destroy() will be  executed.  
    32.    except KeyboardInterrupt:  
            destroy() 

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    8.    GPIO.setup(BeepPin, GPIO.OUT, initial=GPIO.LOW) 

Initialize the pin connected to the buzzer to output 
mode and set it to the default low level.

.. code-block::

    13.        GPIO.output(BeepPin, GPIO.HIGH) 

The BeepPin is connected to the transistor and then to the cathode 
of the buzzer. When BeepPin is at high level, the base pin(b pin) 
of the connected transistor inputs high level, then the collector 
pin(c pin) outputs low level; that is, when the cathode of the 
buzzer is at low level and the anode of the buzzer is connected 
to a 5V high level, the buzzer sounds.

.. code-block::

    16.        GPIO.output(BeepPin, GPIO.LOW) 

When BeepPin is at low level, the base pin(b pin) of the connected 
transistor inputs low level, then the collector pin(c pin) outputs high 
level; that is, when the level at both ends of the connected buzzer 
is high, the buzzer is silent.

**Phenomenon Picture**
----------------------------

.. image:: media_pi/image142.jpeg
    :width: 800
    :align: center




