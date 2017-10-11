import paho.mqtt.client as mqtt
import time

BROKER = "192.168.12.1"
TOPIC = 'internetofthings/'
SUB_TEMPERATURE = 'temperature'
SUB_SWITCH = 'switch'

def on_message(client, userdata, msg):
    # Process Temperature value
    if msg.topic == TOPIC + SUB_TEMPERATURE:
        print(msg.topic + " "+str(msg.payload))

        if int(msg.payload) >= 0:
            client.publish(TOPIC+SUB_SWITCH, str(1))
        else:
            client.publish(TOPIC+SUB_SWITCH, str(0))



client = mqtt.Client()
client.on_message=on_message
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC+SUB_TEMPERATURE)
client.subscribe(TOPIC+SUB_SWITCH)
client.loop_forever()
