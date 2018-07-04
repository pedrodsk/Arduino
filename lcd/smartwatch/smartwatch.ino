// UTFT_Demo_320x240 (C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of how to use most of the functions
// of the library with a supported display modules.
//
// This demo was made for modules with a screen resolution 
// of 320x240 pixels.
//
// This program requires the UTFT library.
//

#include <UTFT.h>
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
UTFT myGLCD(ITDB28,19,18,17,16);   // Remember to change the model parameter to suit your display module!
int seg1=0,
minuto1=0,
hor1=0;
int seg2=0,
minuto2=0,
hor2=0; 

void setup()
{
  
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
  myGLCD.clrScr();
//dentro do setup

  myGLCD.setColor(0, 255, 255);//retangulo de cima
  myGLCD.fillRect(0, 0, 319, 50);//retangulo de cima
  myGLCD.setColor(0, 0, 0);//cor do nome smart watch
  myGLCD.setBackColor(204, 255, 255);//cor do fundo do nome
  myGLCD.print("* SMART WATCH *", CENTER, 10);
  

  myGLCD.setColor(0, 255, 255);//retangulo de baixo
  myGLCD.fillRect(0, 200, 319, 239);//retangulo de baixo
  myGLCD.setColor(0,0,0);//cor do nome inova senai
  myGLCD.setBackColor(204, 255, 255);//cpr do fundo do nome
  myGLCD.print("<INOVA SENAI 2014>", CENTER, 215);
  
  myGLCD.setColor(0, 255, 255);//cor do retangulo
  myGLCD.drawRect(40, 80, 280, 170);//retangulo em torno da hora
  
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(0, 0, 0);//cor do fundo da hora
  myGLCD.setColor(153, 255, 0);//cor da hora
  
  //
}
void relogio(){
static unsigned long ult_tempo = 0;
int tempo = millis();
if(tempo - ult_tempo >= 1000) {
ult_tempo = tempo;
seg1++;
}
if(seg1>=10) {
seg1 = 0;
seg2++;
}
if(seg2>=6) {
seg2 = 0;
minuto1++;
}
if(minuto1>=10) {
minuto1=0;
minuto2++;
}
if(minuto2>=6) {
minuto2=0;
hor1++;
}
if(hor1>=10) {
hor1=0;
hor2++;
}
if(hor2>=6) {
hor2=0;
}
}
void loop()
{
  relogio();
  myGLCD.printNumI(seg1,240,100);
  myGLCD.printNumI(seg2,210,100);
  myGLCD.printNumI(minuto1,160,100);
  myGLCD.printNumI(minuto2,130,100);
  myGLCD.printNumI(hor1,80,100);
  myGLCD.printNumI(hor2,50,100);
}
