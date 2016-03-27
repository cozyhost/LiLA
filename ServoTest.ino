#include <Servo.h>

Servo head;

void setup() {
  head.attach(9);
  head.write(90);
  delay(1000);
}

void loop() {
 
  head.write(90);
  delay(1000);
  head.write(45);
  delay(1000);
  head.write(0);
  delay(1000);
  head.write(45);
  delay(1000);
  head.write(90);
  delay(1000);
  head.write(135);
  delay(1000);
  head.write(180);
  delay(1000);
  head.write(135);
  delay(1000);
}
