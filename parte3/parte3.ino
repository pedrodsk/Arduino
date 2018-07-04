#include <IRremote.h>
#define lamp1 6
#define led 14
volatile int power1 = 0;
int luz;
char lerSerial[22]="";
int x,t,y;
char c;
int converter=0;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(lamp1, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  attachInterrupt(0, zero_cross, FALLING);
}

void loop() {
if(Serial.available()){
  do{
  c=Serial.read(); //char c recebe o caracterer a caracterer da Serial
  lerSerial[x]=c; //atribui o valor lido pela serial ao char lerSerial
 
//  Serial.println(lerSerial[x]);
  x++; //incrementa a variável x.. x=0, x=1.. etc
  delay(1); //delay 1ms
  t=1;
  y=1;
}while(c!='\n'); //faz o loop enquanto o caracterer C não é igual a \n (fim de linha)
}
x=0; //zera o caracter
if(y==1)
converter = atoi(lerSerial); //função para converter o char em inteiro
if (irrecv.decode(&results)) {
  irrecv.resume();
  Serial.println(results.value,HEX);
  if(results.value == 0xEF6A95){
  converter=converter+5;
  //digitalWrite(14,HIGH);
  irrecv.resume();
  t=1;
          }
  if(results.value == 0xEFAA55){
  converter=converter-5;
  //digitalWrite(14,LOW);
  irrecv.resume();
  t=1;
        }
}

if(t==1){
  if(converter>99)
  converter=99;
  if(converter<0)
  converter=0;
Serial.println(converter);
t=0;
y=0;
}
  /* fade in/out
  for(x=0;x<=100;x++){
    luz=x;
    delay(50);
  }
  
  for(x=100;x>=0;x--){
    luz=x;
    delay(50);
  }
  */
  
}
void zero_cross()  
{
 // x++;
  
  luz = map(converter, 99, 0, 400, 6500);
  //x = (32*(256-auxpower));
  delayMicroseconds(luz);
  digitalWrite(lamp1, HIGH);
  delayMicroseconds(8.33);      
  digitalWrite(lamp1, LOW);
    
}

