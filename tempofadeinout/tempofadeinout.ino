/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <Wire.h>
#define rele1 3
#define rele2 4
#define rele3 5
#define rele4 6
#define rele5 13
#define rele6 14
#define rele7 15
#define rele8 16
#define rele9 17
#define rele10 8

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.

pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
pinMode(rele5, OUTPUT);
pinMode(rele6, OUTPUT);
pinMode(rele7, OUTPUT);
pinMode(rele8, OUTPUT);
pinMode(rele9, OUTPUT);
pinMode(rele10, OUTPUT);
Wire.begin();     
}
// the loop routine runs over and over again forever:
byte x=0;
void loop() { 
  
  //digitalWrite(rele1, HIGH);   // turn the LED on (HIGH is the voltage level)
                // wait for a second
  //digitalWrite(rele2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);
  digitalWrite(rele5, HIGH);   // turn the LED on (HIGH is the voltage level)
  fadein(80,100);
  delay(2000);
  fadeout(80,100);
  digitalWrite(rele5, LOW);
  //fadein fadeout 80/100 15 segs
  //fadein fadeout 70/100 13.5 segs
  //fadein fadeout 60/100 12 segs
  //fadein fadeout 50/100 10 segs
    //digitalWrite(rele4, HIGH);   // turn the LED on (HIGH is the voltage level)
    //digitalWrite(rele5, HIGH);   // turn the LED on (HIGH is the voltage level)
    //digitalWrite(rele6, HIGH);   // turn the LED on (HIGH is the voltage level)
    //digitalWrite(rele7, HIGH);   // turn the LED on (HIGH is the voltage level)
    //digitalWrite(rele8, HIGH);   // turn the LED on (HIGH is the voltage level)
   //digitalWrite(rele9, HIGH);   // turn the LED on (HIGH is the voltage level)
   //digitalWrite(rele10, HIGH);   // turn the LED on (HIGH is the voltage level)
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
