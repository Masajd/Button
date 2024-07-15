#include <Button.h>

Button button(2, "Example LED");

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.println(button.getButtonState());
}
