#include <Servo.h> 
 

Servo myservo_5;
int pos = 0;    
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
myservo_5.attach(11);
}

byte x=0;

void loop()
{
  //###RELE1
  digitalWrite(rele1,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
   delay(40);
  }
  for(pos = 0; pos < 180; pos += 1)   
  {
  myservo_5.write(pos);
  delay(30);
}
for(pos = 180; pos > 0; pos -= 1)   
  {
  myservo_5.write(pos);
  delay(30);
}
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
digitalWrite(rele1,LOW);
 //##

 //###RELE2
  digitalWrite(rele2,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
 Wire.endTransmission(4);
    delay(40);
  
}
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
digitalWrite(rele2,LOW);
 //##
 //###RELE3
  digitalWrite(rele3,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
digitalWrite(rele3,LOW);
 //##
 //###RELE4
  digitalWrite(rele4,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
digitalWrite(rele4,LOW);
 //##
 //###RELE5
  digitalWrite(rele5,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
digitalWrite(rele5,LOW);
 //##
 //###RELE6
  digitalWrite(rele6,HIGH);
  for(int i=5;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  Wire.endTransmission(4);
  delay(40);
}
for(int i=100;i>5;i--){
  x=i;
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(2);
  
  delay(40);
}
delay(3000);
Wire.endTransmission(4);
digitalWrite(rele6,LOW);
 //##
 
 
}
