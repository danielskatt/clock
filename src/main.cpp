#include <Arduino.h>

#define STEPPER_PIN_1 21
#define STEPPER_PIN_2 17
#define STEPPER_PIN_3 16
#define STEPPER_PIN_4 19
#define STEPPER_PIN_5 23
#define STEPPER_PIN_6 22
#define STEPPER_PIN_7 14
#define STEPPER_PIN_8 32
#define STEPPER_PIN_9 15
#define STEPPER_PIN_10 33
#define STEPPER_PIN_11 27
#define STEPPER_PIN_12 12
#define DELAY_BETWEEN_STEPS 5
typedef struct {
  int pin_1;
  int pin_2;
  int pin_3;
  int pin_4;
}stepper;
u_int counter = 1;
// only for testing
u_int first_digit = 0, middle_digit = 0, last_digit = 0;
void step_clockwise(int milli_seconds, int counter, stepper pin);
void step_counter_clockwise(int milli_seconds, int counter, stepper pin);

void setup()
{
Serial.begin(9600);
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(STEPPER_PIN_5, OUTPUT);
pinMode(STEPPER_PIN_6, OUTPUT);
pinMode(STEPPER_PIN_7, OUTPUT);
pinMode(STEPPER_PIN_8, OUTPUT);
pinMode(STEPPER_PIN_9, OUTPUT);
pinMode(STEPPER_PIN_10, OUTPUT);
pinMode(STEPPER_PIN_11, OUTPUT);
pinMode(STEPPER_PIN_12, OUTPUT);
}
void loop()
{
  stepper motor_1 = {STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4};
  stepper motor_2 = {STEPPER_PIN_5, STEPPER_PIN_6, STEPPER_PIN_7, STEPPER_PIN_8};
  stepper motor_3 = {STEPPER_PIN_9, STEPPER_PIN_10, STEPPER_PIN_11, STEPPER_PIN_12};
  u_long time_millis = millis();
  // set time interval for last digit
  u_int time = 6000;

  if(time * counter <= time_millis)
  {
    // counter last digit
    step_clockwise(DELAY_BETWEEN_STEPS, 45, motor_1);
    counter++;
    last_digit++;
    Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
    if(counter % 10 == 0)
    {
      // counter middle digit
      step_counter_clockwise(DELAY_BETWEEN_STEPS, 51, motor_2);
      Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
      middle_digit++;
    }
    if(counter % 60 == 0)
    {
      // counter first digit
      step_counter_clockwise(DELAY_BETWEEN_STEPS, 51, motor_3);
      Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
      first_digit++;
    }
  }
  // for testing
  // Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
}
void step_clockwise(int milli_seconds, int counter, stepper pin)
{
  while(counter--)
  {
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, HIGH);
    delay(milli_seconds);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, HIGH);
    digitalWrite(pin.pin_4, LOW);
    delay(milli_seconds);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, HIGH);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(milli_seconds);
    digitalWrite(pin.pin_1, HIGH);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(milli_seconds);
  }
}
void step_counter_clockwise(int milli_seconds, int counter, stepper pin)
{
  while(counter--)
  {
    digitalWrite(pin.pin_1, HIGH);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(milli_seconds);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, HIGH);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, LOW);
    delay(milli_seconds);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, HIGH);
    digitalWrite(pin.pin_4, LOW);
    delay(milli_seconds);
    digitalWrite(pin.pin_1, LOW);
    digitalWrite(pin.pin_2, LOW);
    digitalWrite(pin.pin_3, LOW);
    digitalWrite(pin.pin_4, HIGH);
    delay(milli_seconds);
  }
}
