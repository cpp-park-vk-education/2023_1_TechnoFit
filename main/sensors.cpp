#include "sensors.h"

PulseSensor::PulseSensor(){
  this->pulse.begin();
}

float PulseSensor::getValue(){
  return this->pulse.getSpO2();
}

OxygenSensor::OxygenSensor(){
  this->oxygen.begin();
}

float OxygenSensor::getValue(){
  return this->oxygen.getHeartRate();
}

TemperatureSensor::TemperatureSensor(Adafruit_MLX90614 sensor){
  this->temperature = Adafruit_MLX90614();
}

float TemperatureSensor::getValue(){
  return this->temperature.readObjectTempC();
}


