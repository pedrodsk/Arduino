#include <LedControl.h>

int DIN = 12;
int CS =  10;
int CLK = 11;

byte e[8]=     {0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x81};
byte d[8]=     {0x78,0x7C,0x66,0x66,0x66,0x66,0x7C,0x78};
byte d2[8] = {0x00,0x78,0x7C,0x66,0x66,0x66,0x66,0x7C};
byte u[8]=     {0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x7E};
byte c[8]=     {0x7E,0x7E,0x60,0x60,0x60,0x60,0x7E,0x7E};
byte eight[8]= {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E};
byte s[8]=     {0x7E,0x7C,0x60,0x7C,0x3E,0x06,0x3E,0x7E};
byte dot[8]=   {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
byte o[8]=     {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E};
byte m[8]=     {0xE7,0xFF,0xFF,0xDB,0xDB,0xDB,0xC3,0xC3};

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,7);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
/*
    byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
    byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
    byte frown[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
    
    printByte(smile);
     
    delay(1000);

    printByte(neutral);
    
    delay(1000);

    printByte(frown);    

    delay(1000);
   
    printEduc8s();
  */ 
   //printByte(d);
   //lc.setLed(0,1,0,true);
   for(int i=0;i<7;i++){
   lc.setRow(0,i,B00011000);
   lc.setRow(0,i+1,B00011000);
   delay(300);
   lc.clearDisplay(0);
   delay(300);
   }
   //lc.setColumn(0,0,B11111111);
   //delay(1000);
   //printByte(d2);
    
    //delay(1000);
    //limpar display
    lc.clearDisplay(0);
    delay(1000);
    
}

void printEduc8s()
{
  printByte(e);
  delay(1000);
  printByte(d);
  delay(1000);
  printByte(u);
  delay(1000);
  printByte(c);
  delay(1000);
  printByte(eight);
  delay(1000);
  printByte(s);
  delay(1000);
  printByte(dot);
  delay(1000);
  printByte(c);
  delay(1000);
  printByte(o);
  delay(1000);
  printByte(m);
  delay(1000);
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

