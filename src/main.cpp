#include <Arduino.h>
#include "display/display.hpp"
#include "led/led.hpp"
Display display = Display();
Led led = Led();
void setup()
{
  Serial.begin(9600);
  display.init();
  display.test();
  led.init();

  // put your setup code here, to run once:
}

void loop()
{
  display.update();
  led.update();
  // put your main code here, to run repeatedly:
}