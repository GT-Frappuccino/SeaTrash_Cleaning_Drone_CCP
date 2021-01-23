def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setwarnings(False)
    
    GPIO.setup(L_M1, GPIO.OUT)
    GPIO.setup(L_M2, GPIO.OUT)
    GPIO.setup(L_ENA, GPIO.OUT)
    GPIO.setup(R_M1, GPIO.OUT)
    GPIO.setup(R_M2, GPIO.OUT)
    GPIO.setup(R_ENB, GPIO.OUT)
    #motorR = GPIO.PWM(L_ENA, 100)
    #motorL = GPIO.PWM(R_ENB, 100)
    motorR.start(100)
    motorL.start(100)

def back(time):
    
    GPIO.output(L_M1, GPIO.HIGH)
    GPIO.output(L_M2, GPIO.LOW)

    GPIO.output(L_ENA, GPIO.HIGH)
    GPIO.output(R_M1, GPIO.HIGH)

    sleep(time)

def forward(time): # R

    GPIO.output(L_M1, GPIO.LOW)
    GPIO.output(L_M2, GPIO.HIGH)
    GPIO.output(L_ENA, GPIO.HIGH)

    GPIO.output(R_M1, GPIO.LOW)
    GPIO.output(R_M2, GPIO.HIGH)
    GPIO.output(R_ENB, GPIO.HIGH)

    sleep(time)

def right(time): # both

    GPIO.output(L_M1, GPIO.LOW)
    GPIO.output(L_M2, GPIO.HIGH)
    GPIO.output(L_ENA, GPIO.HIGH)

    GPIO.output(R_M1, GPIO.HIGH)
    GPIO.output(R_M2, GPIO.HIGH)
    GPIO.output(R_ENB, GPIO.HIGH)

    sleep(time)


def left(time): # nothing

    GPIO.output(L_M1, GPIO.HIGH)
    GPIO.output(L_M2, GPIO.HIGH)
    GPIO.output(L_ENA, GPIO.HIGH)

    GPIO.output(R_M1, GPIO.LOW)
    GPIO.output(R_M2, GPIO.HIGH)
    GPIO.output(R_ENB, GPIO.HIGH)

    sleep(time)
    
def stop(time):
    GPIO.output(L_ENA, GPIO.LOW)
    GPIO.output(R_ENB, GPIO.LOW)

    sleep(time)
