/*
  Button.cpp - Library for creating and controlling Buttons
  Created by Sam Dicker on 10.7.2024
*/

#include "Arduino.h"
#include "Button.h"

/** Default Button Constructor.
** Default Constructor that creates a Button on Pin 1. The button is unnamed.
**/
Button::Button(){
    Pin = 1;
    ButtonState = 0;
    Name = "Unnamed Button";
}

/** Button Constructor.
**  @param int Pin, Pin that the button is assigned to on the arduino.
**  @param String Name, Name of the button.
**/
Button::Button(int Pin, String Name){
    this->Pin = Pin;
    ButtonState = 0;
    this->Name = Name;

    initButton();
}

/** Initialise the button using the internal resistor.
**  Sets the pin to be input, and the pin output to be high.
**/
void Button::initButton(){
    pinMode(Pin,INPUT);
    digitalWrite(Pin,HIGH);
}

/** Set the assigned pin of the button on the arduino.
**  @param int Pin, The button pin on the arduino.
**/
void Button::setPin(int Pin){
    this->Pin = Pin;
}

/** Sets the button state of the button to either 1 or 0.
**  @param int ButtonState, the state of the button, either a 1 or a 0.
**/
void Button::setButtonState(int ButtonState){
    if(ButtonState == 1 || ButtonState == 0){
        this->ButtonState = ButtonState;
    }
    else{
        Serial.println("Invalid Button State");
    }
}

/** Gets the assigned pin of the button.
**  @return int Pin, the assigned pin of the button
**/
int Button::getPin(){
    return Pin;
}

/** Gets the button state of the button and the sets the button value of the button.
**  @return int val, the button state of the button, either a 1 or a 0.
**/
int Button::getButtonState(){
    int val = digitalRead(Pin);
    setButtonState(val);

    return val;
}