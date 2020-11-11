#ifndef header_h
#define header_h

#define BLYNK_PRINT Serial
// pin configuration
  // motor 1
#define STEPPER_PIN_1 21
#define STEPPER_PIN_2 17
#define STEPPER_PIN_3 16
#define STEPPER_PIN_4 19
  // motor 2
#define STEPPER_PIN_5 23
#define STEPPER_PIN_6 22
#define STEPPER_PIN_7 14
#define STEPPER_PIN_8 32
  // motor 3
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
} step_motor;


/*
  ***** Function rotate step motor clockwise *****
  Input = A struck with I/O pin configuration
*/  
void step_clockwise(step_motor pin);
/*
  ***** Function rotate step motor counter-clockwise *****
  Input = A struck with I/O pin configuration
*/  
void step_counter_clockwise(step_motor pin);

#endif