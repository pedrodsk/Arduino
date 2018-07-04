boolean estado=1;
boolean x=0;
boolean debounce;
void setup() {
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  

}

void loop() {
 /*  if(digitalRead(2) == 0){
     unsigned long tempo = millis(); 
     while(tempo + 50 > millis());
  }    
  */
     if(digitalRead(2) == 0)  debounce = 1;
 
  if(digitalRead(2)==HIGH && debounce ==1) {
  digitalWrite(13,estado);
  estado=!estado;
  debounce=0;
  }
    
    }
