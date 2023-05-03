#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>

#include <Adafruit_MLX90614.h>
#include <MAX30100.h>
#include <MAX30100_BeatDetector.h>
#include <MAX30100_Filters.h>
#include <MAX30100_PulseOximeter.h>
#include <MAX30100_Registers.h>
#include <MAX30100_SpO2Calculator.h>
#include <Wire.h>

class ISensor{
  virtual float getValue() = 0;
};

class PulseSensor : public ISensor{
  private:
    PulseOximeter pulse;
  public:
    PulseSensor();
    float getValue() override;
};

class OxygenSensor : public ISensor{
  private:
    PulseOximeter oxygen;
  public:
    OxygenSensor();
    float getValue() override;
};

class TemperatureSensor : public ISensor{
  private:
    Adafruit_MLX90614 temperature;
  public:
    TemperatureSensor(Adafruit_MLX90614 sensor);
    float getValue() override;
};

#endif