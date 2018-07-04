#include <Wire.h>
#include <IRremote.h>
IRsend irsend;
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
int y=0;
int start=0;
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

Wire.onReceive(teste);
}
byte x=0;
void loop()
{
  if(y==0){
  digitalWrite(8,HIGH);
 y=1;
 irrecv.resume();
  }
  if(start==1){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(2000);
    y=0;
    start=0;
  }
if (irrecv.decode(&results)) {
  irrecv.resume();
    if(results.value == 0x0FFA25D){
      //irrecv.enableIRIn();
      //irsend.sendNEC(0x0FFA25D, 32);
      //delay(300);
        //if(y==0){
        //i2c(2,1);
        //digitalWrite(7,HIGH);
        //digitalWrite(8,HIGH);
        //y=1;
        //} 
        //else{
          start=1;
        //}
      }
      //pause
    //if(results.value == 0x0FFC23D){
     // irsend.sendNEC(0x0FFC23D, 32);
      //delay(300);
      //digitalWrite(13,LOW);
        //        }
                //recuar
        //if(results.value == 0x0FF22DD){
      //irsend.sendNEC(0x0FF22DD, 32);
      //delay(300);
      //digitalWrite(13,LOW);
                //}
                //avancar
        //        if(results.value == 0x0FF02FD){
      //irsend.sendNEC(0x0FF02FD, 32);
      //delay(300);
      //digitalWrite(13,LOW);
               // }//volume-
       if(results.value == 0x0FFE01F){
      irsend.sendNEC(0x0FFE01F, 32);
      irrecv.enableIRIn();
            //digitalWrite(13,LOW);
                }
                //volume+
       if(results.value == 0x0FFA857){
      irsend.sendNEC(0x0FFA857, 32);
      irrecv.enableIRIn();
      //delay(50);
      //digitalWrite(13,LOW);
                }//1
        if(results.value == 0x0FF30CF){        
        digitalWrite(7,HIGH);
        delay(100);
        digitalWrite(8,HIGH);
        delay(12000);
        irsend.sendNEC(0x0FF30CF, 32);
        irrecv.enableIRIn();
        delay(100);
        irsend.sendNEC(0x0FF30CF, 32);
        irrecv.enableIRIn();
        delay(100);
        irsend.sendNEC(0x0FF30CF, 32);
        irrecv.enableIRIn();
        delay(2500);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
                }
                //2
      if(results.value == 0x0FF18E7){
      
      digitalWrite(7,HIGH);
        delay(100);
        digitalWrite(8,HIGH);
        delay(12000);
        irsend.sendNEC(0x0FF18E7, 32);
        irrecv.enableIRIn();
        delay(100);
        irsend.sendNEC(0x0FF18E7, 32);
        irrecv.enableIRIn();
        delay(100);
        irsend.sendNEC(0x0FF18E7, 32);
        irrecv.enableIRIn();
        delay(2500);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
                //digitalWrite(13,LOW);
                }
                //3
      if(results.value == 0x0FF7A85){
      
      //delay(300);
      //  digitalWrite(7,LOW);
      //  delay(100);
      //  digitalWrite(8,LOW);
      //  delay(1000);
        digitalWrite(7,HIGH);
        delay(100);
        digitalWrite(8,HIGH);
        delay(12000);
        irsend.sendNEC(0x0FF7A85, 32);
        irrecv.enableIRIn();
        delay(100);
        irsend.sendNEC(0x0FF7A85, 32);
        irrecv.enableIRIn();
        delay(100);
        irsend.sendNEC(0x0FF7A85, 32);
        irrecv.enableIRIn();
        delay(2500);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
      //digitalWrite(13,LOW);
                }
                //4
             //   if(results.value == 0x0FF10EF){
      //irsend.sendNEC(0x0FF10EF, 32);
      //delay(300);
      //digitalWrite(13,LOW);
        //        }
    //irrecv.enableIRIn();
}
}
void i2c(int w,byte v){
  Wire.beginTransmission(w); // transmit to device #4
  Wire.write(v);              // sends one byte  
  delay(5);
 Wire.endTransmission(w);
}
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
