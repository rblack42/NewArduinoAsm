#include <avr/io.h>

int i;

#define LED_PIN 5
#define LED_CONFIG  (DDRB |= (1<<LED_PIN))
#define LED_ON          (PORTB |= (1<<LED_PIN))
#define LED_OFF         (PORTB &= ~(1<<LED_PIN))

// Delay 10ms
void T0Delay() {
  // Load initial count value
  TCNT0 = 0;
  // Load compare match value
  OCR0A = 0x9C;
  // CTC mode, prescaler 1024
  TCCR0A = (1 << WGM01);
  TCCR0B = (1 << CS02) | (1 << CS00);
  // Wait until timer 0 compare match
  while (!(TIFR0 & (1 << OCF0A)));
  // Stop timer 0
  TCCR0B = 0;
  // Clear OCF0A flag
  TIFR0 = (1 << OCF0A);
}

void setup() {
  LED_CONFIG;
}

void loop() {
  // Toggle LED on pin 13
  LED_ON;
  // Delay 1s(100*10ms)
  for (i = 0; i < 100; i++) 
    T0Delay();
  LED_OFF;
  for(i = 0; i<100;i++)
      T0Delay();
}

int main(void) {
    setup();
    while(1) {
        loop();
    }
}

