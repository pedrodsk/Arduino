void setup()
{
    DDRC = B11111111;
}

void loop()
{
  
  PORTB = (1<<PB5);
  delay(1000);
  PORTB = ~(1<<PB5);
  delay(1000);
}











//DDRB = B111111111111;
//PORTB = B11110000; // digital 4~7 HIGH, digital 3~0 LOW
//PORTB = B00001111; // digital 4~7 LOW, digital 3~0 HIGH
