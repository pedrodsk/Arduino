// 19/08/2014

#include <UTFT.h>
#include <UTouch.h>
#include <SoftwareSerial.h>  
int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D3
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
UTFT myGLCD(ITDB28,A5,A4,A3,A2);   // Remember to change the model parameter to suit your display module!
UTouch  myTouch( A1,10,A0, 8, 9);
int seg1=0,
minuto1=0,
hor1=0;
int seg2=0,
minuto2=0,
hor2=0;
int x, y;
int z=0; 

void setup()
{
 delay(5000);
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("C,CCAF78C2D9A8\r");
  
 

  myGLCD.InitLCD();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  myGLCD.clrScr();
  
//bluetooth

 
/*
 Serial.begin(115200);  // Begin the serial monitor at 9600bps
 delay(5000);
 Serial.print("$");  // Print three times individually
  Serial.print("$");
  Serial.print("$");  // Enter command mode
teste  delay(100);  // Short delay, wait for the Mate to send back CMD
  Serial.println("C,CCAF78C2D9A8\r");
  */
//dentro do setup
/*
  myGLCD.setColor(0, 255, 255);//retangulo de cima
  myGLCD.fillRect(0, 0, 319, 50);//retangulo de cima
  myGLCD.setColor(53, 53, 53);//cor do nome smart watch
  myGLCD.setBackColor(220, 220, 200);//cor do fundo do nome
  myGLCD.print("** SMART WATCH **", CENTER, 10);
  

  myGLCD.setColor(0, 255, 255);//retangulo de baixo
  myGLCD.fillRect(0, 185, 319, 239);//retangulo de baixo
  myGLCD.setColor(53,53,53);//cor do nome inova senai
  myGLCD.setBackColor(220, 220, 200);//cpr do fundo do nome
  
  
  //myGLCD.print("<INOVA SENAI 2014>", CENTER, 30);
  
  myGLCD.setColor(0, 255, 255);//cor do retangulo
  //myGLCD.drawRect(40, 80, 280, 170);//retangulo em torno da hora
  //myGLCD.drawRoundRect(40,80,280,170);
  myGLCD.fillRoundRect(40,80,280,170);
  
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(220, 220, 220);//cor do fundo da hora
  myGLCD.setColor(50, 50, 50);//cor da hora
  //myGLCD.setColor(16, 16, 16);//cor da hora
  //botao1
  myGLCD.setColor(220, 220, 220);
  myGLCD.fillRect(30, 195, 90, 230);
  myGLCD.setColor(53,53,53);
  myGLCD.setBackColor(220, 220, 200);
  //fim do botao1
  //botao2
  myGLCD.setColor(220, 220, 220);
  myGLCD.fillRect(120, 195, 180, 230);
  myGLCD.setColor(53,53,53);
  myGLCD.setBackColor(220, 220, 200);
  //fim do botao2
  //botao3
  myGLCD.setColor(220, 220, 220);
  myGLCD.fillRect(210, 195, 270, 230);
  myGLCD.setColor(53,53,53);
  myGLCD.setBackColor(220, 220, 200);
  //fim do botao3
  //
//touch
*/
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
void teste(){

  myGLCD.setFont(BigFont);
  myGLCD.fillScr(220,220,220);
  myGLCD.setColor(0, 255, 255);//retangulo de cima
  myGLCD.fillRect(0, 0, 319, 50);//retangulo de cima
  myGLCD.setColor(53, 53, 53);//cor do nome smart watch
  myGLCD.setBackColor(220, 220, 200);//cor do fundo do nome
  myGLCD.print("** SMART WATCH **", CENTER, 10);
  
  myGLCD.setColor(0, 255, 255);//retangulo de baixo
  myGLCD.fillRect(0, 185, 319, 239);//retangulo de baixo
  myGLCD.setColor(53,53,53);//cor do nome inova senai
  myGLCD.setBackColor(220, 220, 200);//cor do fundo do nome
  
    //myGLCD.print("<INOVA SENAI 2014>", CENTER, 30);
  
  //myGLCD.setColor(16, 16, 16);//cor da hora
  //botao1
  myGLCD.setColor(220, 220, 220);
  myGLCD.fillRoundRect(30, 195, 90, 230);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (30, 195, 90, 230);
  myGLCD.printNumI(1, 55, 205);
  myGLCD.print("Mse", 35, 205);
  //fim do botao1
  //botao2
  myGLCD.setColor(220, 220, 220);
  myGLCD.fillRoundRect(120, 195, 180, 230);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (120, 195, 180, 230);
  myGLCD.setBackColor(220, 220, 200);
  myGLCD.print("Key", 125, 205);
  //fim do botao2
  //botao3
  myGLCD.setColor(220, 220, 220);
  myGLCD.fillRoundRect(210, 195, 270, 230);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (210, 195, 270, 230);
  myGLCD.setBackColor(220, 220, 200);
  //relogio
  myGLCD.setColor(0, 255, 255);//cor do retangulo
  //myGLCD.drawRect(40, 80, 280, 170);//retangulo em torno da hora
  //myGLCD.drawRoundRect(40,80,280,170);
  myGLCD.fillRoundRect(40,70,280,165);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(220, 220, 220);//cor do fundo da hora
  myGLCD.setColor(50, 50, 50);//cor da hora
  
}
void loop()
{
  if(z==0){
  teste();
  z=1;
}
  relogio();
  myGLCD.printNumI(seg1,240,100);
  myGLCD.printNumI(seg2,210,100);
  myGLCD.printNumI(minuto1,160,100);
  myGLCD.printNumI(minuto2,130,100);
  myGLCD.printNumI(hor1,80,100);
  myGLCD.printNumI(hor2,50,100);
  if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
      if ((y>=195) && (y<=230))  //botao1
      {
        if ((x>=30) && (x<=90))  
        {
          bluetooth.println("b1");
        }
    }
 if ((y>=195) && (y<=230))  //botao2
      {
        if ((x>=120) && (x<=180))  
        {
          bluetooth.println("b2");
         // myGLCD.clrScr();
        }
    }

     if ((y>=195) && (y<=230))  //botao3
      {
        if ((x>=210) && (x<=270))  
        {
          bluetooth.println("b3");
         // myGLCD.clrScr();
        }
    }


}
}
