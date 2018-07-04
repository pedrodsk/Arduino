int seg1=0,
minuto1=0,
hor1=0;
int seg2=0,
minuto2=0,
hor2=0; 
void setup()
{
Serial.begin(9600);
}
void loop()
{
static unsigned long ult_tempo = 0;
int tempo = millis();
if(tempo - ult_tempo >= 1000) {
ult_tempo = tempo;
seg1++;
}
if(seg1>=10) {
seg1 = 0;
seg2++;
}
if(seg2>=6) {
seg2 = 0;
minuto1++;
}
if(minuto1>=10) {
minuto1=0;
minuto2++;
}
if(minuto2>=6) {
minuto2=0;
hor1++;
}
if(hor1>=10) {
hor1=0;
hor2++;
}
if(hor2>=6) {
hor2=0;
}
Serial.print(hor2);
Serial.print(hor1);
Serial.print(":");
Serial.print(minuto2);
Serial.print(minuto1);
Serial.print(":");
Serial.println(seg2);
Serial.println(seg1);
delay(1000);
}

