#define bomba1 2
#define bomba2 4
#define vibra1 3
#define vibra2 5
#define pot 14
#define led 7
//int leitura;
//int converter;
void setup() {
pinMode(bomba1,OUTPUT);
pinMode(bomba2,OUTPUT);
pinMode(vibra1,OUTPUT);
pinMode(vibra2,OUTPUT);
pinMode(led,OUTPUT);
pinMode(pot,INPUT);
Serial.begin(9600);
}

void loop() {
  
int leitura = analogRead(pot);
int converter = map(leitura, 0, 1023, 400, 1200);
int converter2 = map(converter,400,1200,150,50);
//Serial.println(converter2);
Serial.println(leitura);
digitalWrite(vibra1,HIGH);
delay(converter);
analogWrite(vibra1,LOW);
delay(converter);
}
