void setup() {
pinMode(5, OUTPUT);
Serial.begin(9600);
}

char c;
char velocidade[5];
int velocidadeint;
int x;
int y=3;
void loop() {

  if(Serial.available()){

  do{
  c=Serial.read();
  velocidade[x]=c;
 // Serial.println(velocidade[x]);
  x++;
  y=0;
  delay(100);
}while(c!='\n');
}
x=0; //resetar char serial
  velocidadeint = atoi(velocidade);
   
  delay(1000);
 //velocidade = atoi(x);
if(y==0){
  analogWrite(5,velocidadeint);
  Serial.println(velocidadeint);
 // Serial.println(velocidadeint);
//for(int t=0;t<3;t++){
    y=1;
}

  }
  
