try:
    import usocket as socket
except:
    import socket

from machine import Pin

d1 = Pin(14, Pin.OUT)
d2 = Pin(12, Pin.OUT)
d3 = Pin(13, Pin.OUT)
d4 = Pin(15, Pin.OUT)

d1.value(1)
d2.value(1)
d3.value(1)
d4.value(1)

import network
import esp
esp.osdebug(None)

import gc
gc.collect()

ssid = 'i=q/t#Current'
password = '2022#ElectronFlow'

station = network.WLAN(network.STA_IF)

station.active(True)
station.connect(ssid, password)

while station.isconnected() == False:
    pass

print("Connection Succesful!")
print(station.ifconfig())
