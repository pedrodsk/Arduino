
#include <Servo.h> 
 
Servo myservo_0;   
Servo myservo_1;               
Servo myservo_2;   
Servo myservo_3;               

 
int pos = 0;    
 
void setup() 
{ myservo_0.attach(5);
myservo_1.attach(6);
myservo_2.attach(9);
myservo_3.attach(10);
} 
 
 
void loop() 
{ 
  for(pos = 0; pos < 120; pos += 1)   
  {                                   
    myservo_0.write(pos);     
    myservo_1.write(pos);
    myservo_2.write(pos);     
    myservo_3.write(pos);
    delay(10);                        
  } 
  for(pos = 120; pos>=1; pos-=1)     
  {                                
    myservo_0.write(pos);     
    myservo_1.write(pos);  
    myservo_2.write(pos);     
    myservo_3.write(pos);
    delay(10);   
  } 
} 
