#define giraEsquerda 5
#define giraDireita 6
#define b1 3
#define b2 4
#define entrada A0
int velocidade;
int x=0;
boolean y=0;
void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
//  Serial.begin(9600);
//  pinMode(A0, INPUT);
}

void loop() {
  //int velocidade
  if(x==2){
  velocidade = analogRead(entrada);
  analogWrite(giraEsquerda, velocidade/4);
  delay(10);
    }
  
  if(x==3){
  velocidade = analogRead(entrada);
  analogWrite(giraDireita, velocidade/4);
  delay(10);
  }
 // velocidade = 0;
    if(digitalRead(b1) == LOW ) {
  analogWrite(giraDireita, LOW);
  delay(1000);
  x=2;
  }

  if(digitalRead(b2) == LOW ) {
  digitalWrite(giraEsquerda, LOW);
  delay(1000);
  x=3;
  }
  

}
