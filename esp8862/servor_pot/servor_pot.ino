#define pot A0;
void setup() {
 // pinMode(9,OUTPUT);
//  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
int valorpot = analogRead(A0);
//Serial.println(valorpot);
int converter = map(valorpot,1,882,500,2100);
//Serial.println(converter);
//if(converter != 0){
digitalWrite(9,HIGH); //pwm
delayMicroseconds(converter);//490 a 1900
digitalWrite(9,LOW); //pwm
delay(15); //pwm
//delay(5000);
//}
}


