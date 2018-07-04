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
#define luzteju 6
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
myservo_2.write(180);
//attachInterrupt(0, controle, CHANGE);
Wire.begin(2);
pinMode(luzonca, OUTPUT);
pinMode(luzoncinha, OUTPUT);
pinMode(luzonca1, OUTPUT);
pinMode(luzteju, OUTPUT);
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
delay(26000);
//uma vez
digitalWrite(luzgaviao,HIGH);
fadein(60,60);//4000
delay(14000);
fadeout(10,60);
digitalWrite(luzgaviao,LOW);
//a comade raposa
digitalWrite(luzraposa,HIGH);
fadein(60,60);
delay(4000);
fadeout(10,60);
digitalWrite(luzraposa,LOW);
//eu quero meu queijo
digitalWrite(luzgaviao,HIGH);
fadein(60,60);
delay(4000);
fadeout(10,60);
digitalWrite(luzgaviao,LOW);
//que queijo, eh meu
digitalWrite(luzraposa,HIGH);
fadein(60,60);
delay(5000);
fadeout(10,60);
digitalWrite(luzraposa,LOW);
//apanhei na fazenda
digitalWrite(luzgaviao,HIGH);
fadein(60,60);
delay(2000);//dps
fadeout(10,60);
digitalWrite(luzgaviao,LOW);
//vamos resolver na justica
digitalWrite(luzraposa,HIGH);
fadein(60,60);
delay(6000);
fadeout(10,60);
digitalWrite(luzraposa,LOW);
//o juiz era o guaximin
digitalWrite(luzjuiz,HIGH);
for(int i=10;i<50;i++){
 x=i;
 Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(5);
 Wire.endTransmission(4);
    delay(50);
   }
delay(3000);
digitalWrite(luzmacaco,HIGH);
digitalWrite(luzjuiz,LOW);
delay(2000);
digitalWrite(luzmacaco,LOW);
digitalWrite(luzjuiz,HIGH);

//va e pegue a balaca
delay(4000);
digitalWrite(luzmacaco,HIGH);
delay(6000);//1:39
digitalWrite(luzmacaco,LOW);
delay(4000);
fadeout(50,50);
digitalWrite(luzjuiz,LOW);
fadein(50,50);
digitalWrite(luzmacaco,HIGH);
delay(11000);
digitalWrite(luzjuiz,HIGH);
digitalWrite(luzmacaco,LOW);
delay(22000);
digitalWrite(luzjuiz,LOW);
digitalWrite(luzmacaco,HIGH);
delay(12000);
digitalWrite(luzjuiz,HIGH);
digitalWrite(luzmacaco,HIGH);
fadein(60,60);
delay(1000);
fadeout(60,60);
digitalWrite(luzjuiz,LOW);
digitalWrite(luzmacaco,LOW);
digitalWrite(luzraposa,HIGH);
digitalWrite(luzgaviao,HIGH);
fadein(60,60);
delay(2000);
fadeout(60,60);
digitalWrite(luzgaviao,LOW);
digitalWrite(luzraposa,HIGH);
fadein(60,60);

delay(5000);
digitalWrite(luzraposa,LOW);
digitalWrite(luzjuiz,HIGH);
delay(5000);
for(int i=0;i<5;i++){
motor1avanca(140,5);
delay(1000);
motor1recua(140,5);
}

//cortou o queijo em 2 pedacos
digitalWrite(luzjuiz,HIGH);
fadein(50,60);
delay(300);
fadeout(10,60);
digitalWrite(luzjuiz,LOW);
digitalWrite(luzmacaco,HIGH);
fadein(60,60);
delay(100);
fadeout(10,60);
digitalWrite(luzmacaco,LOW);

//pediu a faca cortou e deu ao macaco
digitalWrite(luzjuiz,HIGH);
fadein(60,60);
delay(8000);
fadeout(10,60);
digitalWrite(luzjuiz,LOW);
digitalWrite(luzmacaco,HIGH);
fadein(60,60);
delay(1);
fadeout(10,60);
digitalWrite(luzmacaco,LOW);

//e assim
digitalWrite(luzjuiz,HIGH);
fadein(60,60);
delay(8000);
fadeout(10,60);
digitalWrite(luzmacaco,HIGH);
fadein(60,60);
delay(1);
fadeout(10,60);
digitalWrite(luzmacaco,LOW);
//no fim
digitalWrite(luzraposa,HIGH);
fadein(60,60);
delay(3200);
fadeout(10,60);
digitalWrite(luzgaviao,HIGH);
//automacao e frase final
digitalWrite(luzjuiz,HIGH);
fadein(60,60);
delay(6200);
fadeout(10,60);
digitalWrite(luzjuiz,LOW);
for(int i=0;i<2;i++){
motor0avanca(100,5);
delay(600);
motor0recua(100,5);
}

digitalWrite(som,LOW);
delay(1000);


}

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

