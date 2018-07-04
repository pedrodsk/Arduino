#define giraEsquerda 5
#define giraDireita 6
boolean z=3;
char lerSerial[10];
char c;
int x=0;
char ladochar[5];
char velocidadechar[5];
int velocidadeint;
String f="200";
void setup() {
  // put your setup code here, to run once:
  pinMode(giraEsquerda, OUTPUT);
  pinMode(giraDireita, OUTPUT);
  Serial.begin(9600);

}

void loop() {
if(Serial.available()){


  do{
  c=Serial.read();
  lerSerial[x]=c;
//  Serial.println(lerSerial[x]);
  x++;
  delay(1);
}while(c!='\n');
}
x=0; //resetar char serial

ladochar[0]=lerSerial[0];
velocidadechar[0]=lerSerial[2];
velocidadechar[1]=lerSerial[3];
velocidadechar[2]=lerSerial[4];
//Serial.println(ladochar);
//Serial.println(velocidadechar);
//Serial.println(ladoint);
velocidadeint = atoi(velocidadechar);
delay(100);
if(lerSerial[0] == 'e')
girar(0,velocidadeint);

if(lerSerial[0] == 'd')
girar(1,velocidadeint);

 
delay(100);
lerSerial[0]=0;
} 

void girar(boolean lado, int velocidade){
  if(lado==0){
    int testedoo = atoi(f);
analogWrite(giraDireita, f);
delay(200);
analogWrite(giraEsquerda, velocidade);
Serial.print(" Motor girando para esquerda ");
Serial.println(velocidade);
  }
  else{
analogWrite(giraEsquerda, 0);
delay(200);
analogWrite(giraDireita, velocidade);
Serial.print(" Motor girando para direita ");
Serial.println(velocidade);
  }
  }


