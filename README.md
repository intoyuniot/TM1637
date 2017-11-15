TM1637
======
Arduino / Spark Core library for TM1637 (LED Driver)

Adapted for IntoRobot by Robin, Sept 19, 2015

Description
-----------
This is an upgraded version from an arduino library to work as well with the spark core from Particle.

An Arduino library for 7-segment display modules based on the TM1637 chip, such as Seeed Studio's [Grove 4 digit display](http://www.seeedstudio.com/depot/grove-4digit-display-p-1198.html). The TM1637 chip also has keyboard input capability, but it's not implemented in this library.

Hardware Connection
-------------------
The display modules has two signal connection (and two power connections) which are CLK and DIO. These pins can be connected to any pair of digital pins on the Arduino. When an object is created, the pins should be configured. There is no limitaion on the number of instances used concurrently (as long as each instance has a pin pair of its own)

Installation
------------
The library is installed as any Arduino library, by copying the files into a directory on the library search path of the Arduino IDE.

For Spark core just contribute in library this repository or include in app.

Usage
-----
The library provides a single class named TM1637Display. An instance of this class provides the following functions:

* `setSegments` - Sets the raw value of the segments of each digit
* `showNumberDec` - Displays a decimal number
* `setBrightness` - Sets the brightness of the display

The information given above is only a summary. Please refer to TM1637Display.h for more information. An example is included, demonstarting the operation of most of the functions.
