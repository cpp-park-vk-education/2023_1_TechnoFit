#ifndef INTERFACE_H
#define INTERFACE_H

#include <Arduino.h>
#include <ArduinoUniqueID.h>

#define LED_1_PIN 9

class IUserInterface{
  public:
    virtual String handleTrainerMessage() = 0;
    virtual String callTrainer() = 0;
};

class LedInterface : public IUserInterface{
  private:
    byte pin;
  public:
    LedInterface(byte pin);
    String handleTrainerMessage() override;
    String callTrainer() override;
    void init();
    void on();
    void off();
};

#endif