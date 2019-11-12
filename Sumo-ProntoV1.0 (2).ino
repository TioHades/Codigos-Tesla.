#include <Ultrasonic.h>//BIBLIOTECA - ULTRASSONICO.
#define fita 1023


Ultrasonic ultrassom(12, 13);
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
float sensorUltra;

int pinoSensor1 = A5;
int valor1 = 0;//Sensor de Refletancia

int pinoSensor2 = A5;
int valor2 = 0;//Sensor de Refletancia

void Ultrasonico(){
  sensorUltra = ultrassom.read();// ultrassom.Ranging(CM) retorna a distancia em
  Serial.print(sensorUltra); //imprime o valor da variável distancia
  Serial.println(" cm");

 if(sensorUltra =< 20){
  
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);

 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
   }
  
}

void SensorRefletancia(){
  
  valor1 = analogRead(pinoSensor1);
  int valorCorrigido1 = valor1;
  Serial.print("refletancia:");
  Serial.println(valorCorrigido1);
  
  valor2 = analogRead(pinoSensor2);
  int valorCorrigido2 = valor2;
  Serial.print("refletancia:");
  Serial.println(valorCorrigido2);
  

  if(valorCorrigido1 =< fita){
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);

   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
  }
  if(valorCorrigido2 =< fita){
     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
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
 Ultrasonico();
 SensorRefletancia();
 //digitalWrite(IN1, HIGH);
 //digitalWrite(IN2, LOW);
 //digitalWrite(IN1, HIGH);
 //digitalWrite(IN2, HIGH);

 //digitalWrite(IN3, LOW);
 //digitalWrite(IN4, HIGH);
 //digitalWrite(IN3, HIGH);
 //digitalWrite(IN4, HIGH);
 

}
