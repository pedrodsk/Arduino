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
#define grupoE 13
#define grupoF 14
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
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
pinMode(som, OUTPUT);
pinMode(grupoA, OUTPUT);
pinMode(grupoB, OUTPUT);
pinMode(grupoC, OUTPUT);
pinMode(grupoD, OUTPUT);
pinMode(grupoE, OUTPUT);
pinMode(grupoF, OUTPUT);
pinMode(grupoGH, OUTPUT);
pinMode(grupoI, OUTPUT);
pinMode(grupoJ, OUTPUT);
pinMode(selA, OUTPUT);
pinMode(selB, OUTPUT);
pinMode(selC, OUTPUT);
pinMode(enable, OUTPUT);
Wire.onReceive(teste);
//pinMode(rele10, OUTPUT);
Wire.begin(8);     
}

// the loop routine runs over and over again forever:
byte x=0;
void loop() {
 //while(start==0){
 //delay(50);
  //}
  
  digitalWrite(som, HIGH);
  delay(15000);
  digitalWrite(grupoA, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(60,100);
  //delay(2000);
  digitalWrite(grupoA, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoB, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);  
  //delay(2000);
  digitalWrite(grupoB, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoC, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoC, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoD, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoD, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoE, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoE, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoF, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoF, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoGH, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoGH, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoI, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoI, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(grupoJ, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(30,100);
  //delay(2000);
  fadeout(30,100);
  //delay(2000);
  digitalWrite(grupoJ, LOW);    // turn the LED off by making the voltage LOW
  

digitalWrite(enable, HIGH);

//gravata
digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
fadein(30,100);
//fadeout(30,100);
//delay(3000);
fadeout(30,100);

//onca
digitalWrite(selA,HIGH);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
//delay(3000);
fadein(30,100);
fadeout(30,100);

//gato
digitalWrite(selA,LOW);
digitalWrite(selB,HIGH);
digitalWrite(selC,LOW);
//delay(3000);
fadein(30,100);
fadeout(30,100);


//macaco
digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,HIGH);
//delay(3000);
fadein(30,100);
fadeout(30,100);

//macaco 2
digitalWrite(selA,LOW);
digitalWrite(selB,HIGH);
digitalWrite(selC,HIGH);
//delay(3000);
fadein(30,100);
fadeout(30,100);



//morcegos
digitalWrite(selA,HIGH);
digitalWrite(selB,LOW);
digitalWrite(selC,HIGH);
//delay(3000);
fadein(30,100);
fadeout(30,100);

//tatu
digitalWrite(selA,HIGH);
digitalWrite(selB,HIGH);
digitalWrite(selC,HIGH);

//delay(3000);
fadein(30,100);
fadeout(30,100);

//besouro
digitalWrite(selA,HIGH);
digitalWrite(selB,HIGH);
digitalWrite(selC,LOW);

//delay(3000);
fadein(30,100);
fadeout(30,100);
digitalWrite(enable, LOW);
delay(1000);
digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
/*
Wire.beginTransmission(10); // transmit to device #4
byte z=0;
Wire.write(z);              // sends one byte  
delay(5);
Wire.endTransmission(10);
start=0;
*/
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

}
}

