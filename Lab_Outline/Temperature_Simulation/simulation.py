import paho.mqtt.client as mqtt
import time

BROKER = "192.168.12.1"
TOPIC = 'internetofthings/'
SUB_TEMPERATURE = 'temperature'
MIN_TEMP = -10;
MAX_TEMP = 10;

client = mqtt.Client()
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC)

client.loop_start()

for x in range(MIN_TEMP, MAX_TEMP):
    print(str(x))
    client.publish(TOPIC+SUB_TEMPERATURE, x)
    time.sleep(2)

client.loop_stop()
