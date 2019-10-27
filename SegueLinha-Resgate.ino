//Codigo By: Colgate, Mattheus F. e Cadu.
#include <Ultrasonic.h>//Bibliotecas, e-mail.
//#include <Servo.h>//Bibliotecas, e-mail.
//#include <SerialRelay.h>//Bibliotecas, e-mail.

#define fita 1000
#define fita_verde_base 120
#define fita_verde_max 100
#define fita_prata_base 50
#define fita_prata_max 150

Ultrasonic ultrassom(12, 13);//Varievel do tipo, Ultrassonico.

int Objetivo = 0;

//Variaveis do Sensor de Refletancia{}
int Sensor_1 = A0;
int Sensor_2 = A1;
int Sensor_3 = A2;
int Sensor_4 = A3;
int Led_1 = 8;//AMARELO
int Led_2 = 6;// VERMELHO
int forca_refle1 = 0;
int forca_refle2 = 0;
int forca_refle3 = 0;
int forca_refle4 = 0;
//Variaveis do Sensor de Refletancia}

//Variaveis do Sensor Ultrassonico{
float distancia;
int Led_x=9;
//Variaveis do sensor Ultasoonico}

//Variaveis para Testar Os leds
int led_1=10;
int led_2=7;
//Variaveis para Testar Os Leds

void ParaTestarOsLeds(){//Esse void e para testar se os leds estao funcionado.
  digitalWrite(led_1, HIGH);
  delay(1000);
  digitalWrite(led_1, LOW);
  delay(1000);
  digitalWrite(led_2, HIGH);
  delay(1000);
  digitalWrite(led_2, LOW);
  delay(1000);
}
void Ultrasson(){
  distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
  // centímetros(CM) ou polegadas(INC)
  Serial.print(distancia); //imprime o valor da variável distancia
  Serial.println("cm");
  delay(100);
}

void SensorRefletancia(){
        forca_refle1 =  analogRead(Sensor_1);
    Serial.print("refletancia:");
Serial.println(forca_refle1);

        forca_refle2 =  analogRead(Sensor_1);
    Serial.print("refletancia:");
Serial.println(forca_refle2);

        forca_refle3 =  analogRead(Sensor_1);
    Serial.print("refletancia:");
Serial.println(forca_refle3);

        forca_refle4 =  analogRead(Sensor_1);
    Serial.print("refletancia:");
Serial.println(forca_refle4);
}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    ParaTestarOsLeds();
    Objetivo = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
    Ultrasson();
    SensorRefletancia();

 while(Objetivo == 1)
{
    CODIGO SEGUE LINHA
  

}
 while(Objetivo == 2)
{
  Codigo resgate
  
  
     
}
}