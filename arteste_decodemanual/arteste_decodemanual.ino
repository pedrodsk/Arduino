
#define TIMER_ENABLE_INTR   (TIMSK2 = _BV(OCIE2A))
#define TIMER_DISABLE_INTR  (TIMSK2 = 0)
#define TIMER_PWM_PIN  3
#define TIMER_ENABLE_PWM   (TCCR1A |= _BV(COM1A1))
#define TIMER_DISABLE_PWM  (TCCR1A &= ~(_BV(COM1A1)))
#define SYSCLOCK  16000000
#define TIMER_CONFIG_KHZ(val) ({ \
  const uint8_t pwmval = SYSCLOCK / 2000 / (val); \
  TCCR2A               = _BV(WGM20); \
  TCCR2B               = _BV(WGM22) | _BV(CS20); \
  OCR2A                = pwmval; \
  OCR2B                = pwmval / 3; \
})
void setup() {
  // put your setup code here, to run once:
Serial.begin(115000);

}

void loop() {
  if(Serial.read() == 'a')
  {
unsigned int raw[72] = {9000,4400,600,500,600,500,550,550,550,550,550,550,500,600,500,600,500,550,550,1700,500,1700,550,1650,550,550,550,1650,550,1700,500,1700,550,1650,550,550,550,550,550,1650,550,1650,550,1700,500,600,500,1700,550,550,500,1700,550,1650,550,550,550,550,550,550,550,1650,550,550,550,1650,550,-24436,8850,2250,550};
sendRaw(raw,72,38);
delay(200);
Serial.println("enviou");
/*
for(int x;x<72;x++){
digitalWrite(3,LOW);
delayMicroseconds(raw[x]);
//Serial.println(x);
digitalWrite(3,HIGH);
x++;
//Serial.println(x);
delayMicroseconds(raw[x]);
x++;
}
*/
}
}
//+=============================================================================
void  sendRaw (unsigned int buf[],  int len,  int hz)
{
  // Set IR carrier frequency
  enableIROut(hz);

  for (int i = 0;  i < len;  i++) {
    if (i & 1)  space(buf[i]) ;
    else        mark (buf[i]) ;
  }

  space(0);  // Always end with the LED off
}

//+=============================================================================
// Sends an IR mark for the specified number of microseconds.
// The mark output is modulated at the PWM frequency.
//
void  mark (int time)
{
  TIMER_ENABLE_PWM; // Enable pin 3 PWM output
  if (time > 0) delayMicroseconds(time);
}

//+=============================================================================
// Leave pin off for time (given in microseconds)
// Sends an IR space for the specified number of microseconds.
// A space is no output, so the PWM output is disabled.
//
void  space (int time)
{
  TIMER_DISABLE_PWM; // Disable pin 3 PWM output
  if (time > 0) delayMicroseconds(time);
}

//+=============================================================================
// Enables IR output.  The khz value controls the modulation frequency in kilohertz.
// The IR output will be on pin 3 (OC2B).
// This routine is designed for 36-40KHz; if you use it for other values, it's up to you
// to make sure it gives reasonable results.  (Watch out for overflow / underflow / rounding.)
// TIMER2 is used in phase-correct PWM mode, with OCR2A controlling the frequency and OCR2B
// controlling the duty cycle.
// There is no prescaling, so the output frequency is 16MHz / (2 * OCR2A)
// To turn the output on and off, we leave the PWM running, but connect and disconnect the output pin.
// A few hours staring at the ATmega documentation and this will all make sense.
// See my Secrets of Arduino PWM at http://arcfn.com/2009/07/secrets-of-arduino-pwm.html for details.
//
void  enableIROut (int khz)
{
  // Disable the Timer2 Interrupt (which is used for receiving IR)
  TIMER_DISABLE_INTR; //Timer2 Overflow Interrupt

  pinMode(TIMER_PWM_PIN, OUTPUT);
  digitalWrite(TIMER_PWM_PIN, LOW); // When not sending PWM, we want it low

  // COM2A = 00: disconnect OC2A
  // COM2B = 00: disconnect OC2B; to send signal set to 10: OC2B non-inverted
  // WGM2 = 101: phase-correct PWM with OCRA as top
  // CS2  = 000: no prescaling
  // The top value for the timer.  The modulation frequency will be SYSCLOCK / 2 / OCR2A.
  TIMER_CONFIG_KHZ(khz);
}

