/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
#define selA 9
#define enable 10
#define selB 8
#define selC 7

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
pinMode(selA, OUTPUT);
pinMode(selB, OUTPUT);
pinMode(selC, OUTPUT);
pinMode(enable, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
digitalWrite(enable, HIGH);

digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
delay(3000);

digitalWrite(selA,LOW);
digitalWrite(selB,LOW);
digitalWrite(selC,HIGH);
delay(3000);

digitalWrite(selA,LOW);
digitalWrite(selB,HIGH);
digitalWrite(selC,LOW);
delay(3000);

digitalWrite(selA,LOW);
digitalWrite(selB,HIGH);
digitalWrite(selC,HIGH);
delay(3000);

digitalWrite(selA,HIGH);
digitalWrite(selB,LOW);
digitalWrite(selC,LOW);
delay(3000);

digitalWrite(selA,HIGH);
digitalWrite(selB,LOW);
digitalWrite(selC,HIGH);
delay(3000);

digitalWrite(selA,HIGH);
digitalWrite(selB,HIGH);
digitalWrite(selC,LOW);
delay(3000);

digitalWrite(selA,HIGH);
digitalWrite(selB,HIGH);
digitalWrite(selC,HIGH);
delay(3000);

               // wait for a second
}
