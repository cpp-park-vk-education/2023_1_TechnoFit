#include "MetricsNetwork.h"
#include "../RequestAdapter.h"
#include "../Headers/Device.h"
#include <random>

void MetricsNetwork::OnGetReply(IResponse& reply)
{
    // parse reply
    Device device;
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution_for_pulse(60, 150);
    std::uniform_int_distribution<> distribution_for_O2(80, 100);
    std::uniform_int_distribution<> distribution_for_temprature(35, 40);
    device.set_O2(distribution_for_O2(generator));
    device.set_pulse(distribution_for_pulse(generator));
    device.set_temprature(distribution_for_temprature(generator));
    device.set_name("arduino");
    replyHandler_->OnFetchStatistics(device);
}

void MetricsNetwork::FetchStatistics(int user_id) 
{
    RequestAdapter request;
    std::function<void(IResponse&)> lambda = [this](IResponse& reply){
        OnGetReply(reply);
    };
    //формируется реквест, делается гет запрос
    networkManager_->get(request, lambda);
}