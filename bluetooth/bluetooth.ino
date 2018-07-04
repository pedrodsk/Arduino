char lerSerial[10]; //char de 10 posições
char c; // char flag
int x=0; //variavel contador
bool a;
void setup() {
  Serial.begin(9600);
  digitalWrite(13,OUTPUT);
}

void loop() {
  if(Serial.available()){
//  do{
  c=Serial.read(); //char c recebe o caracterer a caracterer da Serial
  lerSerial[x]=c; //atribui o valor lido pela serial ao char lerSerial
 
//  Serial.println(lerSerial[x]);
  x++; //incrementa a variável x.. x=0, x=1.. etc
  delay(5); //delay 1ms
//}while(c!='\n'); //faz o loop enquanto o caracterer C não é igual a \n (fim de linha)
}
x=0; //zera o caracter
Serial.println("a");
delay(1000);
if(c=='a'){
     digitalWrite(13,HIGH);
     
    }
if(c=='b'){
     digitalWrite(13,LOW);
     
    }
}
