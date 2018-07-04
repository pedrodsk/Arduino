/*
loop
int i = 0;
int read_data[2];
while(i<2){
while(Serial.available()){
read_data[i] = Serial.read();
i++;
}
}
power = Concatena_Numeros(read_data[0],read_data[1]);
Serial.println(power);
 
}
*/
#define lamp1 10
#define lamp2 11
//#define lamp3 11
volatile int power1 = 0;
int led = 8;
volatile int x=0;
void setup()
{
  //Serial.begin(9600);
  pinMode(lamp1, OUTPUT);
 pinMode(lamp2, OUTPUT);
 
 // pinMode(lamp8, OUTPUT);
  attachInterrupt(0, zero_crosss_int, FALLING);
pinMode(led, OUTPUT);  
}
 
void loop()
{
  // Seta a potência para diferentes níveis. Se o sistema estiver conectado a uma lâmpada,
  // esta vai variar de brilho.
  digitalWrite(led, HIGH);
for(int i=10;i<70;i++){
  power1=i;
  delay(40);
}
for(int i=70;i>10;i--){
  power1=i;
  delay(40);
}

}
void zero_crosss_int()  
{
  // Cálculo do ângulo de disparo: 60Hz-> 8.33ms (1/2 ciclo)
  // (8333us - 8.33us) / 256 = 32 (aprox)
  if(x==0){
  int auxpower = map(power1, 0, 100, 0, 221);
  int powertime1 = (32*(256-auxpower));
  //int powertime2 = (32*(256-power2));  
  // Mantém o circuito desligado por powertime microssegundos 
  delayMicroseconds(powertime1);
  //delayMicroseconds(powertime2);  
  // Envia sinal ao TRIAC para que ele passe a conduzir 
  digitalWrite(lamp1, HIGH);
  digitalWrite(lamp2, HIGH);

  delayMicroseconds(8.33);      
  // Desliga o pulso
  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);
 // x++;
    }
}
