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

##### 20. Oktober 2017
- The internet in the FH was too bad
- To open the help enter "uhelp"


- Wired Button

###### Button
- button up: 1
- button down: 0

- Wired LED;
- Node_Red linked button event to LED event (to test)
  - button press:
    - LED green Pin: 255
    - LED red Pin: 0
  - button not pressed:
    - LED green Pin: 0
    - LED red Pin: 255

### UlnoIOT Part
- added a bunch of nodes for each sensor -> disregarded idea in order to have one for each arduino and add the sensors/actors to the autostart file
- added outside_node
  modified autostart.py of outside_node to:

    button("ulnoiotBTN", d0, 0, 1)
    led("ulnoiotLEDG", d2, "on", "off")
    led("ulnoiotLEDR", d1, "on", off)
    output("ulnoiotBUZZER", d5, "on", "off")
    run(10)

- The respective led-colours are turned on when the command "on" is received, turned off with the message "off"

- Now adding the other Arduino with the Gas-Sensor
- Initialize the Arduino with "USB1"
- Using pin A0 for Gas-Sensor -> analog-command in ulnoIOT transfers it to digital signal
- Now adding flame-sensor
- modified autostart.py of inside_node to:


    analog("ulnoiotGAS", precision=1, threshold=400)
    input("ulnoiotFLAME", d2, 1, 0)


- Trouble: Gas-sensor always sent 1 and flame-sensor always sent 1 aswell
  - Changing the threshold to 1.000 made the Gas-sensor send 0 -> means that I just have bad air in my room
  - Modified threshold back to 400
  - Holding a light near the Flame-sensor made the sensor send 0 -> means that I have used 1 and 0 at the wrong places and need to switch them

- Correct autostart.py for inside_node looks like:


    analog("ulnoiotGAS", precision=1, threshold=400)
    input("ulnoiotFLAME", d2, 0, 1)  


- Only thing left is adding the Buzzer to the pin D5
- But Buzzer is not sending a signal -> problem: not direct support in ulnoIOT -> looking for workaround
- Problem: Due to bad internet connection, testing can't be done
- In enclosed testing sessions the outside_node (except for buzzer) and the inside_node were working as expected
- Dropping buzzer for now

### node red Part
I (Magdalena Hametner) did the Node red part.

[old](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_1/node-red.txt)
[current](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Projects/Project_1/current.txt)
