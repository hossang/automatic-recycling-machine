import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

pins = (21,20,16) #r = 21 g = 20 b = 16

GPIO.setup(pins[0], GPIO.OUT)
GPIO.setup(pins[1], GPIO.OUT)
GPIO.setup(pins[2], GPIO.OUT)

try:
    while 1:
        #GPIO.output(pins[0], GPIO.HIGH) #light up,GPIO.HIGH==1
        time.sleep(0.5)
        GPIO.output(pins[2], GPIO.HIGH) #light off,GPIO.LOW==0
        time.sleep(0.5)
    
except KeyboardInterrupt:
    GPIO.cleanup() 
    

