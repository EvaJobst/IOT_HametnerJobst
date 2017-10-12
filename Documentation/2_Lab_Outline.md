# Lab Outline 2
## (3. Oct 2017)
mit Eva Jobst und Magdalena Hametner

- Eva: Code
- Magdalena: Doku, Setup (Arduino, Sensors)

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

- Magdalena: Doku, Setup (Arduino + Sensors)
- Eva: Code

ButtonPin = 10;
Button is a input;

Send HTTP Request in own method

in loop: check if value of Button changes

Button wired to Wemos D1 mini

not working ...

Blinking Led Program to test if network
--> works

Fingerprint deleted as we need this only in the HTTPS

ButtonPin = 2;

LED HIGH and LED LOW
- When led is low the HTTP Request should be sent

### LCD Display
- Magdalena: Code, Setup (Arduino, Sensors)
- Eva: User Stories, Dokumentation

- Installed Driver and Program for Arduino on Magdalena's Mac -> works
- Adding LCD Display to board; use of the extension board since we now have two pins that need a connection to the ground
- We changed the pin of the button, since we need it for the LCD
- Use of the example code ESP826612LCD; copying parts of it in the already modified HTTPSRequest
- Not working! We did not change the Pin for the Button in code
- Since the online resources weren't helping much --> trying possible inputs
- Problem was actually that pin D2 does not have a connection --> need to fix this in the next lesson

Currently: D2 -> not working; D3 -> SDA of LCD; D4 -> SCL; D1 -> Button-Signal
