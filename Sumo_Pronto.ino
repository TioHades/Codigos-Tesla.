#include <Ultrasonic.h>//BIBLIOTECA - ULTRASSONICO.
#define fita 1000

Ultrasonic ultrassom_a(10, 11);
Ultrasonic ultrassom_b(12, 13);
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

long sensorUltra_a;
long sensorUltra_b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  sensorUltra_a = ultrassom_a.read();// ultrassom.Ranging(CM) retorna a distancia em
  Serial.print(sensorUltra_a); //imprime o valor da variável distancia
  Serial.println(" cm");

  sensorUltra_b = ultrassom_b.read();// ultrassom.Ranging(CM) retorna a distancia em
  Serial.print(sensorUltra_b); //imprime o valor da variável distancia
  Serial.println(" cm");

  if ((sensorUltra_a <= 20) || (sensorUltra_b <= 20)) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}
