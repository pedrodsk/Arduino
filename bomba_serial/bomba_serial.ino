char lerSerial[10]; //char de 10 posições
char c; // char flag
int x=0; //variavel contador
//int y=0;
void setup() {
  
pinMode(10,OUTPUT); //pino 9 como saída
Serial.begin(9600); //baud rate da comunicação serial
}

void loop() {
if(Serial.available()){
  do{
  c=Serial.read(); //char c recebe o caracterer a caracterer da Serial
  lerSerial[x]=c; //atribui o valor lido pela serial ao char lerSerial
 
//  Serial.println(lerSerial[x]);
  x++; //incrementa a variável x.. x=0, x=1.. etc
  delay(5); //delay 1ms
}while(c!='\n'); //faz o loop enquanto o caracterer C não é igual a \n (fim de linha)
}
x=0; //zera o caracter

int converter = atoi(lerSerial); //função para converter o char em inteiro
//converter = map(converter, 0, 99,0,255);
if(converter != 0){
analogWrite(10,converter); //pwm
delay(250);
digitalWrite(10,LOW);
Serial.println(converter);
}
else
analogWrite(10,LOW);
delay(1000);
}

