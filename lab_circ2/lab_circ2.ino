const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

//volatile int power1 = 0;
unsigned long x=0;
int y=0;
int t=0;
float valores[200];
long tempoAnterior = 0;
unsigned long tempo=100000;
void setup() {
  ADCSRA &= ~PS_128;
  ADCSRA |= PS_32;
  Serial.begin(115200);
  for(int i=0;i<200;i++)
  valores[i]=0;
  attachInterrupt(0, zero_cross, FALLING);
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
  if(y==1) 
  {
  valores[i]=analogRead(A1);
  //delayMicroseconds(1);
  i++;
  }

if(y==2){
  for(int i=0;i<200;i++){
  Serial.println(valores[i]);
  delay(100);
  }
  Serial.println(i);
  //Serial.println(x);
  //x=0;
  y=3;
  }


}
void zero_cross()  
{
  //Serial.print("a");
  //tempo=millis();
  if(y==0){
    y=1;
      }
  if(y==1 && t!=0)
  y=2;
  t++;
 // goto oioi();
  }
  //Serial.println("a");
  void oioi(){
    x++;
  }  

