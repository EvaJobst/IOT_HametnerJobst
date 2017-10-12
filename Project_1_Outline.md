# Projekt 1
| What?             | Done By       |
|----------         |-------------  |
| Program           |	Jobst					|
| Documentation     | Hametner			|
| Pair-Programming	|	Jobst+Hametner|

We took the second of the [Userstories](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/3_User_Stories.md) and adopted it to the needs of the project.

For the project we need three different sensors and two different actors.

We choose the
- Flame-Sensor,
- Gas-Sensor and
- Button.

Our Actors are
- LED
- Active Buzza

First we needed to think of the ways how we could realize the userstory.

## Use Cases - LED:
- Green:
	- RGB: 0, 255, 0
	- Everything is ok.
	- only one or non sensor reacts
		- non sensor
	- Button click --> nothing happens
- Yellow:
	- RGB: 255, 255, 0
	- warning
	- Gas-Sensor reacts
	- Button click, to signal that everything is okay
- Red:
	- RGB: 255, 0, 0
	- attention!
	- Buzza recats
	- all tow sensors react
		- Flame-Sensor
		- Gas-Sensor
	- Button click, if it was a false alarm

### Jobst:

### Hametner:
I programmed in the Arduino. First I tried to configure a singel button press. I succeeded. Next I managed to turn on and off the LED and give different colors out.

## Possible Extensions:
- LED is Yellow notification to phone
- Temperatur-Sensor
