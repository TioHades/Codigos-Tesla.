#include <Ultrasonic.h>//Bibliotecas, e-mail.
#include <Servo.h>//Bibliotecas, e-mail.
#include <SerialRelay.h>//Bibliotecas, e-mail.

#define SERVO 6//Porta Do servo
#define fita 1000//Refletancia da fita preta
#define fita_verde_base //Colocar a refletancia minina da fita verde
#define fita_verde_max //Colocar a refletancia maxima da fita verde
#define fita_prata_base //Colocar a refletancia minina da fita prata
#define fita_prata_max //Colocar a refletancia maxima da fitra prata

Ultrasonic ultrassom(12, 13);//Varievel do tipo, Ultrassonico.
Servo myservo;//Variavel do tipo Servo.
float sensorUltra;//Sensor Ultrassonico.
int pos;//varievel posição do servo.


const byte NumModules = 1;//Quantidades de Reles
SerialRelay relays(4,5,NumModules); //Porta do rele, Data e Clock

int SensorRefle1 = A5;//Porta do sensor de refletancia. Direito
int SensorRefle2 = A4;//Porta do sensor de refletancia. Esquerdo
int SensorRefle3 = A3;//Porta do sensor de refletancia. Meio

//VARIAVEIS AUXILIARES
int Objetivo = 1;
int valor1 = 0;
int valor2 = 0;
int valor3 = 0;
//VARIAVEIS AUXILIARES

void Ultrasonico() {//Função para o Ultrassonico
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
  pinMode(sensorUltra, INPUT);//Vinculando o sensorUltra como entrada de dados
}

void loop(){
  Ultrasonico();//Chamando a função do Ultrassonico
  SensorRefletancia();
  while(Objetivo == 1){{//Objetivo 1, Seguir a linha e desviar de obstaculos
  if(valor1 < fita && valor2 < fita)//Enguanto os sensores do meio não tiverem vendo a fita motor ON.
 {
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
 }
 if(valor1 > fita && valor2 < fita)//Se um dos lados sentir a fita preta, Ajustar o motor para deixar a fita no meio.
 {
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_OFF,1);
 }
  if(valor1 < fita && valor2 > fita)//Se um dos lados sentir a fita preta, Ajustar o motor para deixar a fita no meio.
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
  if(valor1 >= fita_verde_base && valor1 <= fita_verde_max) {//ISSO E PARA QUANDO TIVER UMA FITA VERDE VIRAR PARA UM LADO
  // VIRAR PARA UM LADO, ESQUERDO COM O ROBO OLHANDO PARA FRENTE.
   int i; int x;//X EO TEMPO QUE ELE VAI FICAR ANDANDO, ESSE IF E DOS VÃO, TEM 15CM. AJUSTAR O X PARA SE FOR MAIOR QUE 15  ACONTECEU ALGUM ERRO.
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.  
  }
  
 }
 if(valor2 >= fita_verde_base && valor2 <= fita_verde_max) {//ISSO E PARA QUANDO TIVER UMA FITA VERDE VIRAR PARA UM LADO
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
   x = 10; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
   //ARRUMA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   x = 10; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
   for(i = 0; i < x; i++){
   relays.SetRelay(1, SERIAL_RELAY_OFF, 1);   // Vai abrir a porta do Rele para a energia passar.
   delay(1);
   relays.SetRelay(2, SERIAL_RELAY_ON, 1);   // Vai abrir a porta do Rele para a energia passar.
   }
   x = 10; //X EO TEMPO QUE VAI FICAR RODANDO, EU NÃO SEI O QUANTO DEMORAR E NEM SE, SE EU COLOCAR 1000, VAI SER 1 SEGUNDO. 
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

  
}
     while(Objetivo == 2){//Se o robor sentir a fita prata passar para o objetivo 2.
    //MODO RESGATE, 
    
 }
  
}
