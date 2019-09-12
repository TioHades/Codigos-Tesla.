#include <Ultrasonic.h>
#include <Servo.h>
#include <SerialRelay.h>

#define SERVO 6
#define fita 1000
#define fita_verde 
#define fita_prata 

Ultrasonic ultrassom(12, 13);//Varievel do tipo, Ultrassonico.
Servo myservo;//Variavel do tipo Servo.
float sensorUltra;//Sensor Ultrassonico.
int pos;//varievel posição do servo.


const byte NumModules = 1;
SerialRelay relays(4,5,NumModules); 

int SensorRefle1 = A5;
int SensorRefle2 = A4;
int SensorRefle3 = A3;

int Objetivo = 1;
int valor1 = 0;
int valor2 = 0;
int valor3 = 0;


void Ultrasonico() {
  sensorUltra = ultrassom.read();// ultrassom.Ranging(CM) retorna a distancia em
  Serial.print(sensorUltra); //imprime o valor da variável distancia
  Serial.println(" cm");
}
void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO);
  myservo.write(0);
}

void loop(){
  Ultrasonico();
  while(Objetivo == 1){
    if(valor1 < fita && valor2 < fita)
 {
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
 if(valor1 > fita && valor2 < fita)//Se o valor não estiver entre FITA_1 E FITA_2 Motor parar.
 {
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_OFF,1);
 }
  if(valor1 < fita && valor2 > fita)//Se o valor não estiver entre FITA_1 E FITA_2 Motor parar.
 {
   relays.SetRelay(1, SERIAL_RELAY_OFF,1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);
 }
 if(valor1 > fita && valor2 > fita){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
 // if(valor1 = fita_verde && ) {
  
// }
// if(valor1 = fita_verde && ) {
  
// }
// if(valor1 = fita_verde &&) {
  //if(valor1 < fita_prata && valor2 ><){ Obejetivo = 2;}
 } 
while(Objetivo == 2){
  
 
 
  }
  
}
