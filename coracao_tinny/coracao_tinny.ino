#define bomba1 A3
#define bomba2 A2
#define vibra1 1
#define vibra2 0
#define pot A1
//#define led1 2
//#define led2 3
boolean estado1 = 0;
boolean estado2 = 0;
long tempoAnterior1 = 0;
long intervalo1 = 1000;
long tempoAnterior2 = 0;
long intervalo2 = 800;
//int leitura;
//int converter;
void setup() {
pinMode(bomba1,OUTPUT);
pinMode(bomba2,OUTPUT);
pinMode(vibra1,OUTPUT);
pinMode(vibra2,OUTPUT);
digitalWrite(bomba1, LOW);
digitalWrite(bomba2, LOW);
digitalWrite(vibra1, LOW);
digitalWrite(vibra2, LOW);
//pinMode(led1,OUTPUT);
//pinMode(led2,OUTPUT);
pinMode(pot,INPUT);
//Serial.begin(9600);
}

void loop() {
unsigned long tempo = millis();
int leitura = analogRead(pot);
//1200ms = 50 batimentos por minuto
//400ms = 120 batimentos por minuto
int converter = map(leitura, 0, 1023, 400, 1200);
if(converter < 1150){
  digitalWrite(bomba1,HIGH);
  delay(50);
  digitalWrite(bomba2,HIGH);
  for(int x=0;x<15;x++)
  {
  analogWrite(vibra1,x);
  analogWrite(vibra2,x);
  delay(5); //+75
  }
  digitalWrite(bomba1,LOW);
  delay(50);
  digitalWrite(bomba2,LOW);
  for(int x=15;x<30;x++)
  {
  analogWrite(vibra1,x);
  analogWrite(vibra2,x);
  delay(5); //+75
  }
  //int converter2=converter/30;
  for(int x=30;x>0;x--)
  {
  analogWrite(vibra1,x);
  analogWrite(vibra2,x);
  delay(5); //+150
  }
  delay(converter-400);
  
  }
    }

