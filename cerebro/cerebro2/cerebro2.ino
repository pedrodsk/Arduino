#define echoPin 12   
#define trigPin 13   
#define bomba1 10  
void setup()  
{  
   //Serial.begin(9600);   
   pinMode(echoPin, INPUT);   
   pinMode(trigPin, OUTPUT);  
   pinMode(bomba1, OUTPUT);
}  
  int distAnt=0;
void loop()  
{  
  int distancia = distancia2();
  if(distancia <80 && distancia !=0){
  //Serial.println(distancia);  
  
  distAnt = distancia;
  int velocidade = map(distancia, 1, 79, 80, 30);
  //int tempo = map(distancia, 1, 59, 100, 28);
  //Serial.println(velocidade);
  analogWrite(bomba1,velocidade);
  delay(150);
  digitalWrite(bomba1,LOW);
  delay(400);
  //analogWrite(bomba1,LOW);
  }
  if(distancia>80 || distancia==0)
  digitalWrite(bomba1,LOW);
  delay(100);
}
int distancia2() {
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);  
    long duration = pulseIn(echoPin,HIGH);  
    long distancia = duration /29 / 2 ;  
  return distancia;
}

