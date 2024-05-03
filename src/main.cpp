#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <math.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "bit.h"

#define PWMCONTROL PINB2 // pwm control

void setup(){
  bitSet(DDRB, PWMCONTROL);
  set_tc1_mode(11); // PWM phase correct mode
  bitSet(TCCR1A, COM1B1); // Clear OC1A on compare match, set OC1A at BOTTOM
  setPrescaler_tc1(2); // 8 prescaler
}

int main(){
  setup();
  // bitClear(PORTD, IN2);
  OCR1A = 10000; // 16e6 / (21008)

  while(1){
    OCR1B = 4100;
    _delay_ms(2000);

    OCR1B = 6100;
    _delay_ms(2000);

    OCR1B = 9000;
    _delay_ms(2000);
  }
}