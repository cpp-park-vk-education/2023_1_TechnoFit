#ifndef HAR_SENSOR_H
#define HAR_SENSOR_H

#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"

class IGyroAccSensor{
  virtual String getMotion() = 0;
};

class MotionSensor : public IGyroAccSensor{
  private:
    MPU6050 mpu;
  public:
    MotionSensor(MPU6050 sensor);
    String getMotion() override;
};

#endif