//#include <Servo.h> 
 

//Servo myservo_5;
//int pos = 0;    
//
#include <Wire.h>
#define rele1 12
#define rele2 3
#define rele3 4
#define rele4 5
#define rele5 6
#define rele6 7
#define rele7 9
#define rele8 10
void setup()
{
Wire.begin(); // join i2c bus (address optional for master)
digitalWrite(8,LOW);
pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
pinMode(rele5, OUTPUT);
pinMode(rele6, OUTPUT);
pinMode(rele7, OUTPUT);
pinMode(rele8, OUTPUT);
//myservo_5.attach(11);
}

byte x=0;

void loop()
{
/* //###rabo ianga
digitalWrite(rele5,HIGH);
fadein(30,50);
delay(6000);
fadeout(10,100);
digitalWrite(rele5,LOW);
//###cabeca ianga
digitalWrite(rele4,HIGH);
 fadein(50,100);
delay(6000);
fadeout(10,100);
digitalWrite(rele4,LOW);
//alternar cabeca/rabo
for(int i=0;i<3;i++){
digitalWrite(rele5,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
 Wire.endTransmission(4);
    delay(5);
  
}
//delay(6000);
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(5);
  
}
digitalWrite(rele5,LOW);
digitalWrite(rele4,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
 Wire.endTransmission(4);
    delay(5);
  
}
//delay(6000);
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(5);
  
}
digitalWrite(rele4,LOW);
}
//luz do porco
digitalWrite(rele2, HIGH);
fadein(10,100);
delay(6000);
fadeout(10,100);
digitalWrite(rele2, LOW);
//
//luz do caipora
digitalWrite(rele3, HIGH);
fadein(10,100);
delay(6000);
fadeout(10,100);
digitalWrite(rele3, LOW);
//
//luz do curupira
digitalWrite(rele6, HIGH);
fadein(10,100);
delay(6000);
fadeout(10,100);
digitalWrite(rele6, LOW);
//
//luz da florzinha
digitalWrite(rele1, HIGH);
fadein(10,100);
delay(6000);
fadeout(10,100);
digitalWrite(rele1, LOW);
//
//
*/
//final
Wire.beginTransmission(4); // transmit to device #4
  Wire.write(100);              // sends one byte  
  delay(5);
  Wire.endTransmission(4);
  
digitalWrite(rele4, HIGH);
digitalWrite(rele5, HIGH);
digitalWrite(rele2, HIGH);
digitalWrite(rele3, HIGH);
digitalWrite(rele6, HIGH);
digitalWrite(rele1, HIGH);
//digitalWrite(rele1, LOW);
//digitalWrite(rele2, LOW);
//digitalWrite(rele3, LOW);
//digitalWrite(rele4, LOW);
//digitalWrite(rele5, LOW);
//digitalWrite(rele6, LOW);

} //##

/*

//funcoes
 void fadein(int tempo, int potencia)
 {
   for(int i=10;i<potencia;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
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
  delay(2);
  Wire.endTransmission(4);
  delay(70);
}
}//fim fadeout

*/
