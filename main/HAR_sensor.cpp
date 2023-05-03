#include "HAR_sensor.h"

MotionSensor::MotionSensor(MPU6050 sensor){
  this->mpu = sensor;
  this->mpu.initialize();
}

String MotionSensor::getMotion(){
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  this->mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  String result = "";
  return result;
}