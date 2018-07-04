#include <Wire.h>

byte x = 0; 

// ====================================================== 

void setup() 
{ 
Wire.begin(); // Start I2C Bus as Master 
} 

// ====================================================== 

void loop() 
{ 

Wire.beginTransmission(9); // transmit to device #9 
x=0;
Wire.write(x); // sends x 
Wire.endTransmission(); // stop transmitting 
delay(1000); 
Wire.beginTransmission(9); // transmit to device #9 
x=1;
Wire.write(x); // sends x 
Wire.endTransmission(); // stop transmitting 
delay(1000);
} 
// ==================== end of file ==================== 

