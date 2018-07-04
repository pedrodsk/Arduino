#include <Wire.h>
#include <IRremote.h>
#define feed 6
IRsend irsend;
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
int y=0;
int start=0;
int q=15000;
int m=0;
void setup()
{

irrecv.enableIRIn(); 
//irrecv.blink13(true);
pinMode(13,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(6,OUTPUT);
digitalWrite(13,LOW);
//Serial.begin(9600);
Wire.begin(10);
//attachInterrupt(0, controle, CHANGE);

Wire.onReceive(teste);
}
byte x=0;
void loop()
{
//  digitalWrite(feed,HIGH);
  if(y==0){
   delay(2000); 
  digitalWrite(7,HIGH);//som
  delay(3000);
  digitalWrite(8,HIGH);//pc
  delay(4000);
  for(int t=0;t<3;t++){
  digitalWrite(feed,LOW);
  delay(200);
  digitalWrite(feed,HIGH);
delay(200);  
}
 
  irsend.sendNEC(0xFFC23D,32);
   delay(40);
   irrecv.enableIRIn();
        
  
 y=1;
 irrecv.resume();
  }
  if(start==1){
    digitalWrite(7,LOW);
    delay(1000);
    digitalWrite(8,LOW);
    delay(1000);//2000
    y=0;
    start=0;
  }
if (irrecv.decode(&results)) {
  irrecv.resume();
    if(results.value == 0x0FFA25D){
      digitalWrite(feed,HIGH);
      delay(200);
      digitalWrite(feed,LOW);
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
          m=0;
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
       if(results.value == 0x0FFE01F && m==0){
      irsend.sendNEC(0x0FFE01F, 32);
      irrecv.enableIRIn();
            //digitalWrite(13,LOW);
                }
                //volume+
       if(results.value == 0x0FFA857 && m==0){
      irsend.sendNEC(0x0FFA857, 32);
      irrecv.enableIRIn();
      //delay(50);
      //digitalWrite(13,LOW);
                }//1
        if(results.value == 0x0FF30CF && m==0){ 
   digitalWrite(feed,LOW);       
        //digitalWrite(7,HIGH);
        //delay(30);
        delay(100);
       // digitalWrite(8,HIGH);
        //delay(q);
        irsend.sendNEC(0xFF30CF,32);
        delay(40);
        irrecv.enableIRIn();
        delay(2500);
        
               delay(2500);
        
      for(int o=0;o<10;o++) {
        Wire.beginTransmission(8); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);
        }  
              }
                //2
      if(results.value == 0x0FF18E7 && m==0){
      digitalWrite(feed,LOW);
        delay(100);
      //digitalWrite(7,HIGH);
        //delay(100);
        //digitalWrite(8,HIGH);
        //delay(q);
        irsend.sendNEC(0xFF18E7,32);
        delay(40);
        irrecv.enableIRIn();
        delay(2500);
        
        for(int o=0;o<10;o++) {
        Wire.beginTransmission(6); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);
        }
                //digitalWrite(13,LOW);
                }
                //3
      if(results.value == 0x0FF7A85 && m==0){
        digitalWrite(feed,LOW);
        //digitalWrite(7,HIGH);
        delay(100);
        //digitalWrite(8,HIGH);
        //delay(q);
        irsend.sendNEC(0xFF7A85,32);
        delay(40);
        irrecv.enableIRIn();
                delay(2500);
                
      for(int o=0;o<10;o++) {
        Wire.beginTransmission(2); // transmit to device #4
        x = 1;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);
        }  
              }
                //9
                if(results.value == 0xFF52AD && m==0){
                  m=1;
                  for(int t=0;t<5;t++){
  digitalWrite(feed,LOW);
  delay(200);
  digitalWrite(feed,HIGH);
  delay(200);
  }
  digitalWrite(feed,LOW);
      for(int o=0;o<10;o++) {
        Wire.beginTransmission(8); // transmit to device #4
        x = 2;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(8);  
      }
                        }//fim 4
                        //5
                /*if(results.value == 0xFF38C7 && m==0){
                  m=1;
      for(int o=0;o<10;o++) {
        Wire.beginTransmission(6); // transmit to device #4
        x = 2;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(6);  
      }
                        }//fim 5
                        //6
                if(results.value == 0xFF5AA5 && m==0){
                  m=1;
      for(int o=0;o<10;o++) {
        Wire.beginTransmission(2); // transmit to device #4
        x = 2;
        Wire.write(x);              // sends one byte  
        delay(5);
        Wire.endTransmission(2);  
      }
                        }//fim 6
*/
  
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
}
