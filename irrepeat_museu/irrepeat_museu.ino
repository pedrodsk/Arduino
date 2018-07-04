#include <Wire.h>
#include <IRremote.h>
IRsend irsend;
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
int y=0;
void setup()
{
irrecv.enableIRIn(); 
//irrecv.blink13(true);
pinMode(13,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
digitalWrite(13,LOW);
//Serial.begin(9600);
Wire.begin(10);
//attachInterrupt(0, controle, CHANGE);
}
byte x=0;


void loop()

{

if (irrecv.decode(&results)) {
  irrecv.resume();
  //power
    if(results.value == 0x0FFA25D){
      irsend.sendNEC(0x0FFA25D, 32);
      delay(300);
     //digitalWrite(13,HIGH);
        if(y==0){
        i2c(6,1);
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        y=1;
        } 
        else{
        //i2c(6,1);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        y=0;
        }
      }//pause
    if(results.value == 0x0FFC23D){
      irsend.sendNEC(0x0FFC23D, 32);
      delay(300);
      digitalWrite(13,LOW);
                }
                //recuar
        if(results.value == 0x0FF22DD){
      irsend.sendNEC(0x0FF22DD, 32);
      delay(300);
      digitalWrite(13,LOW);
                }
                //avancar
                if(results.value == 0x0FF02FD){
      irsend.sendNEC(0x0FF02FD, 32);
      delay(300);
      digitalWrite(13,LOW);
                }//volume-
                if(results.value == 0x0FFE01F){
      irsend.sendNEC(0x0FFE01F, 32);
      delay(50);
      digitalWrite(13,LOW);
                }//volume+
                if(results.value == 0x0FFA857){
      irsend.sendNEC(0x0FFA857, 32);
      delay(50);
      digitalWrite(13,LOW);
                }//1                
                if(results.value == 0x0FF30CF){
      irsend.sendNEC(0x0FF30CF, 32);
      delay(300);
      digitalWrite(13,LOW);
                }//2
                if(results.value == 0x0FF18E7){
      irsend.sendNEC(0x0FF18E7, 32);
      delay(300);
      digitalWrite(13,LOW);
                }//3
                if(results.value == 0x0FF7A85){
      irsend.sendNEC(0x0FF7A85, 32);
      delay(300);
      digitalWrite(13,LOW);
                }//4
                if(results.value == 0x0FF10EF){
      irsend.sendNEC(0x0FF10EF, 32);
      delay(300);
      digitalWrite(13,LOW);
                }
    irrecv.enableIRIn();
  }
}

void i2c(int w,int v){
  Wire.beginTransmission(w); // transmit to device #4
  Wire.write(v);              // sends one byte  
  delay(5);
 Wire.endTransmission(w);
}
