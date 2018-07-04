//#include <Servo.h> 
 

//Servo myservo_5;
//int pos = 0;    
//
#include <Wire.h>
#define rele1 2
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
 //###rabo ianga
  digitalWrite(rele5,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
 Wire.endTransmission(4);
    delay(70);
  
}
delay(6000);
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(70);
  
}
digitalWrite(rele5,LOW);
//###final rele 5
//###cabeca ianga
  
  digitalWrite(rele4,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
 Wire.endTransmission(4);
    delay(70);
  
}
delay(6000);
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(30);
  
}
digitalWrite(rele4,LOW);
//###final rele 4
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
delay(15000);

} //##
 
