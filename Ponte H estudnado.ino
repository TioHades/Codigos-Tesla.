/*Pinagem do arduino*/
 
//motor_A
int IN1 = 2 ;//Entrada no Ponte H
int IN2 = 4 ;//Entrada no Ponte H
int velocidadeA = 3;//Entrada na ponte H Ativade MA.
 
//motor_B
int IN3 = 6 ;//Entrada no Ponte H
int IN4 = 7 ;//Entrada no Ponte H
int velocidadeB = 5;//Entrada na ponte H Ativade MB.
 
//variavel auxiliar
int velocidade = 0;//Variel auxilidar para velocidade
 
//Inicializa Pinos
void setup(){
pinMode(IN1,OUTPUT);//Conectando pino, com mode de saida de energia.
pinMode(IN2,OUTPUT);//Conectando pino, com mode de saida de energia.
pinMode(IN3,OUTPUT);//Conectando pino, com mode de saida de energia.
pinMode(IN4,OUTPUT);//Conectando pino, com mode de saida de energia.
pinMode(velocidadeA,OUTPUT);//Conectando pino, com mode de saida de energia.
pinMode(velocidadeB,OUTPUT);//Conectando pino, com mode de saida de energia.
}
 
void loop(){
 
/*Exemplo de velocidades no motor A*/
 
//Sentido 2
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
 
//Alta
analogWrite(velocidadeA,230);
 
//Intermediaria
analogWrite(velocidadeA,150);
 
//Baixa
analogWrite(velocidadeA,80);
 
}