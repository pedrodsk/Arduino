const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

//volatile int power1 = 0;
unsigned long x=0;
int y=0;
int t=0;
int valores[100];
long tempoAnterior = 0;
unsigned long tempo=0;
unsigned long intervalo=1000;
void setup() {
  ADCSRA &= ~PS_128;
  ADCSRA |= PS_64;
  Serial.begin(115200);
  for(int i=0;i<100;i++)
  valores[i]=0;
  //attachInterrupt(0, zero_cross, FALLING);
  }

  

/*  if(y==1) {
    //for(int i=0; i<100;i++){
    if(tempo - tempoAnterior < 8.3333){
  int i;
  valores[i] = analogRead(A0);
  valores[i] = valores[i] * (3.5 / 1023.0);
  i++;
  
*/
long i=0;
void loop() {
  //if(tempo - tempoAnterior > intervalo && y==1){
  //tempoAnterior=tempo;
  if(t==0){
  valores[i] = analogRead(A0);
  //intervalo+=3;
  //y=0;
  i++;
  }
  //}
if(i==70 && t==0){
//detachInterrupt(0);
for(int i=0;i<70;i++){
Serial.println(valores[i]);
delay(200);
}
t=1;
}
}
void zero_cross()  
{
  tempo=millis();
  y=1;
}
