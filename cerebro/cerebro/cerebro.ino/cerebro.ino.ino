#define echoPin 12 //Pino 13 recebe o pulso do echo  
#define trigPin 13 //Pino 12 envia o pulso para gerar o echo  
#define bomba1 10  
void setup()  
{  
   Serial.begin(9600); //inicia a porta serial  
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)  
   pinMode(bomba1, OUTPUT);
}  
  int distAnt=0;
void loop()  
{  
  int distancia = distancia2();
  if(distancia >2 && distancia != distAnt && distancia <150){
 // Serial.print("Distancia em CM: ");  
  Serial.println(distancia);  
   //espera 1 segundo para fazer a leitura novamente
  distAnt = distancia;
  if(distancia<150 && distancia>100)
  {
    Serial.println("30");
    analogWrite(bomba1,30);
  }
  if(distancia<100 && distancia>80)
  {
    Serial.println("60");
    analogWrite(bomba1,60);
  }
  if(distancia<80 && distancia>60)
  {
    Serial.println("90");
    analogWrite(bomba1,90);
  }
  if(distancia<60 && distancia>40)
  {
    Serial.println("120");
    analogWrite(bomba1,120);
  }
  if(distancia<40 && distancia>20)
  {
    Serial.println("140");
    analogWrite(bomba1,140);
  }
  if(distancia<20 && distancia>2)
  {
    Serial.println("160");
    analogWrite(bomba1,160);
  }
  }
  delay(500);
}
int distancia2() {
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);  
    long duration = pulseIn(echoPin,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
    long distancia = duration /29 / 2 ;  
  return distancia;
}

