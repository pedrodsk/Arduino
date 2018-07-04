#define cabecaH 2
#define cabecaAH 3
#define bracoeH 4
#define bracoeAH 5
#define bracodH 6
#define bracodAH 7
#define raboH 8
#define raboAH 9
#define olhos 11
#define ligar1 A0
#define ligar2 A1
#define ligar3 A2
#define ligar4 A3
int pos1;
byte pos2;
byte pos3;
byte pos4;
byte val;
int doido;
int tempo;
int tempo2;
int tempo3;
int tempodoido;

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
  pinMode(ligar1, OUTPUT);
  pinMode(ligar2, OUTPUT);
  pinMode(ligar3, OUTPUT);
  pinMode(ligar4, OUTPUT);


digitalWrite(cabecaH, LOW);
digitalWrite(cabecaAH, LOW);
digitalWrite(bracoeH, LOW);
digitalWrite(bracoeAH, LOW);
digitalWrite(bracodH, LOW);
digitalWrite(bracodAH, LOW);
digitalWrite(raboH, LOW);
digitalWrite(raboAH, LOW);
digitalWrite(ligar1, HIGH);
digitalWrite(ligar2, HIGH);
digitalWrite(ligar3, HIGH);
digitalWrite(ligar4, HIGH);

}
int x=1;
void loop() // run over and over
{
 if(x==1){
 delay(2000);
 calibrar();
 delay(5000);
 x=0;
  }
  doido = random(1,3 );
  tempodoido= random(0, 2);
 
  
  switch(doido) {
    case 1:
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  digitalWrite(ligar1, LOW);
  digitalWrite(ligar2, HIGH);
  delay(200);
  if(pos1==0){
  cabecahorario(255, 200);
  delay(500);
  }
 else{
    cabecaahorario(255,300);
    delay(500);
        }
   digitalWrite(ligar1, HIGH);
   digitalWrite(ligar2, LOW);
 delay(200);
 break;
 case 2:
 delay(100);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
digitalWrite(ligar2, LOW);
digitalWrite(ligar1, HIGH);
 if(pos2==0){
 bracoehorario(255,200);
 delay(500);
  }
 else{
   bracoeahorario(255,300);
 delay(500);
 }
digitalWrite(ligar2, HIGH);
digitalWrite(ligar1, LOW);
 break;
 case 3:
  if(pos3==0){
 bracodhorario(255,150);
 delay(300);
 digitalWrite(ligar2, HIGH);
 delay(100);
  }
 else{
 bracodahorario(255,150);
 delay(300);
 }
 
 break;
 case 4:
 if(pos4==0){
 rabohorario(255,80);
 delay(tempo);
  }
 else{
 raboahorario(255,80);
 delay(tempo);
 }
 break;
  }//fim do switch case
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(tempo3);
}

void calibrar(){
  //cabeca
  digitalWrite(ligar1,LOW);
   cabecaahorario(255,150);
    delay(1000);
    cabecaahorario(255,150);
    delay(1000);
    cabecaahorario(255,150);
    delay(1000);
 
 analogWrite(cabecaH,255);
 analogWrite(cabecaAH,0);
  delay(300);
 //pos3=1;
 analogWrite(cabecaH,0);
 analogWrite(cabecaAH,0);
 digitalWrite(ligar1, HIGH);
 delay(400);
 //fim cabeca
//braco e
  digitalWrite(ligar2,LOW);
   bracoeahorario(255,150);
    delay(1000);
    bracoeahorario(255,150);
    delay(1000);
    bracoeahorario(255,150);
    delay(1000);
 
 analogWrite(bracoeH,255);
 analogWrite(bracoeAH,0);
  delay(300);
 //pos3=1;
 analogWrite(bracoeH,0);
 analogWrite(bracoeAH,0);
 digitalWrite(ligar2, HIGH);
 delay(400);    
    //fim braco e
 //braco d
// bracodahorario(255,110);
//    delay(1000);
 //   bracodahorario(255,110);
 //   delay(1000);
  //  bracodahorario(255,110);
  //  delay(1000);
 
 //analogWrite(bracodH,255);
// analogWrite(bracodAH,0);
// delay(300);
 //pos3=1;
// analogWrite(bracodH,0);
 //analogWrite(bracodAH,0);
  //   delay(500);
    //fim bracod

    //rabo
   
   //raboahorario(255,80);
    //delay(1000);
    //raboahorario(255,80);
    //delay(1000);
    //raboahorario(255,80);
    //delay(1000);
 
// analogWrite(raboH,255);
// analogWrite(raboAH,0);
// delay(100);
 //pos3=1;
// analogWrite(raboH,0);
// analogWrite(raboAH,0);
  //   delay(500);
 //fim rabo
    
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
 //delay(tempo);
 pos4=1;
 //analogWrite(raboH,0);
 //analogWrite(raboAH,0);
     }
void raboahorario(int velocidade, int tempo) {
 analogWrite(raboH,0);
 analogWrite(raboAH,velocidade);
 //delay(tempo);
 //analogWrite(raboH,0);
 //analogWrite(raboAH,0);
 pos4=0;
     }
