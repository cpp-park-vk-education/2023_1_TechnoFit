#pragma once
#include "../../IRequest.h"
#include <string>

class IRepository
{
public:
    virtual std::string formClientQuery(std::vector<unsigned char>& request) = 0;
    virtual std::string formDeviceQuery(std::vector<unsigned char>& request) = 0;
    virtual std::string formMLQuery(std::vector<unsigned char>& request) = 0;
};