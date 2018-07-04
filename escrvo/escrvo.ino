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
  {
 for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_0.write(pos);
    myservo_1.write(pos);
    // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo_0.write(pos);             
    myservo_1.write(pos);
    delay(15);
  } 
for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_0.write(pos);             
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo_0.write(pos);             
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);
  }
   for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo_0.write(pos);             
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo_0.write(pos);             
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
}
}
}
  
}
//funcoes
void pause() {
  int x=5;
  if(x=20){
  int x = Wire.read();
 while(x==2){
   int x = Wire.read();
 }
  }
}
void teste(int howMany)
{
  int o=2;
}

