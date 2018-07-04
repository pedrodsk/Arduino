#include <SoftwareSerial.h>  

int bluetoothTx =2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

#define frente 6
#define tras 9
char comando;

void setup()  
{

  // set the data rate for the SoftwareSerial port
  bluetooth.begin(9600);
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
  bluetooth.println("Sentido 1");
  delay(1000);
    if(comando=='A'){
      bluetooth.println("Sentido 1");
     digitalWrite(13,HIGH);
     
    }
    if(comando=='B'){
      bluetooth.println("Sentido 2");
      digitalWrite(13,LOW);
    }  
}
}
