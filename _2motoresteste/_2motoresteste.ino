
#include <Servo.h> 
 
Servo myservo_0;   
Servo myservo_1;               
Servo myservo_2;   
Servo myservo_3;               

 
int pos = 0;    
 
void setup() 
{ myservo_0.attach(9);
myservo_1.attach(10);
myservo_2.attach(11);

} 
 
 
void loop() 
{ 
  //myservo_0.write(0); //flozinha  0 a 140  //teiu
  //myservo_1.write(0);//corupira 0 a 100  //juiz
  //myservo_2.write(100);//coruja 180 a 80
 
  for(pos = 0; pos < 100; pos += 1)   
  {                                   
    myservo_0.write(pos);     
   myservo_1.write(pos);
   myservo_2.write(pos);     
    
    delay(10);                        
  } 
  for(pos = 100; pos>=1; pos-=1)     
  {                                
    myservo_0.write(pos);     
   myservo_1.write(pos);  
   myservo_2.write(pos);     
        delay(10);   
  } 

} 

