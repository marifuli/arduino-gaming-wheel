#include <RotaryEncoder.h>

#define IN1 7
#define IN2 8

RotaryEncoder *encoder = nullptr;

void checkPosition () {
  encoder->tick();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  encoder = new RotaryEncoder(IN1, IN2, RotaryEncoder::LatchMode::TWO03);

  attachInterrupt(digitalPinToInterrupt(IN1), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(IN2), checkPosition, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int pos = 0;
  encoder->tick();

  int newPos = encoder->getPosition();
  if(pos != newPos) {
    Serial.println(newPos);
    pos = newPos;
  }
}














