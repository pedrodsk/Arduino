#include <SoftwareSerial.h>
#include <string.h>

int espTx = 2;
int espRx = 3;
SoftwareSerial ESP(espTx, espRx);

void setup() {
  Serial.begin(57600);
  ESP.begin(57600);
  delay(5000);
  conectar();

}

int x=0;
char teste[5];
char inByte;
char c;
int y;
void loop() {

  delay(200);
}
void serialEvent() {
  if (ESP.available()) {
        c = ESP.read();
       teste[x] = c;
   x++;
   delay(10);
}
}
/* 
 *  AT+CWMODE=1
 *  AT+CWJAP="LIEC_WIFI","LIEC_123"
 *  AT+CWDHCP=1,1
 *  AT+CIPSTA="10.0.0.14"
 *  AT+CIPSTATUS
 *  AT+CIPSTART="TCP","10.0.0.10",23
*

 */
 void conectar(){
  if(ESP.available()){
    /*
  ESP.print(F("AT\r\n"));
  inByte = ESP.read();
  Serial.print(inByte);
  delay(200);
*/
  
///*
   ESP.print(F("AT+CWMODE=1\r\n"));
 // inByte = ESP.read();
  //Serial.print(inByte);
  delay(500);
//*/
  
/*
  ESP.print(F("AT+CWJAP=\"LIEC_WIFI\",\"LIEC_123\"\r\n"));
  inByte = ESP.read();
  Serial.print(inByte);
  delay(500);
*/

///*
  ESP.print(F("AT+CWDHCP=1,1\r\n"));
 // inByte = ESP.read();
 // Serial.print(inByte);
  delay(500);
//*/

///*
  ESP.print(F("AT+CIPSTA=\"10.0.0.14\"\r\n"));
 // inByte = ESP.read();
 // Serial.print(inByte);
  delay(500);

//*/

///*
  ESP.print(F("AT+CIPSTART=\"TCP\",\"10.0.0.13\",23\r\n"));
 // inByte = ESP.read();
 // Serial.print(inByte);
  delay(500);
 ESP.print(F("AT+CIPSEND=20\r\n"));
 // inByte = ESP.read();
 // Serial.print(inByte);
  delay(500);
  ESP.print(F("ola, conectei! PING."));

//*/
//x=2;
  }
 }
 

