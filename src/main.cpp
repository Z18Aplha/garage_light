#include <Arduino.h>

const int HALL = 2;
const int RELAIS = 4;
int x;

void hall_detect(){
  if (digitalRead(HALL)){
    // no magnet in proximity - turn relais off
    // Serial.println("hall sensor - rising edge (magnet removed)");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RELAIS, LOW);
  }
  else{
    // magnet in proximity - turn relais on
    // Serial.println("hall sensor - falling edge (magnet detected)");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RELAIS, HIGH);
  }
}

void setup() {
  pinMode(HALL, INPUT_PULLUP);
  pinMode(RELAIS, OUTPUT);
  digitalWrite(RELAIS, LOW);
  attachInterrupt(digitalPinToInterrupt(HALL), hall_detect, CHANGE);

  Serial.begin(9600);
}

void loop() {
  // digitalWrite(RELAIS, LOW);
  // delay(1000);
  // digitalWrite(RELAIS, HIGH);
  delay(1000);
}