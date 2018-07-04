#include <Servo.h> 
#include <IRremote.h>
#include <NECIRrcv.h>
#include <Wire.h>
//#include <TimerOne.h>
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
//#define rele7 9
//#define rele8 10
void setup()
{
irrecv.enableIRIn();  
attachInterrupt(0, controle, CHANGE);
Wire.begin();
digitalWrite(8,LOW);
pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
pinMode(rele5, OUTPUT);
pinMode(rele6, OUTPUT);
pinMode(rele7, OUTPUT);
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
//###rabo ianga
digitalWrite(rele1,HIGH);
fadein(80,100);
delay(3000);
fadeout(80,100);
delay(1000);
digitalWrite(rele1,LOW);
digitalWrite(rele2,HIGH);
fadein(80,100);
delay(3000);
fadeout(80,100);
delay(1000);
digitalWrite(rele2,LOW);
digitalWrite(rele3,HIGH);
fadein(80,100);
delay(3000);
fadeout(80,100);
delay(1000);
digitalWrite(rele3,LOW);
digitalWrite(rele4,HIGH);
fadein(80,100);
delay(3000);
fadeout(80,100);
delay(1000);
digitalWrite(rele4,LOW);
digitalWrite(rele5,HIGH);
fadein(80,100);
delay(3000);
fadeout(80,100);
delay(1000);
digitalWrite(rele5,LOW);
digitalWrite(rele6,HIGH);
fadein(80,100);
delay(3000);
fadeout(80,100);
delay(1000);
digitalWrite(rele6,LOW);
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
  for(pos = 90; pos < a; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_0.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor avanca
  void motor0recua(int a, int t){
  for(pos = a; pos > 90; pos -= 1)  // goes from 0 degrees to 180 degrees 
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
  for(pos = a; pos > 1; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor recua
  void motor2avanca(int a,int t){
  for(pos = 0; pos < a; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor avanca
  void motor2recua(int a, int t){
  for(pos = a; pos > 1; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(t);
  }
  }//fim motor recua
// funcao 
void controle(){
  
    if(irrecv.decode(&results)){ 
      if(results.value == 16753245){//power
     start=1;
     irrecv.resume();  
     }
       irrecv.resume();
    
    
       //if(results.value == 16756815){//play
     //start=1;
       //}
       
       if(results.value == 16761405){//pause
     pause=1;
     while(pause==1){
       Timer1.attachInterrupt(controle);
       irrecv.resume();
      if (irrecv.decode(&results)) {
      if(results.value == 16761405){ 
      pause=0; 
      }
    }
  }
         }
    
}
}

