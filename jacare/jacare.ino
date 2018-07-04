#include <SoftwareSerial.h>  

int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

#define frente 6
#define tras 9
char comando;

void setup()  
{

  // set the data rate for the SoftwareSerial port
  bluetooth.begin(115200);
  pinMode(frente, OUTPUT);
  pinMode(tras, OUTPUT);
  pinMode(13, OUTPUT);
digitalWrite(frente, LOW);
digitalWrite(tras, LOW);
}

void loop() // run over and over
{
 
      if(bluetooth.available()) 
  {
  comando = bluetooth.read();
    if(comando=='A'){
      bluetooth.println("Sentido 1");
     digitalWrite(frente,HIGH);
     delay(5000);
     digitalWrite(frente,LOW);
     
    }
    if(comando=='B'){
      bluetooth.println("Sentido 2");
      digitalWrite(tras,HIGH);
      delay(5000);
      digitalWrite(tras,LOW);
         }
     digitalWrite(frente,LOW);
     digitalWrite(tras,LOW);
  
}
}
