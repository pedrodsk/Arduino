#include <Wire.h>

byte x = 0; 

// ====================================================== 

void setup() 
{ 
Wire.begin(); // Start I2C Bus as Master 
Serial.begin(9600);
} 

// ====================================================== 

void loop() 
{ 

if (Serial.available() > 0) {
  Wire.beginTransmission(9);
 x = Serial.read(); 
  Wire.write(x);               
  Wire.endTransmission();    
  }
} 
// ==================== end of file ==================== 

