# scripts
#include <Ultrasonic.h>
#include <Servo.h>
#define fita_1 980 //refletancia da linha preta
#define fita_2 1023// refletancia da linha preta
#define SERVO 6

Ultrasonic ultrassom(12, 13);//Varievel do tipo, Ultrassonico.
Servo myservo;//Variavel do tipo Servo.
int pos;//varievel posição do servo.

float sensorUltra;//Sensor Ultrassonico.
int pinoSensor = A5;
int valor = 0;//Sensor de Refletancia
int led_1 = 7;
int led_2 = 4;

void Ultrasonico() {
  sensorUltra = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em ultrassom.read();
  Serial.print(sensorUltra); //imprime o valor da variável distancia
  Serial.println(" cm");
  //delay(1000);
  if (sensorUltra <= 20) {
    digitalWrite(led_1, LOW);
    //   myservo.write(val);
    for (pos = 0; pos < 120; pos++)
    {
      myservo.write(pos);
      //delay(15);
    }
    delay(1000);
    for (pos = 90; pos >= 0; pos--)
    {
      myservo.write(pos);
      //delay(15);
      //delay(15);
    }
  } else if (sensorUltra > 20) {
    digitalWrite(led_1, HIGH);
  }
}

void SensorRefletancia() {
  valor = analogRead(pinoSensor);
  int valorCorrigido = valor;
  Serial.print("refletancia:");
  Serial.println(valorCorrigido);
  //delay(100);
  if (valorCorrigido <= fita_1)
  { // || //valorCorrigido <= fita_2){
    digitalWrite(led_2, HIGH);
  } else {
    digitalWrite(led_2, LOW);
  }
}
void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO);
  myservo.write(0);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  // pinMode(sensorRefle, INPUT);
}

void loop() {
  Ultrasonico();
  SensorRefletancia();

}
