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
