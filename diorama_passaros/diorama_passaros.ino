/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <Wire.h>
#define som 2
#define grupoA 3//arara azul
#define grupoB 4//periquito cara suja
#define grupoC 5//aguia
#define grupoD 6//jagucana
#define grupoE 14
#define grupoF 13
#define grupoGH 15
#define grupoI 16
#define grupoJ 17
//#define rele10 8
#define selA 9
#define enable 10
#define selB 8
#define selC 7
//#define motor2 10
//#define motor3 11
int start=0;
int start2=0;
int m=0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
pinMode(som, OUTPUT);
pinMode(grupoA, OUTPUT);//arara azul
pinMode(grupoB, OUTPUT);//jandai testa vermelha
pinMode(grupoC, OUTPUT);//aguia
pinMode(grupoD, OUTPUT);//jagu
pinMode(grupoE, OUTPUT);//bicudo
pinMode(grupoF, OUTPUT);//pintassilgo
pinMode(grupoGH, OUTPUT);//maria
pinMode(grupoI, OUTPUT);//formigueiro
pinMode(grupoJ, OUTPUT);//jow chick
pinMode(selA, OUTPUT);
pinMode(selB, OUTPUT);
pinMode(selC, OUTPUT);
pinMode(enable, OUTPUT);
pinMode(som, OUTPUT);
Wire.onReceive(teste);
//pinMode(rele10, OUTPUT);
Wire.begin(8);     
}

// the loop routine runs over and over again forever:
byte x=0;
void loop() {
delay(300); 

while(m==1){
digitalWrite(grupoA, HIGH);
delay(1000);
digitalWrite(grupoB, HIGH);
delay(1000);
digitalWrite(grupoC, HIGH);
delay(1000);
digitalWrite(grupoD, HIGH);
delay(1000);
digitalWrite(grupoE, HIGH);
delay(1000);
digitalWrite(grupoF, HIGH);
delay(1000);
digitalWrite(grupoGH, HIGH);
delay(1000);
digitalWrite(grupoI, HIGH);
fadein(200,70);
delay(60000);
fadeout(200,70);
digitalWrite(grupoA, LOW);
delay(1000);
digitalWrite(grupoB, LOW);
delay(1000);
digitalWrite(grupoC, LOW);
delay(1000);
digitalWrite(grupoD, LOW);
delay(1000);
digitalWrite(grupoE, LOW);
delay(1000);
digitalWrite(grupoF, LOW);
delay(1000);
digitalWrite(grupoGH, LOW);
delay(1000);
digitalWrite(grupoI, LOW);

//mudar de cenario
for(int o=0;o<10;o++) {
        Wire.beginTransmission(6); // transmit to device #4
        x = 2;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);  
      }
      m=0;
      delay(1000);
      m=0;
  }
while(start==1){
  //sincronização
delay(3000);
  digitalWrite(som, HIGH);
  delay(115000);//113500
  digitalWrite(grupoA, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(50,100);
  delay(5800);
   digitalWrite(grupoA, LOW);    // turn the LED off by making the voltage LOW
   digitalWrite(grupoB, HIGH);   // turn the LED on (HIGH is the voltage level)
  //fadein(50,100);
  delay(6000);
  fadeout(50,100);  
  //delay(2000);
  digitalWrite(grupoB, LOW);    // turn the LED off by making the voltage LOW
  delay(2500);
  digitalWrite(grupoC, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(60,100);
  //delay(2000);
  digitalWrite(grupoD, HIGH);
  fadeout(30,100);
  digitalWrite(grupoC, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(grupoD, LOW);
  //digitalWrite(grupoD, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  //fadein(30,100);
  //delay(2000);
  //fadeout(30,100);
  //delay(2000);
      // turn the LED off by making the voltage LOW
  delay(4000);
  digitalWrite(grupoE, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(150,100);
  delay(15000);
  //fadeout(80,100);
  //delay(2000);
      // turn the LED off by making the voltage LOW
  delay(7000);
  fadeout(60,100);
  digitalWrite(grupoE, LOW);
  digitalWrite(grupoF, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(230,100);
  delay(3500);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoF, LOW);    // turn the LED off by making the voltage LOW
  //digitalWrite(grupoE, LOW);
  //delay(2000);
  digitalWrite(grupoGH, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(80,100);
  //delay(3000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoGH, LOW);    // turn the LED off by making the voltage LOW
  
  
  digitalWrite(grupoI, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(200,100);
  delay(3000);
  fadeout(200,100);
  //delay(2000);
  digitalWrite(grupoI, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoJ, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(50,100);
 // delay(200);
digitalWrite(grupoJ, LOW);  

digitalWrite(enable, HIGH);

//gravata
digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
fadeout(70,100);
//delay(2000);
    // turn the LED off by making the voltage LOW

//fadein(30,100);
//fadeout(30,100);
//delay(3000);
//fadeout(30,100);

//onca
digitalWrite(selA,HIGH);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
fadein(100,100);
//delay(2000);

delay(2000);
//gato
digitalWrite(selA,LOW);
digitalWrite(selB,HIGH);
digitalWrite(selC,LOW);
delay(4000);
//delay(2000);
fadeout(80,100);

//macaco
digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,HIGH);
//delay(3000);
fadein(80,100);
//macaco 2
digitalWrite(selA,LOW);
digitalWrite(selB,HIGH);
digitalWrite(selC,HIGH);
delay(1000);
fadeout(80,100);

//delay(3000);
//fadein(60,100);
//delay(2000);
//fadeout(60,100);



//morcegos
digitalWrite(selA,HIGH);
digitalWrite(selB,LOW);
digitalWrite(selC,HIGH);
//delay(3000);
fadein(70,100);
//delay(2000);
fadeout(70,100);

//tatu
digitalWrite(selA,HIGH);
digitalWrite(selB,HIGH);
digitalWrite(selC,HIGH);

//delay(3000);
fadein(50,100);
//delay(2000);
fadeout(50,100);

//besouro
digitalWrite(selA,HIGH);
digitalWrite(selB,HIGH);
digitalWrite(selC,LOW);

//delay(3000);
fadein(80,100);
delay(5000);
fadeout(40,100);


digitalWrite(enable, LOW);
digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
digitalWrite(grupoA, HIGH);
digitalWrite(grupoB, HIGH);
digitalWrite(grupoC, HIGH);
digitalWrite(grupoD, HIGH);
digitalWrite(grupoE, HIGH);
digitalWrite(grupoF, HIGH);
digitalWrite(grupoGH, HIGH);
digitalWrite(grupoI, HIGH);
fadein(275,90);
fadeout(275,90);
digitalWrite(grupoA, LOW);
digitalWrite(grupoB, LOW);
digitalWrite(grupoC, LOW);
digitalWrite(grupoD, LOW);
digitalWrite(grupoE, LOW);
digitalWrite(grupoF, LOW);
digitalWrite(grupoGH, LOW);
digitalWrite(grupoI, LOW);

//delay(25000);
//elay(20000);
digitalWrite(som,LOW);
Wire.beginTransmission(10); // transmit to device #4
byte z=1;
Wire.write(z);              // sends one byte  
delay(5);
Wire.endTransmission(10);
start=0;
}
}
void fadein(int tempo, int potencia)
 {
   for(int i=10;i<potencia;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
 Wire.endTransmission(4);
    delay(tempo);
   } 
}//fim fadein

void fadeout(int tempo, int potencia)
 {
 for(int i=potencia;i>10;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
  Wire.endTransmission(4);
  delay(tempo);
}
 }
 void teste(int howMany) 
{ 
x = Wire.read(); // receive byte as an integer 
if (x == 1) 
{ 
start=1;
}
if (x == 2) 
{  
m=1;
}
}


