#include <Wire.h>
#include <IRremote.h>
#include <NECIRrcv.h>
#include <TimerOne.h>
//variaveis
#define rele1 3
#define rele2 4
#define rele3 5
#define rele4 6
#define rele5 7
#define rele6 8
#define rele7 9
#define rele8 10

int power1;
int led=13;
int RECV_PIN = 2;
int y=0;
unsigned long codeValue;
IRrecv irrecv(RECV_PIN);
decode_results results;
byte x=1;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Wire.begin();
  pinMode(12, OUTPUT);
 //Timer1.initialize(60);
 //Timer1.attachInterrupt(controle);
  attachInterrupt(0, controle, CHANGE);
 //dimmer
pinMode(rele1, OUTPUT);
digitalWrite(rele1, LOW);
pinMode(rele2, OUTPUT);
digitalWrite(rele2, LOW);
pinMode(rele3, OUTPUT);
digitalWrite(rele3, LOW);
pinMode(rele4, OUTPUT);
digitalWrite(rele4, LOW);
pinMode(rele5, OUTPUT);
digitalWrite(rele5, LOW);
pinMode(rele6, OUTPUT);
digitalWrite(rele6, LOW);
pinMode(rele7, OUTPUT);
digitalWrite(rele7, LOW);
pinMode(rele8, OUTPUT);
digitalWrite(rele8, LOW);
}


void loop() {
 digitalWrite(rele4, HIGH);
digitalWrite(rele5, HIGH);
digitalWrite(rele6, HIGH);
for(int i=0;i<50;i++){
 power1=i;
 Wire.beginTransmission(2); 
  Wire.write(power1);               
  Wire.endTransmission(2);
 delay(60);
}
for(int i=50;i>0;i--){
 power1=i;
 Wire.beginTransmission(2); 
  Wire.write(power1);               
  Wire.endTransmission(2);
 delay(60);
}
}


//FUNCOES

//FUNCAO CONTROLE
void controle()
{
if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 3041548455){
     digitalWrite(led,LOW);
      y=0;
      //play escravo
      //Wire.beginTransmission(4);
      //Wire.write(1);
      //Wire.endTransmission(4);
      //play escravo
         }
if(results.value == 3041532645){
    digitalWrite(led,HIGH);
    y=2;
    while(y==2){
     //pausa escravo
      //Wire.beginTransmission(4);
      //Wire.write(2);

      //Wire.endTransmission(4);
      //fim pausa escravo
      
      irrecv.resume();
      if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 3041548455){
     digitalWrite(led,LOW);
      y=0;
         }
      }
      //Serial.println("teste");
      delay(400);
    }
   
  }
    irrecv.resume(); // Receive the next value
}
}
//FUNCAO CONTROLE FIM
//FUNCAO DIMMER

