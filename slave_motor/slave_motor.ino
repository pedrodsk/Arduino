#include <TimerOne.h>
#include <Wire.h>
#include <Servo.h>
//variaveis
Servo myservo_0;  // create servo object to control a servo 
Servo myservo_1;                // a maximum of eight servo objects can be created 
int pos = 0;    // variable to store the servo position 
int pos2 = 0;

void setup()
{
myservo_0.attach(9);
myservo_1.attach(10);
Wire.begin(2);                // join i2c bus with address #4
Wire.onReceive(receiveEvent); // register event 
}
void loop(){
  delay(100);
}
  

void receiveEvent(int howMany)
{
  while(1<Wire.available()) // loop through all but the last
  {
    pos= Wire.read();                              // in steps of 1 degree 
    myservo_0.write(pos);              // tell servo to go to position in variable 'pos'
  }
    pos2= Wire.read(); 
    myservo_1.write(pos2); 
                          // waits 15ms for the servo to reach the position 
  } 


