#include <EEPROM.h>
#define reed1 2 
#define reed2 3
#define reed3 4
#define reed4 5
#define reed5 6 
#define reed6 7
#define reed7 8
#define reed8 9


#define cabecaf A0
#define cabecat A1
#define bracoef A2
#define bracoet A3
#define bracodf A4
#define bracodt A5
#define rabof 11
#define rabot 12
#define olhos 10
byte pos1;
byte pos2;
byte pos3;
byte pos4;
int addr1=10;
int addr2=20;
int addr3=30;
int addr4=40;
byte val;
//char comando;

void setup()  
{
  pinMode(reed1, INPUT);
  pinMode(reed2, INPUT);
  pinMode(reed3, INPUT);
  pinMode(reed4, INPUT);
  pinMode(reed5, INPUT);
  pinMode(reed6, INPUT);
  pinMode(reed7, INPUT);
  pinMode(reed8, INPUT);
  
  pinMode(cabecaf, OUTPUT);
  pinMode(cabecat, OUTPUT);
  pinMode(bracoef, OUTPUT);
  pinMode(bracoet, OUTPUT);
  pinMode(bracodf, OUTPUT);
  pinMode(bracodt, OUTPUT);
  pinMode(rabof, OUTPUT);
  pinMode(rabot, OUTPUT);

digitalWrite(reed1, HIGH);
digitalWrite(reed2, HIGH);
digitalWrite(reed3, HIGH);
digitalWrite(reed4, HIGH);
digitalWrite(cabecaf, LOW);
digitalWrite(cabecat, LOW);
digitalWrite(bracoef, LOW);
digitalWrite(bracoet, LOW);
digitalWrite(bracodf, LOW);
digitalWrite(bracodt, LOW);
digitalWrite(rabof, LOW);
digitalWrite(rabot, LOW);

pos1 = EEPROM.read(10);
pos2 = EEPROM.read(20);
pos3 = EEPROM.read(30);
pos4 = EEPROM.read(40);
}

void loop() // run over and over
{
 
}
void calibrar(){
  if(pos1==0){
  while(reed1==HIGH){
    digitalWrite(cabecaf,HIGH);
    digitalWrite(cabecat,LOW);
    EEPROM.write(10, 1);
    if(reed1==LOW)
    {
    digitalWrite(cabecaf,LOW);
    digitalWrite(cabecat,LOW);
  }
  }
  }
  if(pos1==1){
  while(reed1==HIGH){
    digitalWrite(cabecaf,LOW);
    digitalWrite(cabecat,HIGH);
    EEPROM.write(10, 0);
    if(reed1==LOW)
    {
    digitalWrite(cabecaf,LOW);
    digitalWrite(cabecat,LOW);
  }
  }
  }
  
  while(reed2==HIGH){
    digitalWrite(bracoef,HIGH);
    digitalWrite(bracoet,LOW);
    if(reed2==LOW)
    {
    digitalWrite(bracoef,LOW);
    digitalWrite(bracoet,LOW);
  }
  }
  while(reed3==HIGH){
    digitalWrite(bracodf,HIGH);
    digitalWrite(bracodt,LOW);
    if(reed3==LOW)
    {
    digitalWrite(bracodf,LOW);
    digitalWrite(bracodt,LOW);
  }
  }
  while(reed4==HIGH){
    digitalWrite(rabof,HIGH);
    digitalWrite(rabot,LOW);
    if(reed4==LOW)
    {
    digitalWrite(rabof,LOW);
    digitalWrite(rabot,LOW);
  }
  }
}//fim calibrar
void cabecaesquerda(){
 digitalWrite(cabecaf,HIGH);
 digitalWrite(cabecat,LOW);
 delay(1000);
 digitalWrite(cabecaf,LOW);
 digitalWrite(cabecat,LOW);
     }
void cabecadireita() {
 digitalWrite(cabecaf,LOW);
 digitalWrite(cabecat,HIGH);
 delay(1000);
 digitalWrite(cabecaf,LOW);
 digitalWrite(cabecat,LOW);
     }
