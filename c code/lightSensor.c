// Quick Demo of light sensor

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"

// -------- Functions --------- //
static inline void initADC0(void) {
  ADMUX |= (1 << REFS0);                  /* reference voltage on AVCC */
  ADCSRA |= (1 << ADPS2);                   /* ADC clock prescaler /16 */
  ADCSRA |= (1 << ADEN);     /* enable ADC */
}



int main(void) {
  // -------- Inits --------- //
  uint8_t ledValue;
  uint16_t adcValue;
  uint8_t i;

  initADC0();
 
  // ------ Event loop ------ //
  while (1) {

    ADCSRA |= (1 << ADSC);                     /* start ADC conversion */
    loop_until_bit_is_clear(ADCSRA, ADSC);          /* wait until done */
    adcValue = ADC;                                     /* read ADC in */
                           
    _delay_ms(50);
  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
