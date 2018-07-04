/*
#############################################################
# Controle de posição de servo motor via serial.(bluetooth) # 
# Autor: Pedro. Curso de Kleber - UFCG                      # 
#############################################################
*/

char lerSerial[10]; //char de 10 posições
char c; // char flag
int x=0; //variavel contador
//int y=0;
void setup() {
  
pinMode(9,OUTPUT); //pino 9 como saída
Serial.begin(115000); //baud rate da comunicação serial
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
if(converter != 0){
converter = map(converter,1,100,500,2100); //função que mapeia a variavel 1=500 100=2100.. regra de 3
//Serial.println(converter);

digitalWrite(9,HIGH); //pwm
delayMicroseconds(converter);//490 a 1900
//Serial.println(converter);
digitalWrite(9,LOW); //pwm
delay(5); //pwm
//y=0;
}
}
