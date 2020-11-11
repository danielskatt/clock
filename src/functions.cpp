#include <Arduino.h>
#include "header.h"

extern int counter;

void step_clockwise(step_motor pin)
{
  while(counter--)
  {
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, HIGH);
    delay(DELAY_BETWEEN_STEPS);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, HIGH);
    digitalWrite(pin.pin_4, LOW);
    delay(DELAY_BETWEEN_STEPS);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, HIGH);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(DELAY_BETWEEN_STEPS);
    digitalWrite(pin.pin_1, HIGH);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(DELAY_BETWEEN_STEPS);
  }
}
void step_counter_clockwise(step_motor pin)
{
  while(counter--)
  {
    digitalWrite(pin.pin_1, HIGH);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(DELAY_BETWEEN_STEPS);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, HIGH);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(DELAY_BETWEEN_STEPS);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, HIGH);
    digitalWrite(pin.pin_4, LOW);
    delay(DELAY_BETWEEN_STEPS);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, HIGH);
    delay(DELAY_BETWEEN_STEPS);
  }
}