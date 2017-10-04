# Vorlesungsarbeit
Magdalena Hametner - Mo, 3. Oktober 2017

## Folie 2 - Low Level Buses
Worked with Dominik reichinger, Johannes Mayrhofer, Johannes Lugstein, Marlies Hüttner, Michael Rockenschaub, Nora Wokatsch, Philipp Graf

### RS232
+ Serial communication transmission of data
+ + signal between a DTE (Data Terminal Equipment, e.g. Computer terminal) with a DCE
(data-circuit terminating equipment [data communication equipment, e.g. a modem])
+ + Was a standard port for computers connecting: Mice, Keyboard, Modem, Printer, Data storage

+ Downsides:
+ + Low transmission speed
+ + + 20 000 bits/second
+ + Short maximum cable length (max. 15m)
+ + + low capacity cable up to 300m
+ + Large voltage swing (3V bis 15V und -3V bis -15V)
+ + Large connectors
+ + No multipoint capability
+ + Limited multidrop capability

+ Got replaced in modern computers by USB
+ synchoronos and asynchronous
+ standard defines the number of circuits
+ Each circuit only operates in one direction
+ Standard does not define character framing

+ Use:
+ + Industrial machines
+ + Networking equipment
+ + Scientific instruments where low speed, point to point and short range wired data connection is adequate

+ Speeds
+ + Baud = 3579545 / 2 / 16 = 111861 baud. 2% error-tolerance

### I2C
+ multimaster, multislave
+ works with packets
+ seriell
+ half-duplex

+ wiring

2 schemes: (GND, SCL, VCC, SDA) and (VCC, SDA, GND, SCL)

+ Speed:
+ + standard mode: 100 kbit/s
+ + full speed: 400 kbit/s
+ + fast mode: 1 mbit/s
+ + high speed: 3,2 Mbit/s

+ Use
+ + lower speed periferal integrated circuits to micro controller

+ Example:
Reading configuration data from SPD EEPROMs on SDRAM, DDR SDRAM, DDR2 SDRAM memory sticks (DIMM) and other stacked PC boards
Supporting systems management for PCI cards, through an SMBus 2.0 connection.
Accessing NVRAM chips that keep user settings.
Accessing low-speed DACs and ADCs.
Changing contrast, hue, and color balance settings in monitors (Display Data Channel).
Changing sound volume in intelligent speakers.

### SPI
A synchronous serial communication interface specification used for short distance communication
The SPI bus can operate with a single master device and with one or more slave devices.
Full duplex communication in the default version.

+ wiring
+ + SCLK: Serial Clock (output from master),
+ + MOSI: Master Output Slave Input, or Master Out Slave In (data output from master)
+ + MISO: Master Input Slave Output, or Master In Slave Out (data output from slave
+ + SS: Slave Select (often active low, output from master)

+ Speed:
Not limited to any maximum clock speed, enabling potentially high speed;
Depends on the slave device.
Higher throughput than I²C or SMBus

+ Use:
+ + SPI earned a solid role in embedded systems
+ + ARM, MIPS, or PowerPC and with other microcontrollers such as the AVR, PIC, and MSP430
+ + Secue digital cards
+ + LCD
+ + Sensors

+ Connection:
To begin communication, the bus master configures the clock, using a frequency supported by the slave device.
The master then selects the slave device with a logic level 0
Independent slave configuration, there is an independent chip select line for each slave
SPI may be connected in a daisy chain configuration, the first slave output being connected to the second slave input, etc.

### Onewire
Onewire is a communication bus system that provides low-speed data signaling and power over a single cable loop (One cable for data and power, the other for ground).

The concept is simular to I²C, but has a lower data rate and a longer range. It's typically used in small and cheap devices.

A network of those devices with an master device is a MicroLan.

The Onewhire Technology is commonly used in HomeAutomation Systems for devices like Sensors, Cheap Wearables

+ Max. Speed 16,3 kbps

+ Examples:
+ + apple macsave
+ + Temperature sensors, weather sensors

De devices work in a master slave concept

Differen Topologies with different cable length
+ star 750M
+ linear
+ Bus (max 350 m)

Protocolls CMOS,TTL

Variable packages

sequenzielle datenrichtung in beide richtungen

variable data packes between 15 and 54 us
recovery time 10 us.
bis 750 m reichweite

## MPR 121 capacitive sensor

- Low power operation
- 1.71 V to 3.6V supply operation
- 29 uA supply current at 16 ms sampling interval periods
- 3 uA Stop mode current
- 12 capacitance sensing inputs
- 8 Inputs are multifunctionla for LED driver and GPIO
- Complete touch detection
- Auto-configuration for each sensing input
- Auto-calibartion for each sensing input
- Touch/release threshold and debounce for touch detection
- I²C interface, with interrupt output
- 3mm x 3mm x 0.65 mm 20 lead QFN package
- -40°C to + 85°C operating temperature range

Connect Raspberry Pi 3.3V to MPR121 VIN.
Connect Raspberry Pi GND to MPR121 GND.
Connect Raspberry Pi SCL to MPR121 SCL.
Connect Raspberry Pi SDA to MPR121 SDA.

![alt text](https://cdn-learn.adafruit.com/assets/assets/000/021/912/original/sensors_MPR121_RaspberryPi_bb.png?1419316602 "MPR 21")
