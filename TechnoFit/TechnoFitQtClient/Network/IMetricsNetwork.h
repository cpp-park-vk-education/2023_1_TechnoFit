#pragma once
#include "../../IResponse.h"
#include <functional>
class IMetricsNetwork
{
public:
    virtual void FetchStatistics(int user_id, int type) = 0;
    virtual void OnGetReply(IResponse& reply) = 0;
    virtual ~IMetricsNetwork() 
    {

    }
};