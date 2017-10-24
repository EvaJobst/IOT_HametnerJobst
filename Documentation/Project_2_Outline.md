# Project 02 - Liquid Challenge

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

## Measurements
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

##### Average
|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |
|----|----|----|----|----|----|----|
| 0 | 6 cm | 0 cm |4 cm |10 cm | True | False |

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

##### Average
|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |
|----|----|----|----|----|----|----|
| 0 | 6 cm | 0 cm |4 cm |10 cm | True | False |

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

##### Average
|Nr.|Opt. Dist.|Acoust. Dist.| Opt. Height | Acoust. Height | Is Conductive | Is Full |
|----|----|----|----|----|----|----|
| 0 | 6 cm | 0 cm |4 cm |10 cm | True | False |
## Measure Water, Oil and Dirty Water


# Scale
##### 24. Oktober 2017

Arduino - Library hx711 install - open Example/.../calibrate

begin: 696 scale Factor
Sending 'l' from the serial terminal decrease factor by 1.0
      - Sending 'L' from the serial terminal decrease factor by 10.0
      - Sending 'h' from the serial terminal increase factor by 1.0
      - Sending 'H' from the serial terminal increase factor by 10.0
      - Sending 't' from the serial terminal call tare function

new scale Factor: 408.5

## Wasser:
4/10 Wassermenge --> 112g (Wasser + Glas)

--> Glas ohne Wasser --> 34g

78g Wasser bei 4/10 Wasserstand

78/4*10 = 195g max. Wassergewicht (Glas voll)

Gesamtgewicht: (100g - 34g)/195g*100 = 33,85%

## Öl

4/10 Ölmenge --> 107,5g (Öl + Glas)

Glas siehe oben

Öl allein: 107,5g-34g = 73,5g

volles Glas 73,5g/4*10 = 183,75g

Gesamtgewicht: (x - 34g)/183,75g*100
