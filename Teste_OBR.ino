#include <Ultrasonic.h>
#include <Servo.h>
#include <SerialRelay.h>

#define SERVO 6
#define fita 1000
#define fita_verde_base 
#define fita_verde_max 
#define fita_prata_base 
#define fita_prata_max 

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
  sensorUltra = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
  Serial.print(sensorUltra); //imprime o valor da variável distancia
  Serial.println(" cm");

}
void SensorRefletancia(){
  valor1 = analogRead(SensorRefle1);
  Serial.print("refletancia:");
  Serial.println(valor1);

  valor2 = analogRead(SensorRefle2);
  Serial.print("refletancia:");
  Serial.println(valor2);
  
  valor3 = analogRead(SensorRefle3);
  Serial.print("refletancia:");
  Serial.println(valor3);
}
void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO);
  myservo.write(0);
  pinMode(sensorUltra, INPUT);
}

void loop(){
  Ultrasonico();
  SensorRefletancia();
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
 if(valor1 > fita && valor2 > fita)
 {
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
  if(valor1 >= fita_verde_base && valor1 <= fita_verde_max) {
  // VIRAR PARA UM LADO, ESQUERDO COM O ROBO OLHANDO PARA FRENTE.
   int i; int x;
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.  
  }
  
 }
 if(valor2 >= fita_verde_base && valor2 <= fita_verde_max) {
   // VIRAR PARA UM LADO, DIREITO COM O ROBO OLHANDO PARA FRENTE.
   int i; int x;
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
 }

 if(valor1 >= fita_verde_base && valor1 <= fita_verde_max && valor2 >= fita_verde_base && valor2 <= fita_verde_max) {
  
  //O ROBO VAI DAR UM 360 E VOLTAR PARA TRÁS.
   int i; int x;
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
 }
  
  
  
  if(valor3 <= fita_prata_max  && valor3 >= fita_prata_base){ 
    Objetivo = 2;
  }
    

  }
  if(sensorUltra <= 15)//Obstaculo.
  {
    int i;
   //ARRUMA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int x;//X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO.
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
   //ARRUMA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   x = 1000; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
   //ARRUMA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   x = 1000; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
   x = 1000; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
    x = 1000; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
   if(valor1 < fita && valor2 < fita)
 {
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
  }
   while(Objetivo == 2){
    //MODO RESGATE, 
    
 }
  
}

