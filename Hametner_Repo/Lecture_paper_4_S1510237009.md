# Vorlesungsarbeit
## Folie 2 - Scaling and Testing
### What will be issues scaling?
- system size, number of systems:
  - Overview gets lost
  - Server capacity scale up
  - configuration of all nodes is harder with more devices
  - testing is much work as every type of unit needed to be tested once
- How can we do testing:
  - simulate single things
  - automated testing scenarios
What role will play
- Simulator(-components)s?
  - faster testing if system can handle 1000 of devices
  - test faster different values and check the behavior of the devices
- MQTT:
  - makes it easy to exchange simulators with real devices
  - easy to add more devices / topics / etc.
- Stories
  - helps to understand the behavior of the different systems
  - helps to test specific scenarios
  - helps to understand bigger simulations and their components

### Open disscussion: ISSUES
#### SCALE
- Cost, Maintenance, Reliability
- The more devices, the more interconnectivity, increasing cost, maintenance and reliability.
- Predictive maintenance
  - Windmills start vibrating, integrating a vibration sensor can predict, before one is actually failing depending on the vibrations its emitting.
  - Too small subnets in combination with a Client-Server pattern might lead to too few IP addresses in an old IPv4 Network to supply every member in a network with an IP address
  - Continuous integration would be "nice".
##### Management
- Frameworks!

#### Testing
- multiple simulators for data stress testing
- latency testing (publisher, subscriber) with timestamping
- unit testing
- device stress testing (lifespan test)
- corner case testing (defined by stories)

#### Simulators
- Can be used for used for testing the systems by using defined values
- Scaling
- Error handling (e.g. String to topic which is usually used for Integers etc)
- Mock test cases which are hard to achieve in a real environment (degree: 700°)
- No hardware needed to test

#### MQTT
- Helps subscribesbs to easily only receive the topics they are interested to
- (Only one bus => one central point if we only have one broker)
- Takes control of the publish/subscribe pattern
- Single point of failue when not implementing more brokers
- Pretty mature and tested a lot

#### Stories
- With stories we can describe the problem easily
- Non-technical level of abstraction
- Help to communicate between stakeholder
- Defines the necessary devices and components
- Used for finding corner - cases / tests


## Folie 3 -  How can we develop and manage Software faster for IoT?
### Node-RED
#### Publicly available/open source/reference implemenation?
- browser-based flow editor
- easy to wire together flows using the wide range of nodes in the palette
- JavaScript functions can be created within the editor using a rich text editor
- free and esay to download

#### How good and plentiful is documentation (are there "good" examples, tutorials, videos)? How easy to understand?
- https://nodered.org/docs/
- easy described examples are listed
- video is available
- esay to understand tutorials

#### Which devices/operating systems are supported (also as nodes)?
- Raspberry Pi
- BeagleBone Black
- Interacting with Arduino
- Android
- some microcontroller available

#### Mass deployment/maintainance (managing multiple nodes at once)?
- Management to connect different nodes

#### Security/privacy (sage against man in the middle attacks)?
- By default, the Node-RED editor is not secured - anyone who can access the IP address and port it is running on can access the editor and deploy changes. This is only suitable if you are running on a trusted network.
- The Editor and Admin API supports two types of authentication:
  - username/password credential based authentication
  - since Node-RED 0.17: authentication against any OAuth/OpenID provider such as Twitter or GitHub


### Life-Demo: Node-RED
$ node-red

$ Take adresse

doppelter Klick auf Node zum Bearbeiten

#### Test:
- mqtt_send button/b1 pressed
- mqtt_all
