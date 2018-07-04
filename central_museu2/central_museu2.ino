#include <Wire.h>
#include <IRremote.h>
#include <NECIRrcv.h>
#include <TimerOne.h>
//variaveis
#define triacApin 4
int power=0;
int led=12;
int RECV_PIN = 3;
int y=0;
unsigned long codeValue;
IRrecv irrecv(RECV_PIN);
decode_results results;
byte x=1;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Wire.begin();
  pinMode(12, OUTPUT);
 Timer1.initialize(60);
 //Timer1.attachInterrupt(controle);
  attachInterrupt(1, controle, CHANGE);
 //dimmer
 pinMode(triacApin, OUTPUT);
digitalWrite(triacApin, LOW);
attachInterrupt(0, zero_cross_detect, FALLING);

}


void loop() {
  /*
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(x);              // sends one byte  
  delay(15000);
  Wire.endTransmission(4);    // stop transmitting
  x=2;
  
  
for(int i=0;i<10000;i++){
 Serial.println(i);
delay(1000);
}
*/
for(int i2=0;i2<100;i2++){
 power=i2;
 delay(150);
}
for(int i2=100;i2>0;i2--){
 power=i2;
 delay(150);
}
}


//FUNCOES

//FUNCAO CONTROLE
void controle()
{
if (irrecv.decode(&results)) {
   // Serial.println(results.value);
   
     if(results.value == 3041548455){
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
      Timer1.attachInterrupt(zero_cross_detect);
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
//FUNCAO DIMMER
void zero_cross_detect()
{
if(power > 0){
  power=15;
long dimtime = int(map(power,0,100,7000,150));  // calcula o tempo de delay para o disparo do TRIAC 7950,100
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
//FIM FUNCAO DIMMER

