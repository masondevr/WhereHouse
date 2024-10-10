from  picamera import PiCamera
from datetime import datetime
from time import sleep
camera = PiCamera()
camera.resolution= (1024, 768)
camera.start_preview()
print("sleeping")
sleep(1)
print("waking")
now = datetime.now()
dt_string = now.strftime("Images/%Y-%m-%d_%H-%M-%S")
print("taking pic")
camera.capture(dt_string + ".jpg")
print("picture taken")
