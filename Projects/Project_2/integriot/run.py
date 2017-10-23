from integriot import *
import time
from hcsr04 import HCSR04

#def distance(msg):
#	print(msg)
#	while msg == "on":
#		a = 0
#	time1 = time.time()
	
#	while msg == "off":
#		a = 1
#	time2 = time.time()
	
#	during = time2 - time1
#	cm = during * 340 / 2 * 100
#	print(cm, 'cm')

def loop():
	distance = ultrasonic.distance_cm()
	print('Distance:', distance, ' cm')
#	while True:
#		trigger.off()
#		time.sleep(0.000002)

#		trigger.on()
#		time.sleep(0.00001)
#		trigger.off()
	

init("192.168.12.1")

prefix("test_node")
#echo = sensor("ultrasonic/echo")
#trigger = switch("ultrasonic/trigger")
#echo.add_callback_change(callback=distance)
ultrasonic = HCSR04(trigger_pin=0, echo_pin=2)

loop()
run()