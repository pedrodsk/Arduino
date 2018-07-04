#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define carga 7
#define descarga 6
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, NEGATIVE);
long tempoAnterior = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int a=0;
void setup() {
  lcd.begin (16,2);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(A1, INPUT); //ohmimetro
  pinMode(carga,OUTPUT);
  digitalWrite(carga, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  Serial.begin(9600);
  detachInterrupt(0);
  lcd.setBacklight(LOW);
  //attachInterrupt(0, zero_cross, FALLING);
}
int x=0;
int y=0;
float feq;
float pico;
float pico2;
int r,c,l;
int Rxands =100;
int RES = 2200;
float microfarads;
float nanofarads;
void loop() {
  
  //lcd.setBacklight(LOW);
  //lcd.setCursor(0,1);
  //lcd.print("AZUL");
  //delay(100);
//funcao debounce
  if(digitalRead(3) == LOW || y==1){
    lastDebounceTime = millis();
    a=1;
  }
  if(digitalRead(4) == LOW){
    lastDebounceTime = millis();
   a=2;
   y=0;
  }
    if ((millis() - lastDebounceTime) > debounceDelay && a==1 || y==1) {
    attachInterrupt(0, zero_cross, FALLING);
    unsigned long tempo = millis();
    y=1;
    if(tempo - tempoAnterior > 1025) {
    feq = x/2;
    lcd.clear();
    Serial.print("Frequencia: ");
    pico = analogRead(14);
    //float picov = map(pico, 0.0, 1024.0, 0.0, 40.0);
    pico2 = pico*7.5 * (5.0 / 1023.0);
    Serial.println(feq);
    Serial.print("Pico ");
    Serial.println(pico2);
  lcd.setBacklight(LOW);
  lcd.setCursor(0,0);
  lcd.print("Frequencia");
  lcd.setCursor(11,0);
  lcd.print(feq);
  lcd.setCursor(0,1);
  lcd.print("Pico");
  lcd.setCursor(11,1);
  lcd.print(pico2);
    //float vp = analogRead(13);
    //float vp2 = map(vp, 0.0, 1023.0, 0.0, 95.0);
    //Serial.print("Vp: ");
    //Serial.println(vp2);
    x=0;
    tempoAnterior = tempo;
  }
  
  }
    if ((millis() - lastDebounceTime) > debounceDelay && a==2) {
    detachInterrupt(0);
    
    a=5;
    
    int leiturar = analogRead(A1);
    float tensao = (5.0 * leiturar)/1023.0;
    float Res = ((5.0*Rxands)/tensao) - Rxands;
    Serial.println(Res);

    digitalWrite(carga, HIGH);
    unsigned long Ti = millis();
    while(analogRead(A2)<648){
      }
    unsigned long Tf = millis() - Ti;
    microfarads=((float)Tf/ RES)*1000;
    if(microfarads >1){
    Serial.println(microfarads);
        }
        else{
        nanofarads = microfarads *1000;
        Serial.println(nanofarads); 
        }
        digitalWrite(carga,LOW);
        pinMode(descarga, OUTPUT);
        digitalWrite(descarga,LOW);
        while(A2>0){
          pinMode(descarga,INPUT);
          delay(300);
          }
    }
  
    
    if(Serial.available()){
      int comando = Serial.read();
      if(comando == 'z'){
        Serial.println(feq);
        Serial.println(pico2);
        Serial.println(r);
        Serial.println(c);
        Serial.println(l);
        }
    }
    lcd.setBacklight(LOW);
}
void zero_cross()  
{
  x++;
  
}
/*
 * if(Serial.available()){
  do{
  c=Serial.read();
  lerSerial[x]=c;
  y=2;
//  Serial.println(lerSerial[x]);
  x++;
  delay(1);
}while(c!='\n');
}
x=0;

int converter = atoi(lerSerial);
if(converter != 0){

 * 
 */
