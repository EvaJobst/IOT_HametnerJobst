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

// NODE-RED - fertig machen
< [{"id":"d311091a.41ebe","type":"tab","label":"Ulnoiot_Project","disabled":false,"info":""},{"id":"8d52d8fb.fc07d","type":"mqtt in","z":"d311091a.41ebe","name":"Button Subscriber","topic":"outside_node/ulonoiotBTN","qos":"0","broker":"65997223.341d04","x":95,"y":40,"wires":[["631c8495.a66dcc"]]},{"id":"631c8495.a66dcc","type":"switch","z":"d311091a.41ebe","name":"switch BTN","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"},{"t":"eq","v":"1","vt":"str"}],"checkall":"true","outputs":2,"x":291,"y":40,"wires":[["bcb6d7ff.1fcee","a0318962.8a74e8"],["6e95a091.35c278","b9337ff1.5d9a9"]]},{"id":"25c0e9b7.ed538e","type":"inject","z":"d311091a.41ebe","name":"button not clicked","topic":"","payload":"1","payloadType":"str","repeat":"","crontab":"","once":false,"x":150,"y":140,"wires":[[]]},{"id":"bcb6d7ff.1fcee","type":"change","z":"d311091a.41ebe","name":"Green on","rules":[{"t":"set","p":"green","pt":"msg","to":"255","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":480,"y":20,"wires":[["e244fd5a.48586"]]},{"id":"a0318962.8a74e8","type":"change","z":"d311091a.41ebe","name":"Red off","rules":[{"t":"set","p":"red","pt":"msg","to":"0","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":480,"y":60,"wires":[["b6313b11.36f65"]]},{"id":"6e95a091.35c278","type":"change","z":"d311091a.41ebe","name":"Green off","rules":[{"t":"set","p":"green","pt":"msg","to":"0","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":480,"y":100,"wires":[["e244fd5a.48586"]]},{"id":"b9337ff1.5d9a9","type":"change","z":"d311091a.41ebe","name":"Red on","rules":[{"t":"set","p":"red","pt":"msg","to":"255","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":480,"y":140,"wires":[["b6313b11.36f65"]]},{"id":"e244fd5a.48586","type":"mqtt out","z":"d311091a.41ebe","name":"LED green","topic":"outside_node/ulnoiotLEDG","qos":"0","retain":"","broker":"65997223.341d04","x":690,"y":40,"wires":[]},{"id":"b6313b11.36f65","type":"mqtt out","z":"d311091a.41ebe","name":"LED red","topic":"outside_node/ulnoiotLEDR","qos":"0","retain":"","broker":"65997223.341d04","x":680,"y":120,"wires":[]},{"id":"8fca7ac4.9abed8","type":"inject","z":"d311091a.41ebe","name":"button click","topic":"","payload":"0","payloadType":"str","repeat":"","crontab":"","once":false,"x":130,"y":100,"wires":[[]]},{"id":"65997223.341d04","type":"mqtt-broker","z":"","broker":"192.168.12.1","port":"1883","clientid":"","usetls":false,"compatmode":true,"keepalive":"60","cleansession":true,"willTopic":"","willQos":"0","willPayload":"","birthTopic":"","birthQos":"0","birthPayload":""}] >


### UlnoIOT Part
- added a bunch of nodes for each sensor -> disregarded idea in order to have one for each arduino and add the sensors/actors to the autostart file
- added outside_node
  modified autostart.py of outside_node to:


    button("ulnoiotBTN", d3, 0, 1)
    led("ulnoiotLEDG", d7, "on", "off")
    led("ulnoiotLEDR", d8, "on", off)
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
