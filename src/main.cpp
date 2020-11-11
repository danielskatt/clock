#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "header.h"
#include "..//secret.h"

// ****  Configue settings to app BLYNK ****
// char auth[] = "ADD-KEY-TOKEN-HERE";
// char ssid[] = "ADD-WIFI-NETWORK-HERE";
// char pass[] = "ADD-PASSWORD-HERE";
// (Set password to "" for open networks)
// *****************************************

static step_motor m_1 = {STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4};
static step_motor m_2 = {STEPPER_PIN_5, STEPPER_PIN_6, STEPPER_PIN_7, STEPPER_PIN_8};
static step_motor m_3 = {STEPPER_PIN_9, STEPPER_PIN_10, STEPPER_PIN_11, STEPPER_PIN_12};

int counter = 1;
// only for testing
int first_digit = 0, middle_digit = 0, last_digit = 0;

BLYNK_WRITE(V1)
{
  step_clockwise(m_1);
}
BLYNK_WRITE(V2)
{
  step_counter_clockwise(m_2);
}
BLYNK_WRITE(V3)
{
  step_counter_clockwise(m_3);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
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
  u_long time_millis = millis();
  // set time interval for last digit in ms
  u_int time = 60000;

  Blynk.run();

  if(time * counter <= time_millis)
  {
    // counter last digit
    step_clockwise(m_1);
    counter++;
    last_digit++;
    Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
    if(counter % 10 == 0)
    {
      // counter middle digit
      step_counter_clockwise(m_2);
      Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
      middle_digit++;
    }
    if(counter % 60 == 0)
    {
      // counter first digit
      step_counter_clockwise(m_3);
      Serial.printf("%0d:%0d:%0d\n", first_digit, middle_digit, last_digit);
      first_digit++;
    }
  }
}

