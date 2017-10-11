import paho.mqtt.client as mqtt
import time
import serial

BROKER = "192.168.12.1"
TOPIC = "internetofthings/"
SUBTOPIC = "temperature"

arduino = serial.Serial("/dev/cu.wchusbserial1410", 115200)

def on_message(client, userdata, msg): 
    print(msg.topic + " "+str(msg.payload))

    if int(msg.payload) == 0:
        print("ON")
        arduino.write("ON")

client = mqtt.Client()
client.on_message=on_message
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC)
client.loop_forever()
