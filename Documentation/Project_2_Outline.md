# Project 02 - Liquid Challenge

|Teammember|Work|
|----|----|
|Eva Jobst| all sensors but scale|
|Magdalena Hametner| scale sensor|


## Part 1 - Implement Sensors to measure Water and Oil
Goal: measuring liquid (water and oil) challenge (acoustic
distance, optical distance, weight, binary conductive sensing)

#### Pinout
|Sensor|Use Case|Pin|Details|
|----|----|----|----|
|HC-SR04|Acoustic Distance|Echo D4; Trigger D3|Code: ultrasonic_sensor.ino and 1_sensors.ino; Source: http://www.esp8266learning.com/wemos-mini-hc-sr04-ultrasonic-sensor.php; 3.3V|
|VL53L0X|Optical Distance|SDA D2; SCL D1|Code: distance_sensor.ino and 1_sensors.ino; Source: https://github.com/pololu/vl53l0x-arduino; 3.3V|
|Raindrop Sensor|Binary Conduction|D0|Code: rain_sensor.ino and 1_sensors.ino; Source: https://www.sunfounder.com/learn/Sensor-Kit-v2-0-for-Arduino/lesson-34-raindrop-detection-sensor-kit-v2-0-for-arduino.html; 3.3V|
|Reed Switch|Fullness of Container|D5|Code: 1_sensors.ino; Source: https://www.sunfounder.com/learn/Sensor-Kit-v2-0-for-Arduino/lesson-18-reed-switch-sensor-kit-v2-0-for-arduino.html|

#### Notes
- Trying to connect the Ultrasonic Sensor and have it print its values
- Failed -> unable to collect data from the echo
- Found library at RIOT -> will try to use that now  
- Included library -> can't find module 'machine' of library
  - Problem I can't find solution to -> even Internet unhelpful
- Dropping implementation with ulnoIoT -> switch to Arduino IDE
- The biggest problem was trying to find a workaround with ulnoIoT; once we decided to just use Arduino IDE setting up and printing the values was rather easy
- For the Acoustic, Optical and Binary Conductive Sensor fitting libraries and instructions were looked for and implemented -> Pinout table explains it into detail
- All three sensors work - now they are going to be put into one project
- No need for the Analog pin in the rain_sensor code anymore
- Problem: Serial-Monitor is outputting rubbish even though the Baudrate is the same
  - Serial.println("Acoustic Distance (cm): " + distance); -> rubbish
  - Serial.println('Acoustic Distance (cm): ', distance); -> just integer values -> probably ASCII
  - CORRECT FORMAT: Serial.print("Acoustic Distance (cm): "); Serial.print(distance);
- Delay of two seconds so we are not overwhelmed with values
- Acoustic uses cm and Optical uses mm -> need to convert
- Built system -> did test prints with water

>It's raining!
Optical Distance (cm): 17
Acoustic Distance (cm): 8

- Seem promising -> will finetune code now
- Values are now printed in Markdown table syntax

##### Water
|Nr.|Opt. Distance|Acoust. Distance| Opt. Height | Acoust. Height |Is Conductive|
|----|----|----|----|----|----|
| 0 | 10 | 0 |True |
| 1 | 10 | 4 |True |
| 2 | 9 | 5 |True |
| 3 | 10 | 5 |True |
| 4 | 10 | 0 |True |
| 5 | 10 | 5 |True |
| 6 | 8 | 0 |True |
| 7 | 9 | 0 |True |
| 8 | 10 | 0 |True |
| 9 | 8 | 5 |True |

##### Oil
|Nr.|Optical Distance|Acoustic Distance|Is Conductive|
|----|----|----|----|
| 67 | 14 | 6 |False |
| 68 | 13 | 5 |False |
| 69 | 12 | 5 |False |
| 70 | 13 | 5 |False |
| 71 | 13 | 5 |False |
| 72 | 13 | 5 |False |
| 73 | 13 | 5 |False |
| 74 | 13 | 5 |False |
| 75 | 13 | 5 |False |
| 76 | 13 | 5 |False |

- TODO: Add measurement that measures height of water through different methods -> Distance measuring and water sensoring
  - Container Height: 10cm
  - Liquid Height: 4cm
  - **Desired Result:** 6cm

- Adding Analog Pin to Arduino code + set up again
- Calibrating Raindrop Sensor, after how far the module is encapsulated by water:
  - 0%: ~977-1.023 (actual max. value is 1023)
  - 10%: 456, 420
  - 50%: ~350
  - 80%: 254, 264
  - 100%: 0
- Calibration according to Two-Point-Calibration, Source: https://learn.adafruit.com/calibrating-sensors/two-point-calibration
  - CorrectedValue = (((RawValue – RawLow) * ReferenceRange) / RawRange) + ReferenceLow
  - RawLow: 456, RawHigh 254, ReferenceHigh 264, ReferenceLow 420
  - ReferenceRange -> 264 - 420
  - RawRange -> 254 - 456

- **Sidenote:** Program is not uploading if the arduino and modules are not on the same level/plane

## Add Switch
- Switch is added according to the instructions from https://www.sunfounder.com/learn/Sensor-Kit-v2-0-for-Arduino/lesson-18-reed-switch-sensor-kit-v2-0-for-arduino.html
- Reed-Switch is functional but will only output "FALSE", since it does not swim in our setup and thus is not included

## Measure Water, Oil and Dirty Water
#### Water
|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |
|----|----|----|----|----|----|----|
| 0 | 6 cm | 0 cm |4 cm |10 cm | True | False |
| 1 | 5 cm | 4 cm |5 cm |6 cm | True | False |
| 2 | 6 cm | 0 cm |4 cm |10 cm | True | False |
| 3 | 5 cm | 5 cm |5 cm |5 cm | True | False |
| 4 | 5 cm | 0 cm |5 cm |10 cm | True | False |
| 5 | 5 cm | 5 cm |5 cm |5 cm | True | False |
| 6 | 5 cm | 0 cm |5 cm |10 cm | True | False |
| 7 | 6 cm | 5 cm |4 cm |5 cm | True | False |
| 8 | 5 cm | 0 cm |5 cm |10 cm | True | False |
| 9 | 6 cm | 5 cm |4 cm |5 cm | True | False |

#### Oil
|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |
|----|----|----|----|----|----|----|
| 0 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 1 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 2 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 3 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 4 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 5 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 6 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 7 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 8 | 9 cm | 0 cm |1 cm |10 cm | False | False |
| 9 | 10 cm | 0 cm |0 cm |10 cm | False | False |

#### Coca-Cola - "Dirty Water"
|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |
|----|----|----|----|----|----|----|
| 0 | 8 cm | 0 cm |2 cm |10 cm | True | False |
| 1 | 7 cm | 0 cm |3 cm |10 cm | True | False |
| 2 | 7 cm | 6 cm |3 cm |4 cm | True | False |
| 3 | 8 cm | 0 cm |2 cm |10 cm | True | False |
| 4 | 8 cm | 0 cm |2 cm |10 cm | True | False |
| 5 | 7 cm | 0 cm |3 cm |10 cm | True | False |
| 6 | 8 cm | 0 cm |2 cm |10 cm | True | False |
| 7 | 7 cm | 0 cm |3 cm |10 cm | True | False |
| 8 | 7 cm | 0 cm |3 cm |10 cm | True | False |
| 9 | 8 cm | 0 cm |2 cm |10 cm | True | False |

#### Conclusion
##### Average - Water:
|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height |
|----|----|----|----|
| 5,4 cm | 2,4 cm |4,6 cm |7,6 cm |

##### Average - Cola:
|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height |
|----|----|----|----|
| 7,5 cm | 0,6 cm |2,5 cm |9,4 cm |

##### Average - Oil:
|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height |
|----|----|----|----|
| 9,1 cm | 0 cm |0,9 cm |10 cm |

In conclusion the values we have got, as we measured the Water, are more accurate than the values of the other liquids.

The values of the liquides "Cola" and "Oil" are a bit odd. As for example the acoustic distance is 0 at "Average - Oil".

We think that the sensors do not work properly.

"Is Conductive" mean if the liquid is conductive or not and "Is Full" is always false as we only filled 4cm into the jar.

## Set up:
[Pic 1](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_2/pics/IMG_1026.JPG), [Pic 2](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_2/pics/IMG_1027.JPG), [Pic 3](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_2/pics/IMG_1028.JPG), [Pic 4](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_2/pics/IMG_1029.JPG), [Pic 5](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_2/pics/IMG_1030.JPG)

# Scale
##### 24. Oktober 2017
Arduino - Library hx711 install - open Example/HX711/calibrate

Start-Scale-Factor 696

put those letters into the serial monitor while calibrate run

| letter | increase & deacrease | what it does |
| ---- | ---- | ---- |
|L|decreas factor by 10.0|this reduces the scale-factor by 10.0 and so the return value of the scale increases|
|h|increase factor by 1.0|this reduces the scale-factor by 1.0 and so the return value of the scale decreases|
|H|increase factor by 1.0|this reduces the scale-factor by 10.0 and so the return value of the scale decreases|
|t|call tare function|-|

new Scale-Factor: 408.5

## Water:
- Water-amount: 4/10 of the jar
- water + jar: 4/10 water-amount = 112g
- jar + without water: 34g
- water: 112g-34g = 78g
- jar filled: 78g/4*100 = 195g
- whole weight: (100g-34g)/195g*100 = 33,85%

## Oil:
- Oil-amount: 4/10 of the jar
- oil + jar: 4/10 oil-amount = 107,5g
- jar + without oil: 34g
- oil: 107,5g-34g = 73,5g
- jar filled: 73,5g/4*10 = 183,75g
- whole weight: (x-34g)/183,75g*100
