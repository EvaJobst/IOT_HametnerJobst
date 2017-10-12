# Lab Outline 1
## (2. Oct 2017)
mit Eva Jobst und Magdalena Hametner

  Password changed into HametnerJobst
  Username changed into HametnerJobst

  Raspberry Pi 3 build
  Cooler inserted

  IP: 192.168.12.1

  Über GitBash:
    ssh pi@ulnoiotgw -L5901:localhost:5901 (Befehl)
    5901 = Port
      If you are on the pi port 5901 is used;
      On your machine port 5901 is available;

    Netzwerk-Name: HametnerJobst-da1885
      -->localhost did not work

      used IP
        -->Did not work either


Network-Name: HametnerJobst-da1885

NOOBS (Boot) put into Laptop
  + Inputs and alterations checked

not worked :/

conn. with wrong Network
  --> conn. mit Raspberry Pi 3

again ssh command executed

worked
  --> with password confirmed

select:
  2. tmux:ulnoiot: ...

cd home
cd src/rpi-clone
sudo ./rpi-clone -v sda

Card was not placed correctly
  --> Access denied to Partition

Card placed correctly
 --> worked

Eva: "lötet"

sudo chmod -R 755 /home/pi/apps arduino
sudo chmod -R 755 /home/pi/apps arduino/*
  --> Important: to make code executable
      needed: because of errors in given Code
      not needed again

did not work

Arduino IDE started
  --> Tools - Board - Wemos D1 mini
  --> File - example - ESP8266

run

did not work

unplug and plug in D1 minis

run

did work

---------------------------

## (3. Oct 2017)
Raspberry Pi 3 connected to the Hub

GitBash:
- ssh pi@192.168.12.1 as ulnoiot did not work

- VNC Viewer opened
- - Arduino IDE opened
- - - File - Example - WifiWebServer --> run
- - - --> Did not run --> We thought, that our Wemos D1 mini is to small for this program
- - - WifiWebSerer altered
        --> Code from blinking program inserted
- - - --> Did not workaltered
- - - Tried to open the program from terminal to get some errors --> no good idea
- - - correct solution:
- - - - ssid and password altered (ssid = HametnerJobst-da1885 and password = HametnerJobst)
- - - - in setup method: Serial.beginn(115200) altered baudrate
- - - - Serial Monitor Baudrate altered to 115200 too

http://192.168.12.213/LED=ON
http://192.168.12.213/LED=OFF

worked :D
