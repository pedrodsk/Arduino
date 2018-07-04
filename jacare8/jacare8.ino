#define cabecaH 2
#define cabecaAH 3
#define bracoeH 4
#define bracoeAH 5
#define bracodH 6
#define bracodAH 7
#define raboH 8
#define raboAH 9
#define olhos 11
int pos1;
byte pos2;
byte pos3;
byte pos4;
byte val;
int doido;
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
  doido = random(1, 4);
  switch(doido) {
    case 1:
 if(pos1==0){
 cabecahorario(255,800);
 delay(1000);
  }
 else{
 cabecaahorario(255,800);
 delay(1000);
 }
 break;
 case 2:
 if(pos2==0){
 bracoehorario(255,800);
 delay(1000);
  }
 else{
 bracoeahorario(255,800);
 delay(1000);
 }
 break;
 case 3:
 if(pos3==0){
 bracodhorario(255,800);
 delay(1000);
  }
 else{
 bracodahorario(255,800);
 delay(1000);
 }
 break;
 case 4:
 if(pos4==0){
 rabohorario(255,800);
 delay(1000);
  }
 else{
 raboahorario(255,800);
 delay(1000);
 }
 break;
    case 5:
 if(pos1==0){
 cabecahorario(255,800);
  }
 else{
 cabecaahorario(255,800);
 }
 if(pos2==0){
 bracoehorario(255,800);
  }
 else{
 bracoeahorario(255,800);
 }
 delay(1000);
 break;
 
 case 6:
 if(pos1==0){
 cabecahorario(255,800);
  }
 else{
 cabecaahorario(255,800);
 }
 if(pos3==0){
 bracodhorario(255,800);
  }
 else{
 bracodahorario(255,800);
 }
 delay(1000);
 break;
 case 7:
 if(pos1==0){
 cabecahorario(255,800);
  }
 else{
 cabecaahorario(255,800);
 }
 if(pos4==0){
 rabohorario(255,800);
  }
 else{
 raboahorario(255,800);
 }
 delay(1000);
 break;
 
 case 8:
 if(pos2==0){
 bracoehorario(255,800);
  }
 else{
 bracoeahorario(255,800);
 }
 if(pos3==0){
 bracodhorario(255,800);
  }
 else{
 bracodahorario(255,800);
 }
 delay(1000);
 break;
 
 case 9:
 if(pos2==0){
 bracoehorario(255,800);
  }
 else{
 bracoeahorario(255,800);
 }
 if(pos4==0){
 rabohorario(255,800);
  }
 else{
 raboahorario(255,800);
 }
 delay(1000);
 break;
 
 case 10:
 if(pos3==0){
 bracodhorario(255,800);
  }
 else{
 bracodahorario(255,800);
 }
 if(pos4==0){
 rabohorario(255,800);
  }
 else{
 raboahorario(255,800);
 }
 delay(1000);
 break;
  }//fim do switch case
}

void calibrar(){
    cabecaahorario(255,1000);
    bracoeahorario(255,1000);
    bracodahorario(255,1000);
    raboahorario(255,1000);
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
     void bracoehorario(int velocidade, int tempo){
 analogWrite(bracoeH,velocidade);
 analogWrite(bracoeAH,0);
 delay(tempo);
 pos2=1;
 analogWrite(bracoeH,0);
 analogWrite(bracoeAH,0);
     }
void bracoeahorario(int velocidade, int tempo) {
 analogWrite(bracoeH,0);
 analogWrite(bracoeAH,velocidade);
 delay(tempo);
 analogWrite(bracoeH,0);
 analogWrite(bracoeAH,0);
 pos2=0;
     }
 void bracodhorario (int velocidade, int tempo){
 analogWrite(bracodH,velocidade);
 analogWrite(bracodAH,0);
 delay(tempo);
 pos3=1;
 analogWrite(bracodH,0);
 analogWrite(bracodAH,0);
     }
void bracodahorario(int velocidade, int tempo) {
 analogWrite(bracodH,0);
 analogWrite(bracodAH,velocidade);
 delay(tempo);
 analogWrite(bracodH,0);
 analogWrite(bracodAH,0);
 pos3=0;
     }
      void rabohorario (int velocidade, int tempo){
 analogWrite(raboH,velocidade);
 analogWrite(raboAH,0);
 delay(tempo);
 pos4=1;
 analogWrite(raboH,0);
 analogWrite(raboAH,0);
     }
void raboahorario(int velocidade, int tempo) {
 analogWrite(raboH,0);
 analogWrite(raboAH,velocidade);
 delay(tempo);
 analogWrite(raboH,0);
 analogWrite(raboAH,0);
 pos4=0;
     }
