# Projekt 1
| What?             | Done By       	 |
|----------         |-------------  	 |
| Program           |	Jobst + Hametner |
| Documentation     | Jobst + Hametner |
| Pair-Programming	|	Jobst + Hametner |

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

## Scenarios:
Dany favours cooking and to make it safer her boyfriend Jon installed a small wemos with 3 different sensors and 2 different actors.

#### Dany and Jon started the system:
Jon monitored the values which were sent by the different senosrs.

- Flame-Sensor:
	- The values of this sensor testify that there are no flames.
- Gas-Sensor:
	- The gas-sensor is sending nothing alarming.
- Button-Sensor:
	- Even if Jon presses the button, nothing will happen as ther is nothing to deactivate.

He also watched if the actors reacted correcty to the input values.

- LED-Actor:
	- As no sensor is sending any alarming values the LED is off.
- Buzzer-Actor:
	- As no sensor is sending any alarming values the Buzzer is off.

After Dany and Jon tested the sensors with no input action the wanted to try out if the gas-sensor is working correctly.

#### Dany and Jon breath on the gas-sensor:
They monitored the incoming values of the different sensors.

- Flame-Sensor:
	- The flame-sensor is sending nothing alarming, as there are no flames.
- Gas-Sensor:
	- After a while of breathing the gas-sensor sends a change of values.
- Button-Sensor:
	- If Jon or Dany press the Button the gas-sensor and the flame-sensor are deactivated. Furthermore the LED which was on should be turned back to off.

	They also monitored if the actors reacted correcty to the input values.

	- LED-Actor:
		- The LED is turned on to green as the gas-sensor is sensing alarming values.
	- Buzzer-Actor:
		- As the buzzer is only activated if the flame-sensor is sending alarming data, the buzzer won´t be turned on in this case.

After the gas-sensor was tested an verified Jon wanted to try the flame-sensor out. But he had a problem, as Dany and Jon don´t have a lighter or matches at home. So Jon took a flashlight and held it to the flame-sensor.

#### Jon and Dany test the flame-sensor:
In this case Jon monitored the incoming values of the different sensors, too.

- Flame-Sensor:
	- This sensor reacts to the torch and sends values which testify that there are flames.
- Gas-Sensor:
	- The gas-sensor is not sending anythin alarming.
- Button-Sensor:
	- If Jon or Dany press the Button the gas-sensor and the flame-sensor are deactivated. Furthermore the LED and the buzzer which were on should be turned back to off.

	The actors values were also watched by Jon and Dany.

	- LED-Actor:
		- The LED is turned on to red as the flame-sensor is sensing alarming values.
	- Buzzer-Actor:
		- The buzzer is aswell turned to on and it makes quite some noise.

After this Jon is happy as he knows that Dany want burn down the kitchen or there home during cooking.

## Possible Extensions:
- LED is Yellow notification to phone
- Temperatur-Sensor
