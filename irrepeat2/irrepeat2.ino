#include <IRremote.h>
IRsend irsend;
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
irrecv.enableIRIn(); 
//irrecv.blink13(true);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
Serial.begin(9600);
//attachInterrupt(0, controle, CHANGE);
}
int x=1;
void loop()

{
 
if (irrecv.decode(&results)) {
  irrecv.resume();
    if(results.value == 0x0FFA25D){
Serial.println(x);
      //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x0FFA25D, 32);
      delay(100);
      
         // irsend.sendNEC(0x040BF00FF, 32);
     digitalWrite(13,HIGH);
    
    
    }
    if(results.value == 0x0FFE21D){

      //for (int i = 0; i < 20; i++) {
      irsend.sendNEC(0x0FFE21D, 32);
      delay(100);
      digitalWrite(13,LOW);
         // irsend.sendNEC(0x040BF00FF, 32);
     //digitalWrite(13,HIGH);
    
        }
    //int i=0;
    //x++;
    irrecv.enableIRIn();
  }
}

