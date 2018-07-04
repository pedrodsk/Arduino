#include <TimerOne.h>   // inclui biblioteca Timer1
 
#define triacApin 4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // Define que o Dimmer será comandado pelo pino 4
int frequencia = 60;
int stateTriacA = 0;
int power = 0;  //inicializa variavel que controla potencia na lampada com 0 (lampada apagada)
 
void setup()
{
Serial.begin(9600);
pinMode(triacApin, OUTPUT);
digitalWrite(triacApin, LOW);
Serial.println("Controle de TRIAC.\r\nDigite o Percentual de Brilho (duas casas) Ex.: 25");
// Initialize the interruption time Timer1
Timer1.initialize(); // Initialize TimerOne library for the freq we need
// Attach the interrupt 0 to pin 2 for the detection of zero crossing (Zero Cross Detection)
attachInterrupt(0, zero_cross_detect, FALLING); // Attach an Interrupt to Pin 2 (Interrupt 0) for Zero Cross Detection
}
 
void loop()
{
for(int i2=0;i2<100;i2++){
 power=i2;
 delay(150);
}
for(int i2=100;i2>0;i2--){
 power=i2;
 delay(150);
}

int i = 0;
int read_data[2];
if(i<2){
if(Serial.available()){
read_data[i] = Serial.read();
i++;
}
}
power = Concatena_Numeros(read_data[0],read_data[1]);
Serial.println(power);

}
 
void zero_cross_detect()
{
if(power > 0){
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
 
int Concatena_Numeros(int variavel1, int variavel2)
{
int resultado;
resultado = ((variavel1-'0')*10)+(variavel2-'0');
return resultado;
}
