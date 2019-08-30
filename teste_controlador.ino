int controlar = 7;


void setup() {
  // put your setup code here, to run once:
pinMode(controlar, OUTPUT);
digitalWrite(controlar, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(controlar, LOW);
delay(1000);
digitalWrite(controlar, HIGH);
delay(1000);
}
