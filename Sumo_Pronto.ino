#include <Ultrasonic.h>//BIBLIOTECA - ULTRASSONICO.
#define fita 1000

Ultrasonic ultrassom_a(12, 13);
Ultrasonic ultrassom_b(14, 15);
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

long sensorUltra_a;
long sensorUltra_b;

//float sensorUltra1;
//float sensorUltra2;

int pinoSensor1 = A5;
int valor1 = 0;//Sensor de Refletancia

int pinoSensor2 = A4;
int valor2 = 0;//Sensor de Refletancia

void SensorRefletancia() {

  valor1 = analogRead(pinoSensor1);
  int valorCorrigido1 = valor1;
  Serial.print("refletancia:");
  Serial.println(valorCorrigido1);

  valor2 = analogRead(pinoSensor2);
  int valorCorrigido2 = valor2;
  Serial.print("refletancia:");
  Serial.println(valorCorrigido2);

  if ((valor1 >= fita) || (valor2 >= fita)) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
}
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
  SensorRefletancia();
}
}
