# Lab Outline 3
##### (10. October 2017)
with Magdalena Hametner and Eva Jobst

| Exercise                | Done By           |
|----------               |-------------      |
| Code                    | Hametner          |
| Documentation           | Jobst             |
| Setup Arduino + Sensors | Hametner + Jobst  |

- Demo Time: Showing that the Arduino and program works

##### Install simple CoAP Arduino example
- Copper is not supported at Firefix Version 56, need to downgrade to 55
- Following instructions from: http://wiznetmuseum.com/portfolio-items/coap-using-the-arduino-and-firefox-plugin/
- Dropped it; Trying out library from https://github.com/automote/ESP-CoAP
- Using 192.168.12.213 now as CoAP IP
- Wrong Wifi -> need to be in the Raspberry Wifi
- Using client-example -> Mistake: need to use server-example
- In the browser in the "Outgoing" field messages can be posted, that are processed in the "callback_light()" method of the server-file
- Adapting code so it switches on/off the LED of the Arduino
- It works -> though 0 is ON and 1 is off
- Changed code so on message "0" LED switches ON and on message "1" LED switches OFF

##### Build simulators for MQTT
- mqtt_all

##### (11. October 2017)
with Eva Jobst and Magdalena Hametner

| Exercise                | Done By           |
|----------               |-------------      |
| Code                    |  Jobst            |
| ||
| Documentation           |  Hametner         |
| Setup Arduino + Sensors | Hametner + Jobst  |
