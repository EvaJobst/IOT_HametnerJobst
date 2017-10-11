import paho.mqtt.client as mqtt
import time

BROKER = "192.168.12.1"
TOPIC = 'internetofthings/'
SUBTOPIC = 'temperature'
MIN_TEMP = -3;
MAX_TEMP = 3;

client = mqtt.Client()
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC)

client.loop_start()

for x in range(MIN_TEMP, MAX_TEMP):
    print(str(x))
    client.publish(TOPIC, x)
    time.sleep(1)

client.loop_stop()
