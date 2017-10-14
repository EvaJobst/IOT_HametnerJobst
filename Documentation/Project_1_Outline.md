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
- first we decided on the Active Buzza but during the coding we realized that we need the passive one

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

On the 14. Oct I started the next bit of work. I tried to program the gas-sensor. But firstly I totally failed. Than I looked the gas-sensor module thoroughly up on the interned. That was very tedious as I did not find anything which seems to help me.
After a while i found something and tried that out. It worked. The only trouble is that the gas-sensor always says that there is too much gas and i don´t know why.

Further i wanted to code the flame-sensor. That was easy as I immediately found something I could use. That was really easy after the gas sensor.

Firstly I thought that i needed to wired the gas-sensor and the flame-sensor to the same port on the Wemos (on the Analoge A0). But than I managed to wire the gas-sensor to the A0 (= Analog) and the flame-sensor to the D2 (= digital).

The last thing i wanted to code the active buzzer. But soon I realized that I needed to use the passive as the active one only played the different frequences and could not be truned off. I succeeded in coding the passive buzzer.

## Possible Extensions:
- LED is Yellow notification to phone
- Temperatur-Sensor
