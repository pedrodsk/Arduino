#include <SoftwareSerial.h>
int espTx = 2;
int espRx = 3;
char lerSerial[22]="";
//char c;
int x;
SoftwareSerial ESP(espTx, espRx);
void setup() {
  Serial.begin(57600);
  ESP.begin(57600);
  delay(5000);
  conectar();

}

void loop() {
  // read from port 1, send to port 0:
  int t;
  if (ESP.available()) {
   char inByte = ESP.read();
   //lerSerial[x] = c;
   //x++;
   //delay(10);
    Serial.print(inByte);
    //Serial.print(lerSerial);
    //Serial.print(lerSerial);
    //Serial.print(lerSerial);
    //delay(10);
     }
  

  // read from port 0, send to port 1:
  if (Serial.available()) {
    char inByte = Serial.read();
    ESP.print(inByte);
//  }
}
}/*
void serialEvent() {
 
   char c = ESP.read();
   lerSerial[x] = c;
   x++;
   delay(10);

}
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

  
