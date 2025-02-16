import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)  
GPIO.setup(4, GPIO.OUT)   

try:
    while True:
        val = GPIO.input(17)
        
        if val == 1:
            print(val)
            GPIO.output(4, GPIO.LOW)
        else:
            print(val)
            GPIO.output(4, GPIO.HIGH)

except KeyboardInterrupt:
    GPIO.cleanup()

