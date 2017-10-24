# Lecture Paper
Di, 24. Oktober 2017

## [Lora](https://www.youtube.com/watch?v=hMOwbNUpDQA):
= LPWAN (Low Power Wide Area Network)
new Transmission standard
### What is the relation bandwidth/range/power?
- high power to geth a big bandwidth
- no power to spend on wide area
- bandwidth smaller the band width the lower the transmission rate
- bandwidth <-> range:
  - Wifi high bandwidth, power hungry
  - Mobile Internet high power consumtion
  - Bluetooth reach is only a few meters
  - Lora, Sigfox low bandwidth by humanlaw and ???
    - no replacement of bluetooth

### What is the Link budget?
- Conn between sender and receiver [in dB]
- obsticals: distance, cables, Wände, trees
  - bigger consume mor budget
- Amplifier or Antenna Gain -> increase link budget
- 154 dB

### What is the community approach?
- The Things Network (TTN)

### What are benefits with LORA?
- high range
- 350bps-50kbps
- low power consumption - ideal for low power sensors
- very high link budget

### what are problems with LORA?
- low bandwidth
- low channel capacity

### Google link budget again:
- LoRa® and LoraWAN™ provides larger link budget compare to other technologies in environment or obstruction of a given location
- This form of modulation enables LoRa systems to demodulate signals that are 20dB below the noise floor when the demodulation is combined with forward error correction, FEC. This means that the link budget for a LoRa system can provide an improvement of more than 25dB when compared to a traditional FSK system.

### Googel "radio link budget calculator"
pics 1 2

### Google: LORA in Austria and Linz
[TTN](https://github.com/EvaJobst/IOT_HametnerJobst/blob/master/Hametner_Repo/Pics/TTN.png)

### What is TTN?
- https://www.thethingsnetwork.org
- BUILDING A FULLY DISTRIBUTED INTERNET OF THINGS DATA INFRASTRUCTURE
- The technology we use is called LoRaWAN and it allows for things to talk to the internet without 3G or WiFi. So no WiFi codes and no mobile subscriptions.

### What does it stand for?
= The Things Network

### Which problems does it solve?
- connectivity: low power sensors
- low range
- many costs
- Low bandwidth - something like 400 bytes per hour

### How does it solve them?
- with Lora
  - Long range - multiple kilometers
  - Low power - can last months (or even years) on a battery
  - Low cost
