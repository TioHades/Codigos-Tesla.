#include <Ultrasonic.h>

const int pinSensor = 8;//Direita //PINO DIGITAL UTILIZADO PELO MÓDULO//out = BLUE, vcc= vermelho, GND = GREEN
const int sensor = A0;//Esquerda

const int motorA = 11; //velocidade motor A - de 0 a 255
const int motorB = 10; //velocidade motor B - de 0 a 255

const int dir1A = 4; //direcao do motor A - HIGH ou LOW
const int dir2A = 5; //direcao do motor A - HIGH ou LOW

const int dir1B = 6; //direcao do motor B - HIGH ou LOW,
const int dir2B = 7; //direcao do motor B - HIGH ou LOW

Ultrasonic ultrassom(3, 2);//Varievel do tipo, Ultrassonico.

float distancia;

void Ultrasson() {
  distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
  // centímetros(CM) ou polegadas(INC)
  Serial.print(distancia); //imprime o valor da variável distancia
  Serial.println("cm");
  delay(100);
}
void SensorRefletancia() {
  bool estadoSensor1 = digitalRead(pinSensor);//Direita
  bool estadoSensor = digitalRead(sensor);

  Serial.println(estadoSensor1);
  Serial.println(estadoSensor);

  if((estadoSensor1 == false) && (estadoSensor == false)) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(motorA, 80);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(motorB, 80);
    //VELOCIDADE
  }else if ((estadoSensor1 == true) && (estadoSensor == false)) { 
    delay(400);
    Serial.println("PRETO");
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(motorA, 0);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(motorB, 80);
    delay(400);
    //VELOCIDADE
  }else if ((estadoSensor == true) && (estadoSensor1 == false)) {
    delay(400);
    Serial.println("PRETO");
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(motorA, 80);
    //ROTAÇÃO
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(motorB, 0);
    delay(400);
    //VELOCIDADE
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(pinSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(sensor, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin (9600); //INICIALIZA A SERIAL

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dir1A, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(dir2B, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


  SensorRefletancia();
  Ultrasson();
}
