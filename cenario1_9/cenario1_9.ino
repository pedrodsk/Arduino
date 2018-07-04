#include <Servo.h> 
#include <IRremote.h>
#include <NECIRrcv.h>
#include <Wire.h>
#include <TimerOne.h>
Servo myservo_0;
Servo myservo_1;
Servo myservo_2;
int pos = 0; 
int RECV_PIN = 2;
int t=0;
int pause=0;
IRrecv irrecv(RECV_PIN);
decode_results results;
//


#define rele1 3
#define rele2 4
#define rele3 5
#define rele4 6
#define rele5 13
#define rele6 14
#define rele7 15
#define charuto 7
#define fumaca 8
#define som 16
#define cooler 20
//#define rele7 9
//#define rele8 10
void setup()
{
irrecv.enableIRIn();  
myservo_0.attach(9);
myservo_0.write(0);
myservo_1.attach(10);
myservo_1.write(0);
myservo_2.attach(11);
myservo_2.write(180);
//attachInterrupt(0, controle, CHANGE);
Wire.begin();
pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
pinMode(rele5, OUTPUT);
pinMode(rele6, OUTPUT);
pinMode(rele7, OUTPUT);
pinMode(charuto, OUTPUT);
pinMode(fumaca, OUTPUT);
pinMode(som, OUTPUT);
pinMode(cooler, OUTPUT);
Wire.onReceive(teste);
//Timer1.initialize(300000);
//Timer1.attachInterrupt(controle);
//digitalWrite(12,LOW);
//pinMode(rele7, OUTPUT);
//pinMode(rele8, OUTPUT);
//myservo_5.attach(11);
}

byte x=0;
int start=0;
void loop()
{
 
  //while(start==0){
 //delay(50);
  //}
digitalWrite(som,HIGH);
digitalWrite(fumaca,HIGH);
//###rabo ianga
digitalWrite(rele1,HIGH);
fadein(80,100);
delay(6000);
fadeout(80,100);
digitalWrite(rele1,LOW);
//###cabeca ianga
digitalWrite(rele2,HIGH);
 fadein(5,100);
delay(6000);
fadeout(5,100);
digitalWrite(rele2,LOW);
delay(100);
//alternar cabeca/rabo
for(int i=0;i<3;i++){
digitalWrite(rele1,HIGH);
  fadein(1,50);
  fadeout(1,50);
digitalWrite(rele1,LOW);

digitalWrite(rele2,HIGH);
  fadein(1,50);
  fadeout(1,50);
digitalWrite(rele2,LOW);
}
//luz do porco
digitalWrite(charuto,HIGH);
digitalWrite(rele3, HIGH);
fadein(30,100);
delay(6000);
fadeout(30,100);
digitalWrite(rele3, LOW);
//
//luz do caipora

digitalWrite(rele4, HIGH);
fadein(30,100);
delay(6000);
fadeout(30,100);
digitalWrite(rele4, LOW);
digitalWrite(charuto,LOW);
digitalWrite(fumaca,LOW);
//
//luz do curupira
digitalWrite(rele5, HIGH);
digitalWrite(rele6, HIGH);
fadein(30,100);
for(int h=0; h<3;h++)
{
  motor1avanca(100,10);
  //digitalWrite(13,LOW);
  motor2avanca(80,5);
  
  //digitalWrite(13,HIGH);
  motor1recua(100,10);
  //digitalWrite(12,LOW);
  //motor2avanca(80,5);
  motor2recua(80,5);
  //igitalWrite(13,HIGH);
  }
fadeout(30,100);
digitalWrite(rele5, LOW);
digitalWrite(rele6, LOW);
//
//luz da florzinha
digitalWrite(rele7, HIGH);
fadein(30,100);
delay(6000);
for(int i=0;i<5;i++){
motor0avanca(140,5);
delay(600);
motor0recua(140,5);
}
fadeout(50,100);
digitalWrite(rele7, LOW);
digitalWrite(som,LOW);
delay(10000);
//
//final
//delay(500);
//digitalWrite(rele4, HIGH);

} //##



//funcoes
void fadefixo(int g, int tempo)
 {
   
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(g);              // sends one byte  
  delay(2);
 Wire.endTransmission(4);
    delay(tempo);
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
  delay(70);
}
 }//fimdateout
//funcao motor avanca
void motor0avanca(int a,int t){
  for(pos = 0; pos < a; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_0.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor avanca
  void motor0recua(int a, int t){
  for(pos = a; pos > 0; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_0.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor recua
  void motor1avanca(int a,int t){
  for(pos = 0; pos < a; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor avanca
  void motor1recua(int a, int t){
  for(pos = a; pos > 0; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor recua
  void motor2avanca(int a,int t){
  for(pos = 180; pos > a; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor avanca
  void motor2recua(int a, int t){
  for(pos = a; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor recua
// funcao 
void teste(int howMany)
{
 while(Wire.available()) // loop through all but the last
  {
 x = Wire.read(); // receive byte as a character
 if(x==1){
   start=1;
 }
}
}

