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


#define luzonca 3
#define luzoncinha 4
#define luzonca1 5
#define luzteiu 6
#define luzraposa 13
#define luzgaviao 14
#define luzmacaco 15
#define luzjuiz 16
#define luzveado 17
#define motor1 7
#define motor2 8
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
myservo_2.write(0);
//attachInterrupt(0, controle, CHANGE);
Wire.begin(4);
pinMode(luzonca, OUTPUT);
pinMode(luzoncinha, OUTPUT);
pinMode(luzonca1, OUTPUT);
pinMode(luzteiu, OUTPUT);
pinMode(luzgaviao, OUTPUT);
pinMode(luzraposa, OUTPUT);
pinMode(luzmacaco, OUTPUT);
pinMode(luzjuiz, OUTPUT);
pinMode(luzveado, OUTPUT);
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
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
delay(24000);
//havia uma onca
digitalWrite(luzonca,HIGH);
fadein(60,60);
delay(1000);
fadeout(10,60);
digitalWrite(luzonca,LOW);
digitalWrite(luzoncinha,HIGH);
fadein(60,60);
delay(100);
digitalWrite(luzoncinha,LOW);
//o teiu e o cagado
digitalWrite(luzteiu,HIGH);
fadein(60,60);
delay(9500);
digitalWrite(luzonca,HIGH);
delay(10000);
digitalWrite(luzonca,LOW);
fadeout(10,60);
digitalWrite(luzteiu,HIGH);
fadein(60,60);
delay(1500);
digitalWrite(luzonca,HIGH);
delay(10500);
digitalWrite(luzonca,LOW);
delay(72000);
digitalWrite(luzteiu,LOW);
digitalWrite(luzonca,HIGH);
delay(1000);
digitalWrite(luzoncinha,HIGH);
delay(1000);
digitalWrite(luzoncinha,LOW);
digitalWrite(luzonca,LOW);
digitalWrite(luzteiu,HIGH);
delay(2000);
for(int i=0;i<5;i++){
motor0avanca(100,5);
motor2avanca(100,5);
delay(600);
motor0recua(100,5);
motor2recua(100,5);
}
delay(2000);
digitalWrite(luzonca,HIGH);
digitalWrite(luzoncinha,HIGH);
delay(10000);
digitalWrite(luzonca,LOW);

delay(5000);
fadeout(60,60);
digitalWrite(luzonca1,HIGH);
digitalWrite(luzoncinha,HIGH);
digitalWrite(luzteiu,HIGH);
digitalWrite(luzjuiz,HIGH);
digitalWrite(luzraposa,HIGH);
digitalWrite(luzveado,HIGH);
digitalWrite(luzonca,HIGH);
digitalWrite(luzgaviao,HIGH);
digitalWrite(luzmacaco,HIGH);
fadein(90,60);
fadeout(10,60);
//
//chicote
//
//venha moca
//digitalWrite(luzoncinha,HIGH);

//fadeout(10,60);
//digitalWrite(luzoncinha,LOW);
//

delay(1000000);
digitalWrite(som,LOW);



}//
//final
//delay(500);
//digitalWrite(rele4, HIGH);

 //##



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
 while(Wire.available()) // loop through all but the last
  {
 x = Wire.read(); // receive byte as a character
 if(x==1){
   start=1;
 }
}
}

