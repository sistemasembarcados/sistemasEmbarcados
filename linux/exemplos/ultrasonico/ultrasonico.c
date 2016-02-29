#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <sys/time.h>
 
 // gpio 23
 #define ECHO_PIN        23 
 
 // gpio 24
 #define TRIG_PIN        24 
 
 // Velocidade do som 340,29 m/s - 34029 cm/s
 #define SPEED_OF_SOUND  34029
 
 int main (void) {
  
  // configura os pinos
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
  delay(1000);
 
  struct timeval time_start, time_end;
  double time_elapsed, distance;
  
  // emite o sinal com duração de 10us, marcando o inicio da medição
  digitalWrite(GPIO_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(GPIO_TRIGGER, LOW);
 
  // Nosso primeiro passo deve ser o de gravar o ultimo baixo timestamp (time_start) para o ECHO (início de pulso), pouco antes do sinal de retorno.
  while (digitalRead(ECHO_PIN) == LOW) {
   gettimeofday(&amp;time_start, NULL);
  }
 
  // Uma vez que um sinal é recebido, o valor é alterado a partir de baixo (LOW) e alta (HIGH), e o sinal irá permanecer elevada durante a duração do impulso de eco. portanto, precisamos também da última alta timestamp para o ECHO (time_end).
  while (digitalRead(ECHO_PIN) == HIGH) {
   gettimeofday(&amp;time_end, NULL);
  }
  
  // Calculamos a diferenca do tempo
  time_elapsed = (time_end.tv_sec + time_end.tv_usec / 1000000.0) - (time_start.tv_sec + time_start.tv_usec / 1000000.0);
  
  // calcula a distancia em cm, como tempos o comprimento da ida e volta do sinal, e necessario a divisão por 2, pois queremos a distancia do ultrasônico até o objeto.
  distance = (time_elapsed * SPEED_OF_SOUND) / 2;
  printf("Distance: %.2f cmn", distance);
  return 0;
 } 
