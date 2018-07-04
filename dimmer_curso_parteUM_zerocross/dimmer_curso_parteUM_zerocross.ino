int x;
long tempoAnterior = 0;
unsigned long tempo;

void setup() {
  Serial.begin(115200);
  attachInterrupt(0, zero_cross, FALLING);
}

void loop() {

  if(tempo - tempoAnterior > 1000) {
  Serial.println(x);
  tempoAnterior=tempo;
  x=0;
  }

}
void zero_cross()  
{
  x++;
  tempo = millis();
}

