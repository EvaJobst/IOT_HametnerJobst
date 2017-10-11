# Report
11th October 2017; Eva Jobst
______________________
Worked with: Stefan Schwaighofer, Johannes Lugstein, Magdalena Hametner

## Scaling and Testing
##### What will be issues scaling?
- Keeping an overview
- Server Capacity
- Configuration of nodes

##### How can we do testing?
- Encapsulating every kind of unit and test each of them
- Automating test scenarios
- Simulating (corner) values
- e. g. Simulating values -> testing if the processing of them works

##### What role will play?
- Simulator: Testing the full range of possible values
- MQTT: Replacing real devices with simulators; Adding more devices without much overhead
- Stories: Knowing how the components are supposed to work (with each other); Testing specific scenarios

## IoT Frameworks
##### Title
IoTivity
- Hosted by the Linux Foundation, sponsored by OCF
##### Reference implementation

##### Documentation Quality
- On their website (https://www.iotivity.org/documentation)
##### Supported Devices and Operation Systems
- OS: Linux, Tizen, Android, Arduino
- Languages: C, C++, Java
- Devices: https://wiki.iotivity.org/hardware
##### Maintainance
##### Security and Privacy

## Working with Node-RED
- Write in console
````
mqtt_broker
node_red````

- Add node:
  - Server localhost:1883
  - Topic button/b1
  - QoS 0
- Add debug node
- What the button receives will be used in the debugger
- Send something with `mqtt_send button/b1 press(ed)`
- MQTT-output: Topic flashled/led
- `mqtt_all` can also be used to send data
- Node "change" is used in-between to make rules; otherwise the LED would also send "pressed", like the button. But we need the LED to turn on/off.
  - Search for: Pressed | Depressed
  - Replace with: On | Off
