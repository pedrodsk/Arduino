// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int t=10;
int t1;
int dt;
int z;
boolean debounce=0;
boolean b=0;
int x;
boolean y=0;
byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x38,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
  lcd.begin (16,2);
  lcd.createChar (0, smiley);    // load character to the LCD
  lcd.createChar (1, armsUp);    // load character to the LCD
  lcd.createChar (2, frownie);   // load character to the LCD
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  
}
 
void loop()
{
  if(digitalRead(2) == 0 || digitalRead(3) == 0 || digitalRead(4) == 0){
     unsigned long tempo = millis(); 
     while(tempo + 300 > millis());
  }    
     if(digitalRead(2) == 0 || digitalRead(3) == 0 || digitalRead(4) == 0)  debounce = 1;
  if(t<0) t=0;
  if(t != t1) lcd.clear();
//delay(500);
//
  //lcd.setBacklight(HIGH);
lcd.setCursor(0,0);
lcd.print ("Tempo da Bomba?");
  //lcd.print (char(2));

lcd.setCursor(3,1);
lcd.print (t);
lcd.setCursor(6,1);
lcd.print ("segundos");
t1=t;

botaoup();
botaodown();
botaook();
  
  
  
  while(b==1){
    if(digitalRead(4) == 0){
     unsigned long tempo = millis(); 
     while(tempo + 300 > millis());
  }    
     if(digitalRead(4) == 0)  debounce = 1;

t=t--;
y=!y;
lcd.clear();
lcd.setCursor(0,0);
lcd.print ("Tempo de explosao:");
lcd.setCursor(0,1);
lcd.print (t);
lcd.setBacklight(y);
delay(1000);
  while(t==0){
  lcd.clear();
  lcd.setBacklight(1);
lcd.setCursor(0,0);
lcd.print ("A bomba Explodiu");
lcd.setCursor(0,1);
lcd.print ("Tempo:");
lcd.setCursor(7,1);
lcd.print (z);
lcd.setCursor(11,1);
lcd.print ("seg");
lcd.setCursor(15,1);
lcd.print (char(2));

delay(10000);
}
if(digitalRead(4) == 0 && debounce==1){
  lcd.setBacklight(1);
   debounce=!debounce;
lcd.clear();
lcd.setCursor(0,0);
lcd.print ("Desarmando..");
lcd.setCursor(4,1);
lcd.print (char(0));
unsigned long tempo2 = millis(); 
     while(tempo2 + 10000 > millis());
     if(digitalRead(4) == 0){
     while(t<10){
  
lcd.setCursor(0,0);
lcd.print ("A bomba Explodiu");
lcd.setCursor(0,1);
lcd.print ("Tempo:");
lcd.setCursor(7,1);
lcd.print (z);
lcd.setCursor(11,1);
lcd.print ("seg");
lcd.setCursor(15,1);
lcd.print (char(2));
delay(10000);
}

 while(t>10){

lcd.setCursor(0,0);
lcd.print ("Bomba desarmada!");
lcd.setCursor(6,1);
lcd.print (char(0));
delay(10000);
}  
 }
  else{
    while(true){
  
lcd.setCursor(0,0);
lcd.print ("A bomba Explodiu");
lcd.setCursor(0,1);
lcd.print ("Tempo:");
lcd.setCursor(7,1);
lcd.print (z);
lcd.setCursor(11,1);
lcd.print ("seg");
lcd.setCursor(15,1);
lcd.print (char(2));
delay(10000);
    }
  }
} 
  
}
//delay(1000);
//lcd.clear();
//lcd.setBacklight(LOW);
//delay(1000);
 //  lcd.print("tempo setado");
 }
 

void botaoup(){
  //digitalWrite(13,HIGH);
  if(digitalRead(2) == 0 && debounce ==1){
   debounce=!debounce;
   t=t+5;
   //delay(500);
 }
}
 void botaodown(){
 if(digitalRead(3) == 0 && debounce ==1){
   debounce=!debounce;
   t=t-5;
   //delay(500);
 }
 }
 void botaook(){
 if(digitalRead(4) == 0 && debounce ==1){
   debounce=!debounce;
lcd.clear();
lcd.setCursor(0,0);
lcd.print ("Plantando..");
unsigned long tempo2 = millis(); 
     while(tempo2 + 5000 > millis());
       if(digitalRead(4) == 0){
       b=1;
       lcd.clear();
lcd.setCursor(0,0);
lcd.print ("Bomba Plantada!");
z=t;
delay(5000);
       } 
 }
 }
 
