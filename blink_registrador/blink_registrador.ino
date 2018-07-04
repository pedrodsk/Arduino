#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
int main() {
   DDRB = (1<<PB5);
while(1) {
  PORTB = PORTB ^(1<<PB5);
  _delay_ms(1000);
}
}

