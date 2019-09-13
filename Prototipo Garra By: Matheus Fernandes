#include <Servo.h>
  
int servobase = 10; 
int servobraco = 9; 
int servobraco_altura = 12; 
int servogarra = 13; 
  
int potbase = 0; 
int potbraco = 1;
int potbraco_altura = 2; 
int potgarra = 3; 

int base_pos = 0; 
int braco_pos = 0;
int braco_pos_altura = 0;
int garra_pos = 0;

Servo base; 
Servo braco;
Servo braco_altura;
Servo garra;

void setup(){
 //Configura os servo motores com seus pinos.
  Serial.begin(9600);

  base.attach(servobase);
  braco.attach(servobraco);
  braco_altura.attach(servobraco_altura);
  garra.attach(servogarra); 

  // Define a posição inicial do braço. 
  base.write(90);
  braco.write(90);
  braco_altura.write(90);
  garra.write(30);
}

void loop() {
  delay(100);
  base_pos=analogRead(potbase); 
  base_pos=map(base_pos,0,1024,0,178);
  base.write(base_pos); 
  delay(100); 
  
 braco_pos=analogRead(potbraco);
 braco_pos=map(angulobraco,0,1024,0,178);
  braco.write(angulobraco); 
  delay(100);
  braco_pos_altura=analogRead(potbraco_altura);
  braco_pos_altura=map(angulobraco_altura,0,1024,0,178);
  braco_altura.write(angulobraco_altura); 
  delay(100);
  garra_pos=analogRead(potgarra);
  garra_pos=map(garra_pos,0,1024,0,40);
  garra.write(garra_pos); 
  delay(100);
}
