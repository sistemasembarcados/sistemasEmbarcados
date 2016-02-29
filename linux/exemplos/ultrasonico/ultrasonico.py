import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

# gpio 23
ECHO_PIN = 23

# gpio 24
TRIG_PIN = 24

# Velocidade do som 340,29 m/s -> 34029 cm/s
SPEED_OF_SOUND = 34029

# configura os pinos
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)

GPIO.output(TRIG_PIN, GPIO.LOW)
time.sleep(1)

# emite o sinal com duração de 10us, marcando o inicio da medição
GPIO.output(TRIG_PIN, GPIO.HIGH)
time.sleep(0.00001)
GPIO.output(TRIG_PIN, GPIO.LOW)

# Nosso primeiro passo deve ser o de gravar o ultimo baixo timestamp (time_start) para o ECHO (início de pulso), pouco antes do sinal de retorno.
while GPIO.input(ECHO_PIN) == GPIO.LOW:
 time_start = time.time()
 
# Uma vez que um sinal é recebido, o valor é alterado a partir de baixo (LOW) e alta (HIGH), e o sinal irá permanecer elevada durante a duração do impulso de eco. portanto, precisamos também da última alta timestamp para o ECHO (time_end).
while GPIO.input(ECHO_PIN) == GPIO.HIGH:
 time_end = time.time()
 
# calculamos a diferença de tempo
time_elapsed = time_end - time_start 

# calcula a distancia em cm, como tempos o comprimento da ida e volta do sinal, e necessario a divisão por 2, pois queremos a distancia do ultrasônico até o objeto.
distance = (time_elapsed * SPEED_OF_SOUND) / 2 

print("Distance: {0:.2f}".format(distance))

GPIO.cleanup() 
