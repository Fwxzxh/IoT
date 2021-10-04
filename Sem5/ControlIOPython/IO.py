# Controlar IO en arduino con python usando Firmata.

from pyfirmata import Arduino
import time

LED:int = 9

arduino:str = Arduino("/dev/ttyACM0")

for x:int in range(10):
    arduino.digital[LED].write(1)
    time.sleep(.500)
    arduino.digital[LED].write(0)
    time.sleep(.500)
