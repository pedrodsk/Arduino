#define cabecaH 3
#define cabecaAH 5
#define bracoeH 6
#define bracoeAH 9
#define bracodH 10
#define bracodAH 11
#define raboH A0
#define raboAH A1
#define olhos A2
byte pos1;
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

void loop() // run over and over
{
 
}
void calibrar(){
  
    digitalWrite(cabecaH,HIGH);
    digitalWrite(cabecaAH,LOW);
    delay(500);
    digitalWrite(bracoeH,HIGH);
    digitalWrite(bracoeAH,LOW);
    delay(3000);
    digitalWrite(cabecaH,LOW);
    digitalWrite(cabecaAH,LOW);
    delay(500);
    digitalWrite(bracoeH,LOW);
    digitalWrite(bracoeAH,LOW);
  
}//fim calibrar
void cabecahorario(){
 digitalWrite(cabecaH,HIGH);
 digitalWrite(cabecaAH,LOW);
 delay(2000);
 digitalWrite(cabecaf,LOW);
 digitalWrite(cabecat,LOW);
     }
void cabecaahorario() {
 digitalWrite(cabecaH,LOW);
 digitalWrite(cabecaAH,HIGH);
 delay(2000);
 digitalWrite(cabecaH,LOW);
 digitalWrite(cabecaAH,LOW);
     }
