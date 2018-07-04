/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
    int a = Serial.read();
  switch (a) {
  case 'l':
    for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD48B7, 32);
      delay(100);
      Serial.println("funcionou");
      }
break;  
  
  case 'i':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDF00F, 32);
      delay(100);
   // }
    break;
  
  case '1':
     // for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD807F, 32);
      delay(100);
 break;  
  //}

  
  case '2':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD40BF, 32);
      delay(100);
    //}
  break;
  
  case '3':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDC03F, 32);
      delay(100);
   // }
  break;
  
  case '4':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD20DF, 32);
      delay(100);
    //}
  break;
  
  case '5':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDA05F, 32);
      delay(100);
    //}
  break;
  
  case '6':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD609F, 32);
      delay(100);
    //}
  break;
  
  case '7':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDE01F, 32);
      delay(100);
    //}
  break;
  
  case '8':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD10EF, 32);
      delay(100);
    //}
  break;
  
  case '9':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD906F, 32);
      delay(100);
 //   }
  break;
  
  case '0':
   // for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD00FF, 32);
      delay(100);
    //}
  break;
  
  case '+':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD58A7, 32);
      delay(100);
    //}
  break;
  
  case '-':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD7887, 32);
      delay(100);
    //}
  break;
  
  case 'q':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDD827, 32);
      delay(100);
    //}
  break;

  case 'a':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDF807, 32);
      delay(100);
    //}
  break;
  
  case 's':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD08F7, 32);
      delay(100);
    //}
  break;
  
  case 'm':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD01FE, 32);
      delay(100);
    //}
  break;
  
   case 'x':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD1AE5, 32);
      delay(100);
    //}
  break;
  
  case 'c':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD41BE, 32);
      delay(100);
    //}
  break;
  
  case 'b':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDC13E, 32);
      delay(100);
   // }
  break;
  
  case 'e':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FDB847, 32);
      delay(100);
    //}
  break;
  
  case 'd':
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0x02FD9867, 32);
      delay(100);
    //}
  break;
  
}
}

