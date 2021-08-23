Libraries
====================

Two important libraries are used in programming with Raspberry Pi, and
they are wiringPi and RPi.GPIO. The Raspbian OS image of Raspberry Pi
installs them by default, so you can use them directly.

RPi.GPIO
----------------

If you are a Python user, you can program GPIOs with API provided by
RPi.GPIO.

RPi.GPIO is a module to control Raspberry Pi GPIO channels. This package
provides a class to control the GPIO on a Raspberry Pi. For examples and
documents, visit
http://sourceforge.net/p/raspberry-gpio-python/wiki/Home/.

Test whether RPi.GPIO is installed or not, type in python:

.. raw:: html

    <run></run>

.. code-block::

    python

.. image:: media_pi/image49.png
    :width: 800
    :align: center

In Python CLI, input \"**import RPi.GPIO**\", if no error prompts, it
means RPi.GPIO is installed.

.. raw:: html

    <run></run>

.. code-block::

    import RPi.GPIO

.. image:: media_pi/image50.png
    :width: 800
    :align: center

If you want to quit python CLI, type in:

.. raw:: html

    <run></run>

.. code-block::

    exit()

WiringPi 
--------------

wiringPi is a C language GPIO library applied to the Raspberry Pi
platform. It complies with GUN Lv3. The functions in wiringPi are
similar to those in the wiring system of Arduino. They enable the users
familiar with Arduino to use wiringPi more easily.

wiringPi includes lots of GPIO commands which enable you to control all
kinds of interfaces on Raspberry Pi. You can test whether the wiringPi
library is installed successfully or not by the following instructions.

.. raw:: html

    <run></run>

.. code-block::

    gpio -v

.. image:: media_pi/image51.png

If you are using Raspberry Pi 4B, but the GPIO version is **2.50**, it
will cause no response after the C language code is running, that is,
GPIO pins do not work. At this time, you need to manually update to
version **2.52**, the update steps are as follows :

.. raw:: html

    <run></run>

.. code-block::

    cd /tmp

    wget https://project-downloads.drogon.net/wiringpi-latest.deb

    sudo dpkg -i wiringpi-latest.deb

Check with:

.. raw:: html

    <run></run>

.. code-block::

    gpio -v

and make sure it’s version 2.52.

.. raw:: html

    <run></run>

.. code-block::

    gpio readall

.. image:: media_pi/image52.png
    :width: 800
    :align: center

For more details about wiringPi, you can refer to:
http://wiringpi.com/download-and-install/.

