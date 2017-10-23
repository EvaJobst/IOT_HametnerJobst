# Project 02 - Liquid Challenge

## Part 1 - Implement Sensors to measure Water and Oil
Goal: measuring liquid (water and oil) challenge (acoustic
distance, optical distance, weight, binary conductive sensing)

#### Pinout
|Sensor|Use Case|Pin|Details|
|----|----|----|----|
|HC-SR04|Acoustic Distance|Echo D4; Trigger D3|Code: ultrasonic_sensor.ino; Source: http://www.esp8266learning.com/wemos-mini-hc-sr04-ultrasonic-sensor.php; 3.3V|
|VL53L0X|Optical Distance|SDA D2; SCL D1|Code: Continuous.ino; Source: https://github.com/pololu/vl53l0x-arduino; 3.3V|
|Raindrop Sensor|Binary Conduction|D0|Code: rain_sensor.ino; Source: https://www.sunfounder.com/learn/Sensor-Kit-v2-0-for-Arduino/lesson-34-raindrop-detection-sensor-kit-v2-0-for-arduino.html; 3.3V|

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

## Add Switches and measure Water and Oil

## Measure Water, Oil and Dirty Water
