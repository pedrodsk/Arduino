#define lamp1 5
#define lamp2 4 
volatile int power1 = 0;
volatile int power2 = 0;
volatile int x=0;
void setup()
{
  //Serial.begin(9600);
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  attachInterrupt(0, zero_crosss_int, FALLING);  
}
 
void loop()
{
  // Seta a potência para diferentes níveis. Se o sistema estiver conectado a uma lâmpada,
  // esta vai variar de brilho.
  power1=80;
  power2=20;
  //delay(300);
  /*
  power1=220;
  power2=0;
  delay(300);
  power1=60;
  power2=0;
  delay(300);
  power1=80;
  power2=0;
  delay(300);
  power1=80;
  power2=20;
  delay(300);
  power1=80;
  power2=40;
  delay(300);
  power1=80;
  power2=60;
  delay(300);
  power1=80;
  power2=80;
  delay(300);
  power1=80;
  power2=100;
  delay(300);
  power1=80;
  power2=120;
  delay(300);
  power1=80;
  power2=140;
  delay(300);
  power1=80;
  power2=160;
  delay(300);
  power1=100;
  power2=160;
  delay(300);
  power1=120;
  power2=160;
  delay(300);
  power1=140;
  power2=160;
  delay(300);
  power1=160;
  power2=160;
  delay(300);
  power1=180;
  power2=180;
  delay(300);
  power1=200;
  power2=200;
  delay(300);
  power1=220;
  power2=220;
  delay(300);
  power1=20;
  power2=20;/*
    //power=60;
  //delay(100);
  //power=120;
  //delay(100);
  //power=180;
  //delay(100);
  //power=240;
  //delay(100);
 /* for(int i=0;i<220;i++){
  power=i;
  delay(30);
}
  for(int i=220;i>0;i--){
  power=i;
  delay(30);
}*/
}
void zero_crosss_int()  
{
  // Cálculo do ângulo de disparo: 60Hz-> 8.33ms (1/2 ciclo)
  // (8333us - 8.33us) / 256 = 32 (aprox)
  if(x==0){
  int auxpower = map(power1, 0, 100, 0, 241);
  int powertime1 = (32*(256-auxpower));
  //int powertime2 = (32*(256-power2));  
  // Mantém o circuito desligado por powertime microssegundos 
  delayMicroseconds(powertime1);
  //delayMicroseconds(powertime2);  
  // Envia sinal ao TRIAC para que ele passe a conduzir 
  digitalWrite(lamp1, HIGH);
  delayMicroseconds(8.33);      
  // Desliga o pulso
  digitalWrite(lamp1, LOW);
  x++;
    }
    if(power1>=power2){
  int auxpower = map(power1, 0, 100, 0, 241);
  int powertime1 = (32*(256-auxpower));
  int auxpower2 = map(power2, 0, 100, 0, 241);
  int powertime2 = (32*(256-auxpower2)-powertime1+1);  
  // Mantém o circuito desligado por powertime microssegundos 
  //delayMicroseconds(powertime1);
  delayMicroseconds(powertime2);  
  // Envia sinal ao TRIAC para que ele passe a conduzir 
  digitalWrite(lamp2, HIGH);
  delayMicroseconds(8.33);      
  // Desliga o pulso
  digitalWrite(lamp2, LOW);
    }
    x=0;
}

void zero_crosss_int1()  
{
  // Cálculo do ângulo de disparo: 60Hz-> 8.33ms (1/2 ciclo)
  // (8333us - 8.33us) / 256 = 32 (aprox)
  if(power2>0){
    int auxpower2 = map(power2, 0, 100, 0, 241);
  int powertime2 = (32*(256-auxpower2));
  //int powertime2 = (16*(256-power2));  
  // Mantém o circuito desligado por powertime microssegundos 
  delayMicroseconds(powertime2);   
  // Envia sinal ao TRIAC para que ele passe a conduzir 
  digitalWrite(lamp2, HIGH);
  delayMicroseconds(8.33);      
  // Desliga o pulso
  digitalWrite(lamp2, LOW);
  }
}
 void zeroconta()
  {
    if(x==0){
    zero_crosss_int();
  x++;
}
delay(10);
  if(x==1){
   zero_crosss_int1();
 x=0;
 }
        

  
}
