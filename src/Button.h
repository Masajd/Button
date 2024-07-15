/*
  Button.h - Library for creating and controlling Buttons
  Created by Sam Dicker on 10.7.2024
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button{
  private:
    int Pin;
    int ButtonState;
    String Name;

    void initButton();
  public:
    Button();
    Button(int, String);

    void setPin(int);
    void setButtonState(int);

    int getPin();
    int getButtonState();
};

#endif