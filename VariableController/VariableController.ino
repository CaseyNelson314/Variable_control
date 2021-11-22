#include "VariableController.h"
VariableController sw(4);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(sw.GetToggleSw());
}
