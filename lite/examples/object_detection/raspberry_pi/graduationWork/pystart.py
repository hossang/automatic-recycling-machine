##############################
import subprocess
import os
import time
import serial
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

ser = serial.Serial('/dev/ttyACM0', 9600, timeout =1)
ser.flush()

pins = (21,20,16) 

GPIO.setup(pins[0], GPIO.OUT)
GPIO.setup(pins[1], GPIO.OUT)
GPIO.setup(pins[2], GPIO.OUT)

GPIO.output(pins[0], GPIO.HIGH)
#################blueOn#################
var = subprocess.run(['python detect.py --model bcpp0501_edgetpu.tflite --enableEdgeTPU'], capture_output=True, shell=True)
try:
    while(1):
        if var.stdout:
            print('pystart : %s' % var.stdout.decode())
            GPIO.output(pins[0], GPIO.LOW)
#################blueOff#################            
            GPIO.output(pins[1], GPIO.HIGH)
#################greenOn#################            
            while(1):
                line = ser.readline().decode('utf-8').rstrip()
                if(line == 'O'):
                    #print(line)
                    break
 
            GPIO.output(pins[1], GPIO.LOW)
#################greenOff#################            
            GPIO.output(pins[0], GPIO.HIGH)
#################blueOn###################            
            var = subprocess.run(['python detect.py --model bcpp0501_edgetpu.tflite --enableEdgeTPU'], capture_output=True, shell=True)       
except KeyboardInterrupt:
    GPIO.cleanup()    
##############################




