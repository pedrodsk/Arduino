#define bomba1 0 //vinho
#define bomba2 1
#define led A3
#define beep A2 
#define pot A1
//#define led1 2
//#define led2 3
//boolean estado1 = 0;
//boolean estado2 = 0;
//long tempoAnterior1 = 0;
//long intervalo1 = 1000;
//long tempoAnterior2 = 0;
//long intervalo2 = 800;
//int leitura;
//int converter;
void setup() {
pinMode(bomba1,OUTPUT);
pinMode(bomba2,OUTPUT);
pinMode(led,OUTPUT);
pinMode(beep,OUTPUT);
digitalWrite(bomba1, LOW);
digitalWrite(bomba2, LOW);
digitalWrite(beep, LOW);
digitalWrite(led, LOW);
//pinMode(led1,OUTPUT);
//pinMode(led2,OUTPUT);
pinMode(pot,INPUT);
//Serial.begin(9600);
}
int y=1;
void loop() {
unsigned long tempo = millis();
int leitura = analogRead(pot);
//1200ms = 50 batimentos por minuto
//400ms = 120 batimentos por minuto
int converter = map(leitura, 0, 1023, 600, 1200);
if (y==1){
  delay(2000);
  analogWrite(bomba1,150);
  delay(50);
  analogWrite(bomba2,150);
  delay(4000);
  analogWrite(bomba2,LOW);
  analogWrite(bomba1,LOW);
  y=2;
}
if(tempo > 60000 && converter < 1140)
{
  y=1;
}
if(converter < 1140){
  digitalWrite(led,HIGH);
  analogWrite(bomba1,100);
  delay(30);
  analogWrite(bomba2,80);
  for(int x=0;x<5;x++){
  digitalWrite(beep,HIGH);
  delayMicroseconds(2);
  digitalWrite(beep,LOW);
  }
  delay(350);
  digitalWrite(bomba1,LOW);
  digitalWrite(bomba2,LOW);
  delay(150);
  digitalWrite(led,LOW);
  
  delay(converter-500);
   }
    }

