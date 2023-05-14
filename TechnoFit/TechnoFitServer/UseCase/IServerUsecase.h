#pragma once
#include "../../IRequest.h"


class IServerUsecase
{
public:
    virtual std::string ProcessClientRequest(std::vector<unsigned char>& request) = 0;
    virtual std::string ProcessDeviceRequest(std::vector<unsigned char>& request) = 0;
    virtual std::string ProcessMLRequest(std::vector<unsigned char>& request) = 0;
};