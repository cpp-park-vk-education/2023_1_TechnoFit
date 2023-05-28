#include "MetricsNetwork.h"
#include "../RequestAdapter.h"
#include "../Headers/Device.h"
#include "../Headers/Sensors.h"
#include <random>
#include <sstream>
#include <iostream>

void MetricsNetwork::OnGetReply(IResponse& reply)
{
    std::vector<unsigned char> vc = reply.GetBody();
    std::string str(vc.begin(),vc.end());
    std::stringstream iss(str);
    float a;
    iss >> a;
    Device device(a);
    device.set_name(QString::number(a));
    iss >> a;
    if(a == 0)
        device.set_type(Standard);
    if(a == 1)
        device.set_type(Intensive);
    if(a == 2)
        device.set_type(Premium);
    switch(static_cast<int>(a))
    {
    case 0:
        iss >> a;
        device.set_pulse(a);
        iss >> a;
        device.set_O2(a);
        iss >> a;
        device.set_temprature(a);
        break;
    case 1:
        iss >> a;
        device.set_temprature(a);
        iss >> a;
        device.set_ECG(a);
        break;
    case 2:
        iss >> a;
        device.set_pulse(a);
        iss >> a;
        device.set_O2(a);
        iss >> a;
        device.set_temprature(a);
        iss >> a;
        device.set_ECG(a);
        iss >> a;
        device.set_BloodPressure(a);
        break;
    }
    replyHandler_->OnFetchStatistics(device);
}

void MetricsNetwork::FetchStatistics(int user_id, int type) 
{
    RequestAdapter request;
    std::string url = "http://localhost:8080/refresh";
    request.SetUrl(url, user_id, type); 
    std::function<void(IResponse&)> lambda = [this](IResponse& reply){
        OnGetReply(reply);
    };
    networkManager_->get(request, lambda);
}