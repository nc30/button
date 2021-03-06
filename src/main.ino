#include "Keyboard.h"

int POWER = 10;
int STANDBY = 16;
int KEY_ACTIVATE = 2;
int ENTER = 3;
bool press = false;

void setup() {
  pinMode(KEY_ACTIVATE, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);
  pinMode(POWER, OUTPUT);
  pinMode(STANDBY, OUTPUT);
  Keyboard.begin();
  digitalWrite(POWER, HIGH);
}

void loop() {
  if(digitalRead(KEY_ACTIVATE) == LOW) {
    digitalWrite(STANDBY, LOW);
    if (digitalRead(ENTER) == LOW) {
      delay(10);
      if (digitalRead(ENTER) == LOW) {
        Keyboard.write(0x0a);
        delay(1000);
      }
    }
  }else{
    digitalWrite(STANDBY, LOW);
  }
}
