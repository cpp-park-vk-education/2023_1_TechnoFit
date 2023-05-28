#pragma once
#include "../Headers/header.h"
#include <QString>

class IMetricsUseCase
{
public:
    virtual void RefreshData(int user_id, State state) = 0;
    virtual void createDevice(State type, QString name, int age, float weight) = 0;
    virtual void change_graph(int id, State type) = 0;
    virtual ~IMetricsUseCase()
    {

    }
};