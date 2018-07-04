#define tempo 493
#define tx 8
void setup() {
pinMode(3,INPUT);
digitalWrite(3,HIGH);
attachInterrupt(0, codigos,LOW);
pinMode(tx,OUTPUT);
pinMode(13,OUTPUT);
}
//codigo do controle 2AF0F9  10 1010 1111 0000 1111 1001
void loop() {
//apertar o botao

}
//
void startbit(){
digitalWrite(tx,HIGH); //tempo em 1 
//delayMicroseconds(500);
delay(100);

digitalWrite(tx,LOW); //enviar 0
delayMicroseconds(23*tempo); //23x500;

digitalWrite(tx,HIGH); //enviar 1
delayMicroseconds(tempo);
               }
  
void dado(int x){
if(x == 0)
  {
    digitalWrite(tx, LOW);
    delayMicroseconds(tempo);
    digitalWrite(tx, HIGH);
    delayMicroseconds(2*tempo);
  }
  
  if(x == 1)
  {
    digitalWrite(tx, LOW);
    delayMicroseconds(2*tempo);
    digitalWrite(tx, HIGH);
    delayMicroseconds(tempo);

  }
                 }

void controle(){
//0
digitalWrite(tx, LOW);
delayMicroseconds(tempo);
digitalWrite(tx, HIGH);
delayMicroseconds(2*tempo);
//1
digitalWrite(tx, LOW);
delayMicroseconds(2*tempo);
digitalWrite(tx, HIGH);
delayMicroseconds(tempo);
}

void anti(){
//0
digitalWrite(tx, LOW);
delayMicroseconds(tempo);
digitalWrite(tx, HIGH);
delayMicroseconds(2*tempo);
//1
digitalWrite(tx, LOW);
delayMicroseconds(2*tempo);
digitalWrite(tx, HIGH);
delayMicroseconds(tempo);
//0
digitalWrite(tx, LOW);
delayMicroseconds(tempo);
digitalWrite(tx, HIGH);
delayMicroseconds(2*tempo);
//1
digitalWrite(tx, LOW);
delayMicroseconds(2*tempo);
digitalWrite(tx, HIGH);
delayMicroseconds(tempo);
}
void codigos(){
detachInterrupt(0);
digitalWrite(13, !digitalRead(13));
startbit();
//sendPilotCode();
//sendAddressCode(0x2AF0F9);

dado(1);
dado(0);
dado(1);
dado(0);
dado(1);
dado(0);
dado(1);
dado(1);
dado(1);
dado(1);
dado(0);
dado(0);
dado(0);
dado(0);
dado(1);
dado(1);
dado(1);
dado(1);
dado(1);
dado(0);
dado(0);
dado(1);

controle();
//sendDataCode('0', '1');
//sendAntiCode();
anti();
attachInterrupt(0, codigos,LOW);
}
/*
void sendData(char data)
{
  int pulse = (int)tempo;
  
  if(data == '0')
  {
    digitalWrite(tx, LOW);
    delayMicroseconds(tempo);
  
    digitalWrite(tx, HIGH);
    delayMicroseconds(2* tempo);
  }
  
  if(data == '1')
  {
    digitalWrite(tx, LOW);
    delayMicroseconds(2*tempo);
  
    digitalWrite(tx, HIGH);
    delayMicroseconds(tempo);
  }
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
  digitalWrite(tx, LOW);
}
void sendPilotCode()
{
  //Keep pinRF on HIGH for little time
  digitalWrite(tx, HIGH);
  delayMicroseconds(500);
  
  //Set pinRF on LOW for 23 Lambdas
  digitalWrite(tx, LOW);
  delayMicroseconds(23*tempo);
  
  //Set pinRF on HIGH for one Lambda
  digitalWrite(tx, HIGH);
  delayMicroseconds(tempo);
}
*/
