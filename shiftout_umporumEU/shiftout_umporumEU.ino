//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;



void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  // count from 0 to 255 and display the number 
  // on the LEDs
  for (int numberToDisplay = 0; numberToDisplay < 7; numberToDisplay++) {
    // take the latchPin low so 
   int x=(pow(2,numberToDisplay));
   x=x+1;
   //Serial.println(x);
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, x);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    //sqrt(numberToDisplay);
    // pause before next value:
    delay(20);
  }
  for (int numberToDisplay = 0; numberToDisplay < 7; numberToDisplay++) {
    // take the latchPin low so 
   int x=(pow(2,numberToDisplay));
   x=x+1;
   //Serial.println(x);
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, x);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    //sqrt(numberToDisplay);
    // pause before next value:
    delay(20);
  }
}



