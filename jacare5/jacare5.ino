#define cabecaH 3
#define cabecaAH 5
#define bracoeH 6
#define bracoeAH 9
#define bracodH 10
#define bracodAH 11
#define raboH A0
#define raboAH A1
#define olhos A2
int pos1;
byte pos2;
byte pos3;
byte pos4;
byte val;
//char comando;

void setup()  
{
  pinMode(cabecaH, OUTPUT);
  pinMode(cabecaAH, OUTPUT);
  pinMode(bracoeH, OUTPUT);
  pinMode(bracoeAH, OUTPUT);
  pinMode(bracodH, OUTPUT);
  pinMode(bracodAH, OUTPUT);
  pinMode(raboH, OUTPUT);
  pinMode(raboAH, OUTPUT);

digitalWrite(cabecaH, LOW);
digitalWrite(cabecaAH, LOW);
digitalWrite(bracoeH, LOW);
digitalWrite(bracoeAH, LOW);
digitalWrite(bracodH, LOW);
digitalWrite(bracodAH, LOW);
digitalWrite(raboH, LOW);
digitalWrite(raboAH, LOW);
}
int x=1;
void loop() // run over and over
{
 if(x==1){
 delay(2000);
 calibrar();
 delay(8000);
 x=0;
  }
 if(pos1==0){
 cabecahorario(255,800);
 delay(1000);
  }
 if(pos1==1){
 cabecaahorario(255,800);
 delay(1000);
 }
}

void calibrar(){
    cabecahorario(255,1000);
}//fim calibrar

void cabecahorario(int velocidade, int tempo){
 analogWrite(cabecaH,velocidade);
 analogWrite(cabecaAH,0);
 delay(tempo);
 pos1=1;
 analogWrite(cabecaH,0);
 analogWrite(cabecaAH,0);
     }
void cabecaahorario(int velocidade, int tempo) {
 analogWrite(cabecaH,0);
 analogWrite(cabecaAH,velocidade);
 delay(tempo);
 analogWrite(cabecaH,0);
 analogWrite(cabecaAH,0);
 pos1=0;
     }
