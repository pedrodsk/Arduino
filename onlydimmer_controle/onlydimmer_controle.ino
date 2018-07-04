#include <Wire.h>
#include <IRremote.h>
#include <NECIRrcv.h>
#include <TimerOne.h>
//variaveis
int led=12;
int RECV_PIN = 3;
int y=0;
unsigned long codeValue;
IRrecv irrecv(RECV_PIN);
decode_results results;
int x=1;
int pos = 0; 

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Wire.begin();
  pinMode(12, OUTPUT);
 Timer1.initialize(300000);
 Timer1.attachInterrupt(controle);
 //attachInterrupt(0, controle, CHANGE);
}


void loop() {
  //while(x==1){
 //   if (irrecv.decode(&results)) {
 //       if(results.value == 3041548455){
  //         x=2;
    // }
  //}
 // }
  
    //servo
    if (irrecv.decode(&results)) {
        if(results.value == 3041546415 && pos<180){                                // in steps of 1 degree 
  Wire.beginTransmission(2); // transmit to device #4
  pos=pos++;
  Wire.write(pos);
  delay(5);
  Wire.write(pos);
  Wire.endTransmission(2);
  Wire.beginTransmission(4); 
  Wire.write(pos);               
  Wire.endTransmission(4);
               // tell servo to go to position in variable 'pos' 
    //delay(15);                       // waits 15ms for the servo to reach the position 
  }
   if(results.value == 3041579055 && pos > 0){                                // in steps of 1 degree 
  //Wire.beginTransmission(2); // transmit to device #4
  pos=pos--;  
                                
  Wire.beginTransmission(2); // transmit to device #4
  Wire.write(pos);
  delay(5);
  Wire.write(pos);
  Wire.endTransmission(2);
  Wire.beginTransmission(4); 
  Wire.write(pos);               
  Wire.endTransmission(4);
               // tell servo to go to position in variable 'pos' 
  //  delay(15);                        // waits 15ms for the servo to reach the position 
  }
    }
 
  //dimmer
/*for(int i2=0;i2<180;i2++){
  Wire.beginTransmission(4); 
  Wire.write(i2);               
  Wire.endTransmission(4);
 delay(50);
}
for(int i2=180;i2>0;i2--){
  Wire.beginTransmission(4); 
  Wire.write(i2);               
  Wire.endTransmission(4);
 delay(50);
}
 */

}
//FUNCOES

//FUNCAO CONTROLE
void controle()
{
if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 3041575485){
       
     digitalWrite(led,LOW);
      y=0;
      //play escravo
      //Wire.beginTransmission(4);
      //Wire.write(1);
      //Wire.endTransmission(4);
      //play escravo
         }
if(results.value == 3041532645){
    digitalWrite(led,HIGH);
    y=2;
    while(y==2){
     //pausa escravo
      //Wire.beginTransmission(4);
      //Wire.write(2);
      //Wire.endTransmission(4);
      //fim pausa escravo
      Timer1.attachInterrupt(controle);
      irrecv.resume();
      if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 3041548455){
     digitalWrite(led,LOW);
      y=0;
         }
      }
      //Serial.println("teste");
      delay(400);
    }
   
  }

    irrecv.resume(); // Receive the next value
}
}
//FUNCAO CONTROLE FIM


