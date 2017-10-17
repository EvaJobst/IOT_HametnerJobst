# Lab Outline 5
##### 16. October 2017
with Magdalena Hametner and Eva Jobst

##### Node-RED

| Exercise                | Done By           |
|----------               |-------------      |
| Code                    | Jobst             |
| Documentation           | Hametner          |

Youtube - ulno.net --> Tutorial

## Ulnoiot:
open terminal or gitBash
- enter ssh ulnoiotgw -l pi -> F2
  - cd ulnoiot
  - git pull
  - fix_bin
  - ulnoiot upgrade
  - mc -x

 We had troubles with the file system!

## Youtube - Tutorial:
- Current workflow: Getting to know Ulnoiot, while listening to the tutorial and performing the tasks (setting up LED and button) side-by-side.
  - Copied system_template to the tmp folder
  - Renamed system_template -> project01
  - Dublicated node_template and renamed them to "button" and "led"
  - Deleted key.hex
  - Adapted system.conf to current network
  - Changed README
  - in directors "button" -> wrote "initialize" in console in order to flash the button to the Arduino
  - "console_serial" opens the serial connection to the USB
  - button("btn1", d3)
  - check for connected devices with command "devices"
  - run()
  - button("btn1", d3, "down", "up")
  - go to LED folder and "initialize" it: IMPORTANT -> need to initialize with a USB-parameter -> USB1 in this case
  - Edit autostart.py in button/files/autostart.py
    - import is needed for the ulnoiot-stuff!
    - add button("btn1", d3, "down", "up")
    - add run(0)
  - "deploy" in the parent-directory starts all autostart.py; in the node-directory only of the node
  - "deploy noupdate"

##### 17. Oktober 2017
- 2x Wemos D1 mini wired to Raspberry Pi
- PC: login Ulnoiot
- Viewer-UI for Raspberry

We have one internal (= USB1) WEMOS and one external (= USB0) WEMOS.

On the internal we wired: <kurzes Kabel>
- gas-sensor (Pin A0)
- flame-sensor (Pin D2)

On the extrernal we wirde: <langes Kabel>
- button-sensor (Pin D3)
- LED-actor (Pin-Green D7, Pin-Red D8)
- buzzer-actor (Pin D5)

###### We had troubles with the button-sensor.
- disconnected the LED-actor and the buzzer-actor
- tried to make a button press

###### Would be solution:
- We were on the wrong WEMOS (internal).
- with "initialize USB1" we changed to the external WEMOS.

###### Problem
- WEMOS couldn´t connect to Wifi
- Tried other cable
