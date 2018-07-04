#define echoPin 12 //Pino 13 recebe o pulso do echo  
#define trigPin 13 //Pino 12 envia o pulso para gerar o echo  
  
void setup()  
{  
   Serial.begin(9600); //inicia a porta serial  
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)  
}  
  int distAnt=0;
void loop()  
{  
  int distancia = distancia2();
  if(distancia > 2 && distancia != distAnt){
  Serial.print("Distancia em CM: ");  
  Serial.println(distancia);  
   //espera 1 segundo para fazer a leitura novamente
  distAnt = distancia;
  }
  delay(1000);
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

