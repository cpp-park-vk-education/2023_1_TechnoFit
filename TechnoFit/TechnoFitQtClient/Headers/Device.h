#pragma once
#include "Sensors.h"
#include "header.h"
#include <QString>
#include <vector>
#include <memory>
class IDevice
{
public:
    virtual int get_id() = 0;
    virtual float get_pulse() = 0;
    virtual float get_O2() = 0;
    virtual float get_temprature() = 0;
    virtual float get_ECG() = 0;
    virtual float get_BloodPressure() = 0;
    virtual QString get_name() = 0;
    virtual void set_name(QString name) = 0;
    virtual void set_pulse(float pulse) = 0;
    virtual void set_O2(float O2) = 0;
    virtual void set_temprature(float temprature) = 0;
    virtual void set_ECG(float ECG) = 0;
    virtual void set_BloodPressure(float BloodPressure) = 0;
    //virtual void add_sensor(ISensor* sensor) = 0;
    virtual State get_type() = 0;
    virtual void set_type(State state) = 0;
};


class Device : public IDevice
{
public:
    Device(int id) : id(id)
    {

    }
    int get_id() override
    {
        return id;
    }
    float get_O2() override
    {
        return O2;
    }
    float get_temprature() override
    {
        return temprature;
    }
    float get_pulse() override
    {
        return pulse;
    }
    float get_BloodPressure() override
    {
        return BloodPressure;
    }
    float get_ECG() override
    {
        return ECG;
    }
    State get_type() override
    {
        return type;
    }
    void set_type(State state) override
    {
        type = state;
    }
    QString get_name() override
    {
        return name;
    }
    void set_name(QString _name) override
    {
        name = _name;
    }
    void set_pulse(float _pulse) override
    {
        pulse = _pulse;
    }
    void set_O2(float _O2) override
    {
        O2 = _O2; 
    }
    void set_temprature(float _temprature) override
    {
        temprature = _temprature;
    }
    void set_ECG(float _ECG) override
    {
        ECG = _ECG;
    }
    void set_BloodPressure(float _BloodPressure) override
    {
        BloodPressure = _BloodPressure;
    }
    // void add_sensor(ISensor* sensor) override
    // {
    //     params.push_back(sensor);
    // }
private:
    //std::vector<ISensor*> params;
    float pulse;
    float O2;
    float temprature;
    float ECG;
    float BloodPressure;
    QString name;
    int id;
    State type;
};
