import paho.mqtt.client as mqtt
import time

BROKER = "192.168.12.1"
TOPIC = 'internetofthings/'
SUB_SWITCH = 'switch'

def on_message(client, userdata, msg):
    # Process Temperature value
    if msg.topic == TOPIC + SUB_SWITCH:
        if int(msg.payload) == 1:
            print("SWITCH ON")
        else:
            print("SWITCH OFF")



client = mqtt.Client()
client.on_message=on_message
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC+SUB_SWITCH)
client.loop_forever()
