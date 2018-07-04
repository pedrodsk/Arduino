#include <TimerOne.h>
#include <Wire.h>
#include <Servo.h>
//variaveis
Servo myservo_0;  // create servo object to control a servo 
Servo myservo_1;                // a maximum of eight servo objects can be created 
int pos = 0;    // variable to store the servo position 


void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(teste); // register event
  pinMode(11, OUTPUT);
  myservo_0.attach(9);
  myservo_1.attach(10);
  //Timer1.initialize(1000000);
  //Timer1.attachInterrupt(pause);
            // start serial for output
}

void loop()
{
  while(Wire.available()) { // loop through all but the last
 int x = Wire.read();
 if(x==1){
  digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  delay(1000);
}
}
}
  

