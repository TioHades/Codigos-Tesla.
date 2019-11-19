#include <Ultrasonic.h>

#define fita 800


const int motorA = 11; //velocidade motor A - de 0 a 255
const int motorB = 10; //velocidade motor B - de 0 a 255

const int dir1A = 4; //direcao do motor A - HIGH ou LOW
const int dir2A = 5; //direcao do motor A - HIGH ou LOW

const int dir1B = 6; //direcao do motor B - HIGH ou LOW,
const int dir2B = 7; //direcao do motor B - HIGH ou LOW



Ultrasonic ultrassom(3, 2);//Varievel do tipo, Ultrassonico.

int Sensor_1 = A0;//Direita
int Sensor_2 = A1; //Esquerda




float distancia;

int Valor_Sensor1 = 0;
int Valor_Sensor2 = 0;

void Ultrasson() {
  distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
  // centímetros(CM) ou polegadas(INC)
  Serial.print(distancia); //imprime o valor da variável distancia
  Serial.println("cm");
  delay(100);
}
void SensorRefletancia() {
  Valor_Sensor1 =  analogRead(Sensor_1);
  Serial.print("refletancia Direita:");
  Serial.println(Valor_Sensor1);

  Valor_Sensor2 =  analogRead(Sensor_2);
  Serial.print("refletancia Esquerda:");
  Serial.println(Valor_Sensor2);

  if ((Valor_Sensor1 >= fita) && (Valor_Sensor2 >= fita)) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(motorA, 150);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(motorB, 150);
    //VELOCIDADE
    delay(1000);
  }
  if ((Valor_Sensor1 < fita) && (Valor_Sensor2 > fita)) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(motorA, 0);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(motorB, 200);
    //VELOCIDADE
  }
  if ((Valor_Sensor1 > fita) && (Valor_Sensor2 < fita)) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(motorA, 200);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(motorB, 0);
    //VELOCIDADE
  }

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dir1A, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(dir2B, OUTPUT);

  if ((Valor_Sensor1 >= fita) && (Valor_Sensor2 >= fita)) {
    ////
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    //VELOCIDADE
    analogWrite(motorA, 150);
    analogWrite(motorB, 150);
    delay(1000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  SensorRefletancia();
  Ultrasson();
}
