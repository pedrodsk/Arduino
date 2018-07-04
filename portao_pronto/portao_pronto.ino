/* 
TITLE:       EMULATOR FOR HT6P20B ENCODER ON ARDUINO (only 2 Buttons)
CREATED BY:  AFONSO CELSO TURCATO
DATE:        13-JAN-2014
E-MAIL:      acturcato (at) gmail.com
LICENSE:     GPL
REV.:        01
DESCRIPTION:
http://acturcato.wordpress.com/2014/01/10/emulator-for-ht6p20b-encoder-on-arduino-board/
*/

volatile unsigned int lambda;  // desire value for Pulse Clock Width

const byte pinRF = 8;     //Pin where RF Module is connected. Change this field as pin used in your project
const byte pinButton = 2;  //Pin where Enable transmission button is connected. Change this field as pin used in your project.

void myDelay(unsigned int t)
{
  delayMicroseconds(t);
  //delay(t);  //for use on debugging
}

void sendData(char data)
{
  int pulse = (int)lambda;
  
  if(data == '0')
  {
    digitalWrite(pinRF, LOW);
    myDelay(pulse);
  
    digitalWrite(pinRF, HIGH);
    myDelay(2 * pulse);
  }
  
  if(data == '1')
  {
    digitalWrite(pinRF, LOW);
    myDelay(2 * pulse);
  
    digitalWrite(pinRF, HIGH);
    myDelay(pulse);
  }
}

void sendPilotCode()
{
  //Keep pinRF on HIGH for little time
  digitalWrite(pinRF, HIGH);
  delayMicroseconds(500);
  
  //Set pinRF on LOW for 23 Lambdas
  digitalWrite(pinRF, LOW);
  myDelay(23 * lambda);
  
  //Set pinRF on HIGH for one Lambda
  digitalWrite(pinRF, HIGH);
  myDelay(lambda);
}

void sendAddressCode(unsigned long addressCodeHEX)
{
 String addressCodeBIN = "0000000000000000000000" + String(addressCodeHEX, BIN);
 
 addressCodeBIN = addressCodeBIN.substring(addressCodeBIN.length()-22, addressCodeBIN.length());
 
 //Send all bits for Address Code
 for(int i=0; i<22; i++)
 {
   char data = addressCodeBIN[i];
   sendData(data);
 }
}

void sendDataCode(char btn1, char btn2)
{
  sendData(btn2);
  sendData(btn1);
}

void sendAntiCode()
{
  sendData('0');
  sendData('1');
  sendData('0');
  sendData('1');

  //Disable transmission
  digitalWrite(pinRF, LOW);
}

void sendAllCodes()
{
 //Toggle onboard LED
 digitalWrite(13, !digitalRead(13));
   
 //Send PILOTE CODE (details: http://acturcato.wordpress.com/2014/01/04/decoder-for-ht6p20b-encoder-on-arduino-board-english/)
 sendPilotCode();
  
 //Send ADDRESS CODE
 //A valid ADDRESS CODE can be obtained by identifying the address of an existing remote control.
 //More details on: http://acturcato.wordpress.com/2014/01/04/decoder-for-ht6p20b-encoder-on-arduino-board-english/
 sendAddressCode(0x2AF0F9);

 //Send DATA CODE of Buttons (0: OFF; 1: ON)
 sendDataCode('0', '1');  //Button1: OFF and Button2: ON

 //Send a valid ANTI-CODE
 sendAntiCode();

}

void setup()
{ 
  //Change this value according to the values ​​accepted by your RF receiver. On my tests, the values ​​between 320 and 420 were OK!
  lambda = 500;
  
  //Set IOs
  pinMode(pinButton, INPUT);
  pinMode(pinRF, OUTPUT);
  pinMode(13, OUTPUT);
  
  //Set de interrupt mode (See: http://arduino.cc/en/Reference/attachInterrupt for more details)
  attachInterrupt(0, sendAllCodes,FALLING);
  
  //Initialize serial communications at 9600 bps:
  //Serial.begin(9600);
  
  //Start pinRF on LOW (disable TX)
  digitalWrite(pinRF, LOW);
  
  //Wait a second for RF module startup
  delay(1000);
}

void loop()
{
// Nothing here!
}
