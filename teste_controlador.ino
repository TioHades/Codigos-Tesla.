#include <Servo.h>// BIBLIOTECA DO SERVO..........................................................................

int Motor = 7;//Porta de saida do Arduino
int Motor2 = 8;//Porta de saida do Arduino

const int _Servo = 6;
Servo s;
int posi;


void setup() {
s.attach(_Servo);
s.write(0);
pinMode(Motor, OUTPUT);
pinMode(Motor2, OUTPUT);//Inicialização da porta, como Saida = OUTPUT

  
}

void loop() {
  
digitalWrite(Motor, HIGH);
digitalWrite(Motor2, HIGH);

  for(posi = 0; posi < 180; posi++){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
    s.write(posi); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(15); //INTERVALO DE 15 MILISSEGUNDOS
  }
  delay(1000); //INTERVALO DE 1 SEGUNDO
  for(posi = 180; posi >= 0; posi--){ //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
    s.write(posi); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(15); //INTERVALO DE 15 MILISSEGUNDOS
  }

}
