# Report
25th October 2017; Eva Jobst
______________________

### 1-WIRE
- Similar to I2C (but with lower data rate and longer range)
- Network -> is called MicroLAN
- 64-bit Serial Number as identification -> 8 least significant bit are the type of the device (e. g. thermometer); 8 most significant bit are CRC
- Collission Detection Protocol (retry on error solution)

##### Wiring
- Possible to use only two wires for data and ground (possible due to use of an capacitor to store charge and to power the device during an active data line)
- 800 pF capacitor (built-in)

##### Speed
- 16.3 kbit/s; overdrive to 10x


##### Max Length
- 750 m


##### Use
- Power supply
- Used to communicate with small inexpensive devices (e. g. digital thermometer, weather instruments)


##### Examples
- Apple: MagSafe, MagSafe 2, displays, laptops use 1-Wire to send and receive data to and from the connected laptop
- Data is power supply model, wattage, serial number, laptop may command full power, illuminate LED's red or green
- Dell: laptop power supply use the 1-Wire to send data via the third wire to the laptop (about power, current and voltage ratings).
- iButton, Java Ring (ring-mounted iButton with Java virtual machine)


##### RS232
- Used to be standard for serial communication -> modems, printer, mouses
- Replaced with USB
- Nowadays used for service configuration ports
- Asynchronous data transfer, ASCII coded
- Speed: Max. 1.5 MB/s
- Max Length: 15 m; Low capacitity cabel: 300 m


##### I2C
-	Low speed bus protocol for connecting peripherals to microcontroller
- invented by Philips
- two lines: data USDA and clock USCL
- 5v or 3v
- speed 10kbit/s - 3.5 mbit/s
- length: a few meter
- two lines have an adressing space of 7-bit
- master slave principle
- protocol: half duplix
- used for reading configurration data from EEPROMS, Accessing DAC'S and ADC's; Controlling OLED/LCD displays
- OS support: Arduino, Mac, Linux

##### SPI
-	is supposed to be faster than RS232 and I2C
- 4 cable
- synchronous with master-slave
- cable: masterIN/slaveOUT, masterOUT/slaveIN, clock, slave-select
- used for microcontroller for communication with peripherie devices
- max length depends on clock speed (3 m but possible to 100 m)


##### Button KY-004
- How to Wire
- KY-004 -> Arduino
- S -> e. g. Pin 10
- http://sensorkit.en.joy-it.net/images/8/82/ky-004.jpg
- http://sensorkit.en.joy-it.net/images/8/88/3_G_V_S.png
- What to measure/trigger/threshold
	- Outputs a high-signal when pressed

**Example**


	int Led = 13 ;// define LED Interface
	int buttonpin = 10; // define the key switch sensor interface
	int val ;// define numeric variables val
	void setup ()
	{
  	pinMode (Led, OUTPUT); // define LED as output interface
  	pinMode (buttonpin, INPUT); // define the key switch sensor output interface
	}

	void loop ()
	{
  	val = digitalRead (buttonpin); // digital interface will be assigned a value of 3 to read val
    if (val == HIGH)  // When the key switch when the sensor detects a signal, LED flashes
  	{
    	digitalWrite (Led, HIGH);
  	}
  	else
  	{
    	digitalWrite (Led, LOW);
  	}
	}
