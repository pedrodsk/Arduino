#include <Wire.h>
#define LED_1 13 

int x; 

// ====================================================== 

void setup() 
{ 
Wire.begin(9); // Start I2C Bus as a Slave (Device Number 9) 
Wire.onReceive(receiveEvent); // register event 

pinMode(LED_1, OUTPUT); 

x = 0; 
} 

// ====================================================== 

void loop() 
{ 
//If value received is 0 blink LED 1 
delay(100); 
} 

// ====================================================== 

void receiveEvent(int howMany) 
{ 
x = Wire.read(); // receive byte as an integer 
if (x == 0) 
{ 
digitalWrite(LED_1, HIGH); 
} 
//If value received is 1 blink LED 2 
if (x == 1) 
{ 
digitalWrite(LED_1, LOW); 
}
}

//
