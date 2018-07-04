// BLINK SEM DELAY - PEDRO
int led = 2;
int led2 = 3;
boolean x,y;
long tempoAnterior = 0;
long tempoAnterior2 = 0;
long intervalo = 1000;
long intervalo2 = 2000;
long intervalo3 = 300;
long intervalo4 = 600;

void setup() {                
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
unsigned long tempo = millis();
unsigned long tempo2 = millis();

if(tempo - tempoAnterior > intervalo) {
piscar(1);
}
if(tempo - tempoAnterior > intervalo2) {
piscar(0);
tempoAnterior = tempo;
}

if(tempo2 - tempoAnterior2 > intervalo3) {
piscar2(1);
}
if(tempo2 - tempoAnterior2 > intervalo4) {
piscar2(0);
tempoAnterior2 = tempo2;
}


}
 

void piscar(boolean x)
{
  if(x==1)
  {
  digitalWrite(led, HIGH); 
    }               
  if(x==0)
  {
  digitalWrite(led, LOW); 
     }
}

void piscar2(boolean y)
{
  if(y==1)
  {
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  }               // wait for a second
  if(y==0)
  {
  digitalWrite(led2, LOW);   // turn the LED on (HIGH is the voltage level)
  }
}
