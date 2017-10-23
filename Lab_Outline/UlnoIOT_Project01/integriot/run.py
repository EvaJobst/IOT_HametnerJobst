from integriot import *


def show(msg):
	global green
	global red
	print("received:", msg)
	if msg == "green":
		print("switch on green led")
		green.on()
		red.off()
		buzzer.off()
	elif msg == "red":
		print("switch on red led")
		green.off()
		red.on()
		buzzer.on()
	else:
		print("switch off both leds")
		green.off()
		red.off()
		buzzer.off()
		


init("192.168.12.1")

prefix("outside_node")
button = sensor("ulnoiotBTN")
button.add_callback_change(callback=show)
#button.add_callback("",callback=show)
green = led("ulnoiotLEDG", init_state="off")
red = led("ulnoiotLEDR", init_state="off")
buzzer = switch("ulnoiotBUZZER", init_state="off")

run()
