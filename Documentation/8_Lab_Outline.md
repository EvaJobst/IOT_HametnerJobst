# Lab Outline 8
##### 24. October 2017
with Magdalena Hametner and Eva Jobst

##### LORA

| Exercise                | Done By           |
|----------               |-------------      |
| Code                    | Jobst             |
| Documentation           | Hametner          |

- Add Antenna to module
- Add module to Raspberry PI
- Looked at provided resources -> decided on using https://www.hackster.io/ChrisSamuelson/lora-raspberry-pi-single-channel-gateway-cheap-d57d36
- cloned single_chan_pkt_fwd onto Raspberry
- Enabled SPI
- Rebooted PI
- Installed wiring-pi on Raspberry
- Opened main.cpp of single_chan_pkt_fwd and changed SERVER1 to EU Server 52.169.76.203
- Did **NOT** change frequency for now
- Compiled and ran program
- Problem: "Unrecognized Transceiver" when we try to run the program
