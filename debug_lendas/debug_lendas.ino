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
int m=0;
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
//#define cooler 20
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
//pinMode(cooler, OUTPUT);
Wire.onReceive(teste);
//Timer1.initialize(300000);
//Timer1.attachInterrupt(controle);
//digitalWrite(12,LOW);
//pinMode(rele7, OUTPUT);
//pinMode(rele8, OUTPUT);
//myservo_5.attach(11);
}
int te=0;
byte x=0;
int start=0;
void loop()
{
delay(300);   
  while(m==1){
digitalWrite(rele1, HIGH);
delay(1000);
digitalWrite(rele2, HIGH);
delay(1000);
digitalWrite(rele3, HIGH);
delay(1000);
digitalWrite(rele4, HIGH);
delay(1000);
digitalWrite(rele5, HIGH);
delay(1000);
digitalWrite(rele6, HIGH);
delay(1000);
digitalWrite(rele7, HIGH);
fadein(200,70);
digitalWrite(charuto, HIGH);
delay(60000);
fadeout(200,70);
digitalWrite(rele1, LOW);
delay(1000);
digitalWrite(rele2, LOW);
delay(1000);
digitalWrite(rele3, LOW);
delay(1000);
digitalWrite(rele4, LOW);
delay(1000);
digitalWrite(rele5, LOW);
delay(1000);
digitalWrite(rele6, LOW);
delay(1000);
digitalWrite(rele7, LOW);
delay(1000);
digitalWrite(charuto, LOW);

delay(60000);
//mudar de cenario
for(int o=0;o<10;o++) {
        Wire.beginTransmission(8); // transmit to device #4
        x = 2;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);  
      }
      m=0;
      delay(1000);
      m=0;
  }
  
  while(start==1){
digitalWrite(fumaca,HIGH);
digitalWrite(charuto,HIGH);
digitalWrite(rele3, HIGH);
digitalWrite(rele4, HIGH);
if(te==0){
  Wire.beginTransmission(4); // transmit to device #4
  x=60;
  Wire.write(x);
  delay(5);
 Wire.endTransmission(4);
  delay(10000);
  te=1;
}
  }
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
//start=1;
m=1;
}
}


