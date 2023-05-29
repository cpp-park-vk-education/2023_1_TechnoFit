#pragma once
#include "../Headers/Device.h"

class IMetricsNetworkHandler
{
public:
    virtual void OnFetchStatistics(IDevice& device) = 0;
};