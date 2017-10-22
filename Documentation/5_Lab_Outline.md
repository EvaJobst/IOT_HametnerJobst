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

On the internal we wired: <USB1>
- gas-sensor (Pin A0)
- flame-sensor (Pin D2)

On the extrernal we wirde: <USB2>
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

### node red Part
[{"id":"b012f8d9.db405","type":"mqtt in","z":"c902da21.ddac5","name":"Button Subscriber","topic":"outside_node/ulonoiotBTN","qos":"0","broker":"ebf64fa1.fb7058","x":346,"y":48,"wires":[["10abffed.6f23e8"]]},{"id":"10abffed.6f23e8","type":"switch","z":"c902da21.ddac5","name":"switch BTN","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"},{"t":"eq","v":"1","vt":"str"}],"checkall":"true","outputs":2,"x":542,"y":48,"wires":[["10c477a8.a33be","c85e98a0.1ef33","a26fccf0.d123a","debbf410.522b08"],["10c477a8.a33be","f93a70c8.bed37","3c1a68a8.b4eb","1a69d479.ca391c"]]},{"id":"c49f5a3a.688f18","type":"change","z":"c902da21.ddac5","name":"Green on","rules":[{"t":"set","p":"payload","pt":"msg","to":"on","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":1364,"y":300,"wires":[["b0abcaa8.049ca"]]},{"id":"a5145220.7d481","type":"change","z":"c902da21.ddac5","name":"Red off","rules":[{"t":"set","p":"payload","pt":"msg","to":"off","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":1364,"y":340,"wires":[["9b7f1777.389968"]]},{"id":"ec08ba52.ac7568","type":"change","z":"c902da21.ddac5","name":"Green off","rules":[{"t":"set","p":"payload","pt":"msg","to":"off","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":1364,"y":380,"wires":[["b0abcaa8.049ca"]]},{"id":"d5950314.b023e","type":"change","z":"c902da21.ddac5","name":"Red on","rules":[{"t":"set","p":"payload","pt":"msg","to":"on","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":1364,"y":420,"wires":[["9b7f1777.389968"]]},{"id":"b0abcaa8.049ca","type":"mqtt out","z":"c902da21.ddac5","name":"LED green","topic":"outside_node/ulnoiotLEDG","qos":"0","retain":"","broker":"ebf64fa1.fb7058","x":1565,"y":340,"wires":[]},{"id":"9b7f1777.389968","type":"mqtt out","z":"c902da21.ddac5","name":"LED red","topic":"outside_node/ulnoiotLEDR","qos":"0","retain":"","broker":"ebf64fa1.fb7058","x":1564,"y":400,"wires":[]},{"id":"e85c7e1.58d8f8","type":"inject","z":"c902da21.ddac5","name":"button not clicked","topic":"","payload":"1","payloadType":"str","repeat":"","crontab":"","once":false,"x":401,"y":148,"wires":[["10abffed.6f23e8"]]},{"id":"f6b7cb08.78619","type":"inject","z":"c902da21.ddac5","name":"button click","topic":"","payload":"0","payloadType":"str","repeat":"","crontab":"","once":false,"x":381,"y":108,"wires":[["10abffed.6f23e8"]]},{"id":"14c3ba74.66194e","type":"mqtt in","z":"c902da21.ddac5","name":"Gassensor Subscriber","topic":"inside_node/ulnoiotGAS","qos":"2","broker":"3faae7cb.152f78","x":108,"y":260,"wires":[["9d56d7b7.bd671"]]},{"id":"9d56d7b7.bd671","type":"switch","z":"c902da21.ddac5","name":"switch GAS","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"},{"t":"eq","v":"1","vt":"str"}],"checkall":"true","outputs":2,"x":330,"y":260,"wires":[["87729220.12cce8"],["e1a0d53f.fa36c"]]},{"id":"87729220.12cce8","type":"change","z":"c902da21.ddac5","name":"Gas ON","rules":[{"t":"set","p":"payload","pt":"msg","to":"0","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":540,"y":227,"wires":[["f93a70c8.bed37","c85e98a0.1ef33","3c1a68a8.b4eb"]]},{"id":"e1a0d53f.fa36c","type":"change","z":"c902da21.ddac5","name":"Gas OFF","rules":[{"t":"set","p":"payload","pt":"msg","to":"1","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":540,"y":280,"wires":[["10c477a8.a33be","1a69d479.ca391c","debbf410.522b08"]]},{"id":"2a43bb04.15cf1c","type":"mqtt in","z":"c902da21.ddac5","name":"Flamesensor Subscriber","topic":"inside_node/ulnoiotFLAME","qos":"2","broker":"3faae7cb.152f78","x":116,"y":420,"wires":[["2ad0d3d2.030724"]]},{"id":"2ad0d3d2.030724","type":"switch","z":"c902da21.ddac5","name":"switch FLAME","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"},{"t":"eq","v":"1","vt":"str"}],"checkall":"true","outputs":2,"x":360,"y":420,"wires":[["81fdb782.c01f98"],["264baf12.59a81"]]},{"id":"81fdb782.c01f98","type":"change","z":"c902da21.ddac5","name":"Flame ON","rules":[{"t":"set","p":"payload","pt":"msg","to":"0","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":532,"y":387,"wires":[["f93a70c8.bed37","3c1a68a8.b4eb","1a69d479.ca391c","debbf410.522b08"]]},{"id":"264baf12.59a81","type":"change","z":"c902da21.ddac5","name":"Flame OFF","rules":[{"t":"set","p":"payload","pt":"msg","to":"1","tot":"str"}],"action":"","property":"","from":"","to":"","reg":false,"x":542,"y":440,"wires":[["10c477a8.a33be","c85e98a0.1ef33"]]},{"id":"28cb5af.a020926","type":"inject","z":"c902da21.ddac5","name":"gas on","topic":"","payload":"0","payloadType":"str","repeat":"","crontab":"","once":false,"x":96.5,"y":324,"wires":[["9d56d7b7.bd671"]]},{"id":"ce44dbb6.ae159","type":"inject","z":"c902da21.ddac5","name":"gas off","topic":"","payload":"1","payloadType":"str","repeat":"","crontab":"","once":false,"x":94,"y":360,"wires":[["9d56d7b7.bd671"]]},{"id":"2dc0f558.42ca6a","type":"inject","z":"c902da21.ddac5","name":"flame on","topic":"","payload":"0","payloadType":"str","repeat":"","crontab":"","once":false,"x":120,"y":480,"wires":[["2ad0d3d2.030724"]]},{"id":"878ca81b.9411b","type":"inject","z":"c902da21.ddac5","name":"flame off","topic":"","payload":"1","payloadType":"str","repeat":"","crontab":"","once":false,"x":120,"y":520,"wires":[["2ad0d3d2.030724"]]},{"id":"10c477a8.a33be","type":"switch","z":"c902da21.ddac5","name":"sensors off, btn","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":902,"y":260,"wires":[["a5145220.7d481","ec08ba52.ac7568"]]},{"id":"f93a70c8.bed37","type":"switch","z":"c902da21.ddac5","name":"Gas on, Flame off, btn not clicked","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":962,"y":300,"wires":[["c49f5a3a.688f18","a5145220.7d481"]]},{"id":"c85e98a0.1ef33","type":"switch","z":"c902da21.ddac5","name":"Gas on, Flame off, btn clicked","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":953,"y":340,"wires":[["a5145220.7d481","ec08ba52.ac7568"]]},{"id":"3c1a68a8.b4eb","type":"switch","z":"c902da21.ddac5","name":"Gas on, Flame on, btn not clicked","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":962,"y":380,"wires":[["d5950314.b023e","ec08ba52.ac7568"]]},{"id":"a26fccf0.d123a","type":"switch","z":"c902da21.ddac5","name":"Gas on, Flame on, btn clicked","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":952,"y":420,"wires":[["a5145220.7d481","ec08ba52.ac7568"]]},{"id":"1a69d479.ca391c","type":"switch","z":"c902da21.ddac5","name":"Gas off, Flame on, btn not clicked","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":962,"y":460,"wires":[["d5950314.b023e","ec08ba52.ac7568"]]},{"id":"debbf410.522b08","type":"switch","z":"c902da21.ddac5","name":"Gas off, Flame on, btn clicked","property":"payload","propertyType":"msg","rules":[{"t":"eq","v":"0","vt":"str"}],"checkall":"true","outputs":1,"x":952,"y":500,"wires":[["ec08ba52.ac7568","a5145220.7d481"]]},{"id":"ebf64fa1.fb7058","type":"mqtt-broker","z":"","broker":"192.168.12.1","port":"1883","clientid":"","usetls":false,"compatmode":true,"keepalive":"60","cleansession":true,"willTopic":"","willQos":"0","willPayload":"","birthTopic":"","birthQos":"0","birthPayload":""},{"id":"3faae7cb.152f78","type":"mqtt-broker","z":"","broker":"192.168.12.1","port":"1883","clientid":"","usetls":false,"compatmode":true,"keepalive":"60","cleansession":true,"willTopic":"","willQos":"0","willPayload":"","birthTopic":"","birthQos":"0","birthPayload":""}]
