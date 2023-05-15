#include "MetricsNetwork.h"
#include "../RequestAdapter.h"
#include "../Headers/Device.h"
#include <random>
#include <sstream>
#include <iostream>

void MetricsNetwork::OnGetReply(IResponse& reply)
{
    std::vector<unsigned char> vc = reply.GetBody();
    std::string str(vc.begin(),vc.end());
    std::cout << str << std::endl;
    std::stringstream iss(str);
    Device device;
    float a;
    device.set_name("arduino");
    iss >> a;
    device.set_pulse(a);
    iss >> a;
    device.set_O2(a);
    iss >> a;
    device.set_temprature(a);
    replyHandler_->OnFetchStatistics(device);
}

void MetricsNetwork::FetchStatistics(int user_id) 
{
    RequestAdapter request;
    std::string url = "http://localhost:8080/refresh";
    request.SetUrl(url);
    std::function<void(IResponse&)> lambda = [this](IResponse& reply){
        OnGetReply(reply);
    };
    networkManager_->get(request, lambda);
}