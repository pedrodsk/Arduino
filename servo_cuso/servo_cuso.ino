
char lerSerial[10];
char c;
int x=0;
int y=0;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
Serial.begin(115000);
}

void loop() {
if(Serial.available()){
  do{
  c=Serial.read();
  lerSerial[x]=c;
  y=2;
//  Serial.println(lerSerial[x]);
  x++;
  delay(1);
}while(c!='\n');
}
x=0;

int converter = atoi(lerSerial);
if(converter != 0){
converter = map(converter,1,100,500,2100); 
//Serial.println(converter);

digitalWrite(9,HIGH);
delayMicroseconds(converter);//490 a 1900
//Serial.println(converter);
digitalWrite(9,LOW);
delay(5);
y=0;
}
}
