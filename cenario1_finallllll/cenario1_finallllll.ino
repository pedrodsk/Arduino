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
#define som 2
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
Wire.begin(2);
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
 
  while(start==0){
 delay(50);
  }
 // digitalWrite(rele7,HIGH);
digitalWrite(som,HIGH);
delay(68500);
digitalWrite(fumaca,HIGH);
//###rabo ianga
digitalWrite(rele1,HIGH);
fadein(70,100);
delay(25);
fadeout(10,100);
digitalWrite(rele1,LOW);
//###cabeca ianga
digitalWrite(rele2,HIGH);
 fadein(15,100);
delay(100);
fadeout(15,100);
digitalWrite(rele2,LOW);
delay(100);
//alternar cabeca/rabo
for(int i=0;i<3;i++){
digitalWrite(rele1,HIGH);
  fadein(25,80);
  fadeout(25,80);
digitalWrite(rele1,LOW);

digitalWrite(rele2,HIGH);
  fadein(16,80);
  fadeout(13,80);
}
digitalWrite(rele2,LOW);
delay(1000);
//luz do caipora
delay(10000);

digitalWrite(rele4, HIGH);
fadein(60,100);
delay(900);
//fadeout(30,100);


//
//luz do porco

digitalWrite(rele3, HIGH);
//fadein(30,100);
delay(5000);
digitalWrite(charuto,HIGH);
delay(15000);

fadeout(90,100);
digitalWrite(rele4, LOW);
digitalWrite(rele3, LOW);
digitalWrite(charuto,LOW);
digitalWrite(fumaca,LOW);
//
//luz do curupira
delay(15000);
digitalWrite(rele5, HIGH);
//digitalWrite(rele6, HIGH);
for(int i=10;i<40;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
 Wire.endTransmission(4);
    delay(90);
}
delay(15000);
for(int i=40;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
 Wire.endTransmission(4);
    delay(90);
}
delay(25000);
for(int h=0; h<3;h++)
{
motor1avanca(100,10);
motor1recua(100,10);
}

for(int h=0; h<2;h++)
{
  motor1avanca(100,10);
  //digitalWrite(13,LOW);
  digitalWrite(rele6, HIGH);
  motor2avanca(80,5);
  
  //digitalWrite(13,HIGH);
  motor1recua(100,10);
  //digitalWrite(12,LOW);
  //motor2avanca(80,5);
  motor2recua(80,5);
  //igitalWrite(13,HIGH);
  }
fadeout(25,100);
digitalWrite(rele5, LOW);
digitalWrite(rele6, LOW);
//
//luz da florzinha
digitalWrite(rele7, HIGH);
for(int i=10;i<35;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
 Wire.endTransmission(4);
    delay(90);
}
delay(10000);
for(int i=35;i<100;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
 Wire.endTransmission(4);
    delay(90);
}
delay(25500);
for(int i=0;i<5;i++){
motor0avanca(140,5);
delay(600);
motor0recua(140,5);
}
fadeout(50,100);
digitalWrite(rele7, LOW);
digitalWrite(rele1, HIGH);
digitalWrite(rele2, HIGH);
digitalWrite(rele3, HIGH);
digitalWrite(rele4, HIGH);
digitalWrite(rele5, HIGH);
digitalWrite(rele6, HIGH);
digitalWrite(rele7, HIGH);
fadein(120,60);
delay(14000);
fadeout(120,60);
digitalWrite(rele1, LOW);
digitalWrite(rele2, LOW);
digitalWrite(rele3, LOW);
digitalWrite(rele4, LOW);
digitalWrite(rele5, LOW);
digitalWrite(rele6, LOW);
digitalWrite(rele7, LOW);
delay(4000);
digitalWrite(som,LOW);
Wire.beginTransmission(10); // transmit to device #4
Wire.write(1);              // sends one byte  
delay(5);
Wire.endTransmission(10);
start=0;

//
//final
//delay(500);
//digitalWrite(rele4, HIGH);

} //##

//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes
//funcoes

//funcoes
//funcoes
//funcoes
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
  delay(tempo);
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
x = Wire.read(); // receive byte as an integer 
if (x == 1) 
{ 
start=1;
}
if (x == 2) 
{

}
}


