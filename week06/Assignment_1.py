import RPi.GPIO as GPIO
import time

RED_PIN = 29  
GREEN_PIN = 31  
BLUE_PIN = 33  

GPIO.setmode(GPIO.BOARD) 
GPIO.setup(RED_PIN, GPIO.OUT)
GPIO.setup(GREEN_PIN, GPIO.OUT)
GPIO.setup(BLUE_PIN, GPIO.OUT)

def set_color(red, green, blue):
    GPIO.output(RED_PIN, not red)  
    GPIO.output(GREEN_PIN, not green)
    GPIO.output(BLUE_PIN, not blue)

try:
    while True:
        print("Red")
        set_color(1, 0, 0) 
        time.sleep(1)
        
        print("Green")
        set_color(0, 1, 0)
        time.sleep(1)
        
        print("Blue")
        set_color(0, 0, 1) 
        time.sleep(1)

except KeyboardInterrupt:
    print("Program stopped")
finally:
    set_color(0, 0, 0) 
    GPIO.cleanup()
