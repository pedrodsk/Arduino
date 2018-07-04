#include <TimerOne.h>   // inclui biblioteca Timer1
#include <TimerThree.h>
#define triacApin 4 // Define que o Dimmer será comandado pelo pino 4
#define triacApin2 5
int frequencia = 60;
int stateTriacA = 0;
int power = 0;  //inicializa variavel que controla potencia na lampada com 0 (lampada apagada)
int power2 = 0;
 
void setup()
{
Serial.begin(9600);
pinMode(triacApin, OUTPUT);
pinMode(triacApin2, OUTPUT);
digitalWrite(triacApin, LOW);
digitalWrite(triacApin2, LOW);
Serial.println("Controle de TRIAC.\r\nDigite o Percentual de Brilho (duas casas) Ex.: 25");
// Initialize the interruption time Timer1
Timer1.initialize(); // Initialize TimerOne library for the freq we need
Timer3.initialize();
// Attach the interrupt 0 to pin 2 for the detection of zero crossing (Zero Cross Detection)
attachInterrupt(0, zero_cross_detect, FALLING); // Attach an Interrupt to Pin 2 (Interrupt 0) for Zero Cross Detection
}
 
void loop()
{
for(int i2=0;i2<50;i2++){
 power=i2;
 //delay(10);
// power2=i2;
 delay(30);
}
for(int i2=0;i2<50;i2++){
   power2=i2;
 //delay(10);
// power2=i2;
 delay(30);
}
for(int i2=50;i2<100;i2++){
 power=i2;
 //delay(10);
// power2=i2;
 delay(30);
}
for(int i2=50;i2<100;i2++){
 power2=i2;
 //delay(10);
// power2=i2;
 delay(30);
}
for(int i2=100;i2>0;i2--){
 power=i2;
 //delay(10);
// power2=i2;
 delay(30);
}
for(int i2=100;i2>0;i2--){
 power2=i2;
 //delay(10);
// power2=i2;
 delay(30);
}


}//fim do loop
 
void zero_cross_detect()
{
if(power > 0){
long dimtime = int(map(power,0,100,6700,150));  // calcula o tempo de delay para o disparo do TRIAC 7950,100
Timer1.attachInterrupt(gateTRIAC, dimtime);  //associa a funcao gateTRIAC com Interrupcao do TIMER1
//Timer1.detachInterrupt();
Timer1.start();  // inicia contagem TIMER1
}else{
digitalWrite(triacApin, LOW);   // mantem gate do TRIAC desativado.
//digitalWrite(triacApin2, LOW);
Timer1.stop();
}
//delayMicroseconds(10000);
if(power2 > 0){
long dimtime2 = int(map(power2,0,100,6700,150));  // calcula o tempo de delay para o disparo do TRIAC 7950,100
Timer1.attachInterrupt(gateTRIAC2, dimtime2);  //associa a funcao gateTRIAC com Interrupcao do TIMER1
//Timer1.detachInterrupt();
Timer3.start();  // inicia contagem TIMER1
}else{
//digitalWrite(triacApin, LOW);   // mantem gate do TRIAC desativado.
digitalWrite(triacApin2, LOW);
Timer3.stop();
}




}
void gateTRIAC ()
{  // trata interrupcao do TIMER1 gerando pulso no gate do TRIAC
digitalWrite(triacApin, HIGH);  // dispara o Triac
//delayMicroseconds(5);
//digitalWrite(triacApin2, HIGH);
delayMicroseconds(5);  // aguarda 5 microsegundos para garantir disparo do TRIAC
digitalWrite(triacApin, LOW);   // desabibilta gate do TRIAC
//delayMicroseconds(5);
//digitalWrite(triacApin2, LOW);

Timer1.stop();
//Timer1.detachInterrupt();
}

void gateTRIAC2 ()
{  // trata interrupcao do TIMER1 gerando pulso no gate do TRIAC
//digitalWrite(triacApin, HIGH);  // dispara o Triac
digitalWrite(triacApin2, HIGH);
delayMicroseconds(5);  // aguarda 5 microsegundos para garantir disparo do TRIAC
//digitalWrite(triacApin, LOW);   // desabibilta gate do TRIAC
digitalWrite(triacApin2, LOW);
Timer3.stop();
//Timer1.detachInterrupt();
}

