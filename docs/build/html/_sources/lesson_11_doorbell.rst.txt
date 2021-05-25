**Lesson 11 Doorbell**
======================

**Introduction**
--------------------

In this lesson, we will learn how to drive an active buzzer to build a
simple doorbell.

**Newly Added Components**
----------------------------------

.. image:: media_pi/image225.png
    :width: 800
    :align: center

**Schematic Diagram**
----------------------------

When the button is pressed, **Pin13** is connected to the **5V** power
supply and reads out high level; therefore, the program responds to make
**Pin11** output the high level so as to energize the transistor, and
the collector will output low level that means the buzzer rings. When
pin11 outputs at low level the buzzer will be silent.

.. image:: media_pi/image226.png
    :width: 800
    :align: center

.. image:: media_pi/image255.png
    :width: 800
    :align: center

**Build the Circuit**
---------------------------

.. note::
     Long pins of buzzer is the Anode and the short pin is Cathode.

.. image:: media_pi/image144.png
    :width: 800
    :align: center

**For C Language Users**
----------------------------

**Command**
^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_11_DoorBell

**2.** Compile the code.

.. code-block::

    gcc 11_DoorBell.c -lwiringPi

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

When the button is pressed, the buzzer makes a 
sound to simulate a doorbell.

**Code**
^^^^^^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>  
    2.#include <stdio.h>  
    3.  
    4.#define BeepPin 0  
    5.#define ButtonPin   2  
    6.  
    7.int main(void){  
    8.    if(wiringPiSetup() == -1){ //when initialize wiring failed, print message to screen  
    9.        printf("setup wiringPi failed !");  
    10.        return 1;   
    11.    }  
    12.      
    13.    pinMode(BeepPin, OUTPUT);     
    14.    pinMode(ButtonPin, INPUT);  
    15.    pullUpDnControl(ButtonPin, PUD_DOWN);  
    16.  
    17.    while(1){  
    18.        // Indicate that button has pressed down  
    19.        if(digitalRead(ButtonPin) == 1){  
    20.            delay(10);  
    21.            if(digitalRead(ButtonPin) == 1){  
    22.            //beep on  
    23.            printf("Buzzer on\n");  
    24.            digitalWrite(BeepPin, HIGH);  
    25.            delay(100);  
    26.            }  
    27.        }  
    28.        else{  
    29.            printf("Buzzer off\n");  
    30.            //beep off  
    31.            digitalWrite(BeepPin, LOW);  
    32.            delay(100);  
    33.        }         
    34.    }  
    35.    return 0;  
    36.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    20.            delay(10); 

Software removes button jitter. When the signal that the 
button is pressed is detected, a delay of 10ms is used to 
eliminate the possibility of false judgment. If both if conditions 
are met, confirm that the button is pressed, and then execute the program in if.

.. code-block::

    21.            if(digitalRead(ButtonPin) == 1){  
    22.            //beep on  
    23.            printf("Buzzer on\n");  
    24.            digitalWrite(BeepPin, HIGH);  
    25.            delay(100);  
    26.            }  

If the button is recognized to be pressed, the BeepPin is 
at high level. The base pin(b pin) of the connected 
transistor inputs high level, while the collector pin(c pin) 
outputs low level. That is, the cathode of buzzer is at low 
level, and the anode is connected with a high level 5V. Then the 
buzzer rings. 

.. code-block::

    28.        else{  
    29.            printf("Buzzer off\n");  
    30.            //beep off  
    31.            digitalWrite(BeepPin, LOW);  
    32.            delay(100);  
    33.        }   

Otherwise, BeepPin is at low level, and the base pin(b pin) 
of the connected transistor inputs low level, then the collector 
pin(c pin) outputs high level; that is, the level at both ends 
of the buzzer is high, and the buzzer does not ring.

**For Python Language Users**
----------------------------------

**Command**
^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python


**2.** Run the code.

.. code-block::

    sudo python3 11_DoorBell.py

When the button is pressed, the buzzer makes a sound to simulate a
doorbell.

**Code**
^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.import time  
    3.  
    4.BeepPin = 17  
    5.BtnPin = 27  
    6.  
    7.def setup():  
    8.    GPIO.setmode(GPIO.BCM)  
    9.    GPIO.setup(BtnPin, GPIO.IN)  
    10.    GPIO.setup(BeepPin, GPIO.OUT, initial=GPIO.LOW)  
    11.      
    12.def main():  
    13.    while True:  
    14.        if GPIO.input(BtnPin) == 0:  
    15.            #Buzzer off  
    16.            print ('Buzzer Off')  
    17.            GPIO.output(BeepPin, GPIO.LOW)  
    18.            time.sleep(0.1)  
    19.        if GPIO.input(BtnPin) == 1:  
    20.            #Buzzer on  
    21.            print ('Buzzer On')  
    22.            GPIO.output(BeepPin, GPIO.HIGH)  
    23.            time.sleep(0.1)  
    24.  
    25.def destroy():  
    26.    # Turn off buzzer  
    27.    GPIO.output(BeepPin, GPIO.LOW)  
    28.    # Release resource  
    29.    GPIO.cleanup()      
    30.  
    31.# If run this script directly, do:  
    32.if __name__ == '__main__':  
    33.    setup()  
    34.    try:  
    35.        main()  
    36.    # When 'Ctrl+C' is pressed, the child program   
    37.    # destroy() will be  executed.  
    38.    except KeyboardInterrupt:  
            destroy() 

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    14.        if GPIO.input(BtnPin) == 0:  
    15.            #Buzzer off   
    16.            print ('Buzzer Off')  
    17.            GPIO.output(BeepPin, GPIO.LOW)  
    18.            time.sleep(0.1)  

If it is judged that the button is not pressed, BeepPin is 
at low level, and the base pin(b pin) of the connected transistor 
inputs low level, then the collector pin(c pin) outputs high level; 
that is, when the level at both ends of the connected buzzer is high, 
the buzzer does not ring.

.. code-block::

    19.        if GPIO.input(BtnPin) == 1:  
    20.            #Buzzer off  
    21.            print ('Buzzer On')  
    22.            GPIO.output(BeepPin, GPIO.HIGH)  
    23.             time.sleep(0.1)

If the button is recognized to be pressed, the BeepPin is at high level. 
The base pin(b pin) of the connected transistor inputs high level, while the 
collector pin(c pin) outputs low level. That is, the cathode of buzzer is at 
low level, and the anode is connected with a high level 5V. Then the buzzer rings. 

**Phenomenon Picture**
-------------------------------

.. image:: media_pi/image145.jpeg
    :width: 800
    :align: center

