/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
#include <IRremote.h>
#include <NECIRrcv.h>
#include <TimerOne.h>
int led=14;
int RECV_PIN = 3;
int y=0;
unsigned long codeValue;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(12, OUTPUT);
 Timer1.initialize(300000);
//attachInterrupt(0, controle, CHANGE);
Timer1.attachInterrupt(controle);
}

void loop() {
//controle();
for(int i=0;i<10000;i++){
 Serial.println(i);
delay(1000);

}

}


//FUNCOES

//FUNCAO CONTROLE
void controle()
{
if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 16761405){
     digitalWrite(led,HIGH);
      y=0;
         }
if(results.value == 16756815){
    digitalWrite(led,LOW);
    
    y=2;
    while(y==2){
      Timer1.attachInterrupt(controle);
      irrecv.resume();
      if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 3041548455){
     digitalWrite(led,HIGH);
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


