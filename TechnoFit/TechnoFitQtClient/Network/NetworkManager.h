#pragma once
#include "INetworkManager.h"
#include "../../IRequest.h"
#include "../../IResponse.h"
#include <QNetworkAccessManager>
#include "IMetricsNetwork.h"


class NetworkManager : public INetworkManager
{
public:
    NetworkManager()
    {
        
    }
    ~NetworkManager() override
    {
        
    }
    void setQNetworkAccessManager(QNetworkAccessManager* networkmanager_)
    {
        networkmanager = networkmanager_;
    }
    void setMetricsNetwork(IMetricsNetwork* network)
    {
        network_ = network;
    }
    void post(IRequest& request, std::vector<unsigned char>& body, std::function<void(IResponse&)> const& OnGetReply) override;    
    void get(IRequest& request, std::function<void(IResponse&)> const& OnGetReply) override;
private:
    QNetworkAccessManager* networkmanager;
    IMetricsNetwork* network_;
};