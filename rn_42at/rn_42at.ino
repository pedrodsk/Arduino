
#include <SoftwareSerial.h>  

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
    // Begin the serial monitor at 9600bps
  delay(5000);
  bluetooth.begin(9600);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("SU,9600\r");
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  //  bluetooth.begin(9600);  // Start bluetooth serial at 9600

}


void loop()
{
  if(bluetooth.available())  // If the bluetooth sent any characters
  {
    delay(300);
 // bluetooth.print("teste");  // Print three times 
  //delay(100);
   // delay(30000);
    
  // and loop forever and ever!
}
}
