# Portfolio von Eva Jobst
## Lecture
bitte noch selbst schreiben!!! :D
## Exercise
### [Lab Outline 1](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/1_Lab_Outline.md)
On the 2. October 2017 we worked on this lab outline. In this lesson we set up our Raspberry Pi 3. We also started to work with the Arduino IDE and built different programms.
- [Blink](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Lab_Outline/Blink/Blink.ino) is a program which lets the led on the Wemos D1 mini blink.
- [Button](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Lab_Outline/Button/Button.ino) is a program which lets the led on the Wemos D1 mini blink if a the wired button is clicked.

On the 3. October 2017 wrote a few more programms.
- [WifiWebServer](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Lab_Outline/WiFiWebServer/WiFiWebServer.ino) is a program which enables the user to turn on and of the led of the Wemos D1 mini if the user enters
  - http://192.168.12.213/LED=ON or
  - http://192.168.12.213/LED=OFF.

I programmed most of the time during this Lab Outline.

### [Lab Outline 2](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/2_Lab_Outline.md)
On  the 3. October 2017 we started with IFTTT and created a notification [event](https://maker.ifttt.com/trigger/notify_phone/with/key/dpLOveXyj81hUdJ8GoGo6d). We also tried to create a Programm [HTTPSRequestButton](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Lab_Outline/HTTPSRequest_Button/HTTPSRequest.ino), this program sends a request for the notification event, we have created earlier. This event is only requested when the wired Button is clicked.

We also created a programm ([HTTPSRequestLCD](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Lab_Outline/HTTPSRequest_LCD/HTTPSRequest.ino)) with the LCD Display. If the user clicks the wired button on the LCD Display shoud pop a pre-set message.

### [Lab Outline 3](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/3_Lab_Outline.md)
On the 10. October 2017 we worked on the programm [ESP8266I2CLCD](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Lab_Outline/ESP8266I2CLCD/ESP8266I2CLCD.ino). This program prints out installed CoAP plugin for Firefox.

Further we created the program [Temperatur_Simulator](https://github.com/EvaJobst/IOT_HametnerJobst/tree/master/Lab_Outline/Temperature_Simulation).
