#include <Wire.h>
#define lamp1 5
#define lamp2 6
#define lamp3 7
#define lamp4 9
#define lamp5 10
#define lamp6 15
#define lamp7 16
#define lamp8 17
volatile int power1 = 0;
volatile int power2 = 0;
volatile int power3 = 0;
volatile int power4 = 0;
volatile int power5 = 0;
volatile int power6 = 0;
volatile int power7 = 0;
volatile int power8 = 0;
int led = 8;
//volatile int x=0;
byte x=0;
void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(teste);
  //Serial.begin(9600);
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);
  pinMode(lamp4, OUTPUT);
  pinMode(lamp5, OUTPUT);
  pinMode(lamp6, OUTPUT);
 pinMode(lamp7, OUTPUT);
  pinMode(lamp8 , OUTPUT);
 // pinMode(lamp7, OUTPUT);
 // pinMode(lamp8, OUTPUT);
  attachInterrupt(0, zero_crosss_int, FALLING);
pinMode(led, OUTPUT);  
digitalWrite(led, HIGH);
}
 
void loop()
{
 delay(100);
}
 void teste(int howMany)
{
 while(Wire.available()) // loop through all but the last
  {
 x = Wire.read(); // receive byte as a character
}  

}
void zero_crosss_int()  
{
  if(x>0){
  // Cálculo do ângulo de disparo: 60Hz-> 8.33ms (1/2 ciclo)
  // (8333us - 8.33us) / 256 = 32 (aprox
  int auxpower = map(x, 0, 100, 0, 241);
  int x = (32*(256-auxpower));
  //int powertime2 = (32*(256-power2));  
  // Mantém o circuito desligado por powertime microssegundos 
  delayMicroseconds(x);
  //delayMicroseconds(powertime2);  
  // Envia sinal ao TRIAC para que ele passe a conduzir 
  digitalWrite(lamp1, HIGH);
  digitalWrite(lamp2, HIGH);
  digitalWrite(lamp3, HIGH);
  digitalWrite(lamp4, HIGH);
  digitalWrite(lamp5, HIGH);
  digitalWrite(lamp6, HIGH);
  digitalWrite(lamp7, HIGH);
  digitalWrite(lamp8, HIGH);
  delayMicroseconds(8.33);      
  // Desliga o pulso
  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);
  digitalWrite(lamp3, LOW);
  digitalWrite(lamp4, LOW);
  digitalWrite(lamp5, LOW);
  digitalWrite(lamp6, LOW);
  digitalWrite(lamp7, LOW);
  digitalWrite(lamp8, LOW);
 // x++;
    }
}
