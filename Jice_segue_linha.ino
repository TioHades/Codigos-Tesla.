#include <Ultrasonic.h>

#define fita 980
#define Branco 970

int IN1 = 4;
int IN2 = 5;//ESQUERDA
int velocidadeA = 11;

int IN3 = 6;
int IN4 = 7;//DIREITA
int velocidadeB = 10;

Ultrasonic ultrassom(3, 2);//Varievel do tipo, Ultrassonico.

int Sensor_1 = A0;// direita
int Sensor_2 = A1; //  esquerda
int Sensor_3 = A2; // meio



float distancia;
int Led_x = 9;

int refle1 = 0;
int refle2 = 0;
int refle3 = 0;
int refle4 = 0;

void Ultrasson() {
  distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
  // centímetros(CM) ou polegadas(INC)
  Serial.print(distancia); //imprime o valor da variável distancia
  Serial.println("cm");
  delay(100);
}
void SensorRefletancia() {
  refle1 =  analogRead(Sensor_1);
  Serial.print("refletancia 1:");
  Serial.println(refle1);

  refle2 =  analogRead(Sensor_2);
  Serial.print("refletancia 2:");
  Serial.println(refle2);

  refle3 =  analogRead(Sensor_3);
  Serial.print("refletancia 3:");
  Serial.println(refle3);

  if (refle3 >= fita) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(velocidadeA, 75);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(velocidadeB, 75);
    delay(2000);
    if (refle3 <= 980) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
    }
  } if (refle3 <= 980) {//Meio
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

    
  } if(refle2 >= fita) {//esquerda
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(velocidadeA, 50);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(velocidadeB, 75);
    //delay(2000);WHOAMI
  
  } if (refle1 >= fita) {//Direita
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(velocidadeA, 75);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(velocidadeB, 50);


  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(velocidadeA, OUTPUT);
  pinMode(velocidadeB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:



  SensorRefletancia();
  Ultrasson();
}
