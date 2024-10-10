from time import sleep
import board
import busio
import adafruit_vl6180x

##we are using pin 5 for SCL and pin 3 for SDA 

i2c = busio.I2C(board.SCL, board.SDA)

sensor = adafruit_vl6180x.VL6180X(i2c)

while True:
    range_mm = sensor.range
    print("Range: {0}mm".format(range_mm))
    sleep(1.0)
