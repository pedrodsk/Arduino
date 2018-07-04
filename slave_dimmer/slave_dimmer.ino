#include <TimerOne.h>
#include <Wire.h>
#define triacApin 5
int power1=0;
void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(triacApin, OUTPUT);
  digitalWrite(triacApin, LOW);
  Timer1.initialize();
  attachInterrupt(0, zero_cross_detect, FALLING);
}

void loop()
{
 
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(Wire.available()) // loop through all but the last
  {
   power1 = Wire.read(); // receive byte as a character
   Serial.println(power1);
}
}
//funcaodimmer
void zero_cross_detect()
{
if(power1 > 0){
 // power=30;
long dimtime = int(map(power1,0,180,7000,150));  // calcula o tempo de delay para o disparo do TRIAC 7950,100
Timer1.attachInterrupt(gateTRIAC, dimtime);  //associa a funcao gateTRIAC com Interrupcao do TIMER1
Timer1.start();  // inicia contagem TIMER1
}else{
digitalWrite(triacApin, LOW);   // mantem gate do TRIAC desativado.
Timer1.stop();
}
}
 
void gateTRIAC ()
{  // trata interrupcao do TIMER1 gerando pulso no gate do TRIAC
digitalWrite(triacApin, HIGH);  // dispara o Triac
delayMicroseconds(5);  // aguarda 5 microsegundos para garantir disparo do TRIAC
digitalWrite(triacApin, LOW);   // desabibilta gate do TRIAC
Timer1.stop();
}
