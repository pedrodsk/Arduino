/*
 * Assim cada bit será transmitido em 1500 us.
 * O código completo compreende 4 partes principais: Piloto, Endereço, Dado e Anti-Código.
– O Piloto é formado por 23 ciclos de “0” e um ciclo de “1”.
– O Endereço é formado por 22 bits (66 ciclos);
– O Dado é formado por 2 bits (6 ciclos).
– O Anti-Código é formado por 4 bits (12 ciclos) sendo sempre “0101”.

 * 
 */
#include <VirtualWire.h> 
#define tempo 500
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
delayMicroseconds(500);

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
digitalWrite(13, !digitalRead(13));
startbit;
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
controle;
anti;
}


