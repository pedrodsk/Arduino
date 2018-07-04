#define lamp1 10
#define led 8
volatile int power1 = 0;
int x=0;
int luz;
void setup() {
  Serial.begin(9600);
  pinMode(lamp1, OUTPUT);
  attachInterrupt(0, zero_cross, FALLING);
}

void loop() {
  //Serial.println(x);
  
  
  for(x=0;x<=100;x++){
    luz=x;
    delay(50);
  }
  
  for(x=100;x>=0;x--){
    luz=x;
    delay(50);
  }
  luz=20;
 
}
void zero_cross()  
{
 // x++;
  
  int auxpower = map(luz, 100, 0, 500, 6500);
  //x = (32*(256-auxpower));
  delayMicroseconds(5500);
  digitalWrite(lamp1, HIGH);
  delayMicroseconds(8.33);      
  digitalWrite(lamp1, LOW);
    
}

