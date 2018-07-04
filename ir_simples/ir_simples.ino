/*
 * IRremote: IRrecvDump - dump details of IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 */

#include <IRremote.h>

int RECV_PIN = 11;
int x=0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,OUTPUT);
  
}


void loop() {
  
if (irrecv.decode(&results)&&x==0) {
  irrecv.resume();
    Serial.println(results.value);
    if(results.value == 16236607){
      digitalWrite(13,HIGH);
      irrecv.resume();
      x=1;
      } 
}
 if (irrecv.decode(&results)&&x==1) {
  irrecv.resume();
    Serial.println(results.value);
    if(results.value == 16236607){
      digitalWrite(13,LOW);
      irrecv.resume();
      x=0;
      } 
}
}
