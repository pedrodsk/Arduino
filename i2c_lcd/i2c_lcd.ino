#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 lcd.begin (16,2);
}
 
void loop()
{
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Teste neste lcd1");
  lcd.setCursor(0,1);
  lcd.print("LCD do mal,pegou");
  delay(1000);
  lcd.setBacklight(LOW);
  delay(1000);
}
