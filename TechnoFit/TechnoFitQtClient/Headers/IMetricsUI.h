#pragma once
#include "Device.h"
#include "DeviceCard.h"
#include "header.h"

class IMetricsUI
{
public:
    virtual void UpdateResults(IDevice &result) = 0;
    virtual void createDevice(State state, QString name, int age, float weight) = 0;
    virtual void change_graph(int id, State state) = 0;
    virtual ~IMetricsUI()
    {

    }
};