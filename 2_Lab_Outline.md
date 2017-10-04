# Lab Outline 2
## (3. Oct 2017)
mit Eva Jobst und Magdalena Hametner

IFTTT Notification event with webhook structed (Event: "notify_phone")

Notification set with text

If a specific event occurs, this notification is send.

Notification tested and worked

 File - Example - HTTPSRequest (event should occur when program is executed)
 - ssid altered to "HametnerJobst-da1885"
 - password altered to "HametnerJobst"
 - host altered to "maker.ifttt.com"
 -  url altered to "https://maker.ifttt.com/trigger/notify_phone/with/key/dpLOveXyj81hUdJ8GoGo6d"

We did not know what to use for the host.

## (4. Oct 2017)
ButtonPin = 10;
Button is a input;

Send HTTP Request in own method

in loop: check if value of Button changes

Button wired to Wemos D1 mini

not working ...

Blinking Led Program to test if network
--> works

Fingerprint deleted as we need this only in the HTTPS

File - Example - Button:
ButtonPin = 2;

LED HIGH and LED LOW
- When led is low the HTTP Request should be sent


# Todo:
Grundsätzlich Hello World wäre cool wenn Wetterservice auf Display eingebunden
