**Lesson 13 Button Piano**
============================

**Introduction**
-----------------

In our past lesson, we learned how to use PWM waves to drive a passive
buzzer to ring. In this lesson, we make a simple keyboard by applying a
passive buzzer. Let's get started!

**Newly Added Components**
---------------------------

.. image:: media_pi/image229.png
    :width: 800
    :align: center

**Schematic Diagram**
---------------------------

.. image:: media_pi/image230.png
    :width: 800
    :align: center

.. image:: media_pi/image257.png
    :width: 800
    :align: center

**Build the Circuit**
-------------------------

.. image:: media_pi/image231.png
    :width: 400
    :align: center

.. image:: media_pi/image150.png
    :width: 400
    :align: center

**For C Language Users**
----------------------------

**Command**
^^^^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/c/Lesson_13_Button_Piano

**2.** Compile the code.

.. code-block::

    gcc 13_ButtonPiano.c -lwiringPi

**3.** Run the executable file.

.. code-block::

    sudo ./a.out

Now press the seven buttons, and the buzzer will emit the notes: DO, RE,
MI, FA, SO, LA, TI. You can play a song with these seven buttons.

**Code**
^^^^^^^^^^^

.. code-block::

    1.#include <wiringPi.h>  
    2.#include <softTone.h>  
    3.#include <stdio.h>  
    4.  
    5.#define BuzPin    0  
    6.  
    7.const int Tone[] = {262,294,330,350,393,441,495};//define DO, RE, MI, FA, SO, LA, TI  
    8.int beat[] = {1,1,1,1,1,1,1};  
    9.const int Btn[] = {2,3,4,5,6,10,11};//define 7 buttons  
    10.  
    11.int main(void)  
    12.{  
    13.    int i, j;  
    14.  
    15.    if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen  
    16.        printf("setup wiringPi failed !");  
    17.        return 1;   
    18.    }  
    19.  
    20.    if(softToneCreate(BuzPin) == -1){  
    21.        printf("setup softTone failed !");  
    22.        return 1;   
    23.    }  
    24.  
    25.    //set the buttons mode  
    26.    for(int j=0;j<7;j++)  
    27.    {  
    28.        pinMode(Btn[j], INPUT);  
    29.    }  
    30.          
    31.    while(1){  
    32.        //printf("Please press button to play the piano\n");  
    33.        // Indicate that button has pressed down      
    34.        for(i=0;i<7;i++)  
    35.        {  
    36.            if(digitalRead(Btn[i])==1)  
    37.            {  
    38.                delay(10);//Prevent the button' s vibration  
    39.                if(digitalRead(Btn[i])==1)  
    40.                {  
    41.                    softToneWrite(BuzPin, Tone[i]);   
    42.                    delay(beat[i]*250);  
    43.                    printf("1");  
    44.                }  
    45.            }  
    46.            else  
    47.            softToneWrite(BuzPin, 0);  
    48.            if(i==7)  
    49.            i=0;  
    50.        }             
    51.    }  
    52.    return 0;  
    53.}  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    7.  const int Tone[] = {262,294,330,350,393,441,495}; 
    8.  int beat[] = {1,1,1,1,1,1,1};  

In the array Tone[], define the frequencies of DO, RE, MI, FA, SO, LA, TI 
and the number in beat[] refers to the beat of each note in this song(0.5s for each beat).

.. code-block::

    26.  for(int j=0;j<7;j++)  
    27.    {  
    28.        pinMode(Btn[j], INPUT);  
    29.    }  

Set the mode of all buttons to input mode in the for loop.

.. code-block::

    34.        for(i=0;i<7;i++)  
    35.        {  
    36.            if(digitalRead(Btn[i])==1)  
    37.            {  
    38.                delay(10);//Prevent the button' s vibration  
    39.                if(digitalRead(Btn[i])==1)  
    40.                {  
    41.                    softToneWrite(BuzPin, Tone[i]);   
    42.                    delay(beat[i]*250);  
    43.                    printf("1");  
    44.                }  
    45.            }  

Use a for loop to check all the buttons. When one button in array Btn[i] 
is detected to be pressed, the buzzer will respond to the corresponding note in array Tone[i].

.. code-block::

    46.            else  
    47.            softToneWrite(BuzPin, 0);  
    48.            if(i==7)  
    49.            i=0;  
    50.            }

If no button is pressed, turn off the buzzer.

**For Python Language Users**
-------------------------------

**Command**
^^^^^^^^^^^^^

**1.** Go to the folder of the code.

.. code-block::

    cd /home/pi/electronic-kit/for-raspberry-pi/python

**2.** Run the code.

.. code-block::

    sudo python3 13_ButtonPiano.py

Now press the seven buttons, and the buzzer will emit the notes: DO, RE,
MI, FA, SO, LA, TI. You can play a song with these seven buttons.

**Code**
^^^^^^^^^^^

.. code-block::

    1.import RPi.GPIO as GPIO  
    2.import time  
    3.  
    4.Buzzer = 17  
    5.BtnPin = [18,27,22,23,24,25,8,7]  
    6.  
    7.CL = [0, 131, 147, 165, 175, 196, 211, 248]        # Frequency of Low C notes  
    8.CM = [0, 262, 294, 330, 350, 393, 441, 495]        # Frequency of Middle C notes  
    9.CH = [1, 525, 589, 661, 700, 786, 882, 990]        # Frequency of High C notes  
    10.  
    11.song = [     0,CM[1],CM[2],CM[3],CM[4],CM[5],CM[6],CM[7]    ]  
    12.beat = [    1,1, 1, 1, 1, 1, 1,  1]  
    13.  
    14.def setup():  
    15.    GPIO.setmode(GPIO.BCM)          
    16.    for i in range(1, len(BtnPin)):  
    17.        GPIO.setup(BtnPin[i],GPIO.IN)  
    18.    GPIO.setup(Buzzer, GPIO.OUT)      
    19.  
    20.def loop():  
    21.    global Buzz    
    22.    while True:  
    23.        #print ('\n    Please playing piano...')  
    24.        for i in range(1, len(BtnPin)):          
    25.            if GPIO.input(BtnPin[i]) == 1:  
    26.                Buzz = GPIO.PWM(Buzzer, song[i])      
    27.                Buzz.start(50)  
    28.                time.sleep(beat[i] * 0.25)          
    29.                Buzz.stop()      
    30.                     
    31.def destory():  
    32.    Buzz.stop()                      
    33.    GPIO.output(Buzzer, 0)          
    34.    GPIO.cleanup()                  
    35.  
    36.if __name__ == '__main__':        # Program start from here  
    37.    setup()  
    38.    try:  
    39.        loop()  
    40.    except KeyboardInterrupt:      # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.  
    41.        destory()  

**Code Explanation**
^^^^^^^^^^^^^^^^^^^^^^^

.. code-block::

    7.CL = [0, 131, 147, 165, 175, 196, 211, 248]        # Frequency of Low C notes  
    8.CM = [0, 262, 294, 330, 350, 393, 441, 495]        # Frequency of Middle C notes  
    9.CH = [1, 525, 589, 661, 700, 786, 882, 990]        # Frequency of High C notes  

These are the frequencies of each note. The first 0 is to skip CL[0] so that the 
number CL[1]-CL[7] corresponds to the CDEFGAB of the note.

.. code-block::

    10.song = [     0,CM[1],CM[2],CM[3],CM[4],CM[5],CM[6],CM[7]    ]  
    11.beat = [    1,1, 1, 1, 1, 1, 1,  1]  

Define a section of music and the corresponding beats. The number in beat[] 
refers to the beat of each note in the song(0.5s for each beat).

.. code-block::

    16.   for i in range(1, len(BtnPin)):  
    17.        GPIO.setup(BtnPin[i],GPIO.IN)  

Set the mode of all buttons to input mode in the for loop.

.. code-block::

    24.        for i in range(1, len(BtnPin)):       
    25.            if GPIO.input(BtnPin[i]) == 1:  
    26.                Buzz = GPIO.PWM(Buzzer, song[i])      
    27.                Buzz.start(50)  
    28.                time.sleep(beat[i] * 0.25)       
    29.                Buzz.stop()  

Use a for loop to check all the buttons. When one button in array button[i] 
is detected to be pressed, the buzzer will respond to 
the corresponding note in array song[i].

**Phenomenon Picture**
-------------------------

.. image:: media_pi/image151.jpeg
    :width: 800
    :align: center
