#pragma once
#include "IMetricsUseCase.h"
#include "../Headers/IMetricsUI.h"
#include "../Network/IMetricsNetwork.h"
#include "IMetricsNetworkHandler.h"
#include "../Headers/Device.h"
#include "../Headers/mainwindow.h"

#include <memory>
#include <thread>
#include <chrono>

class MetricsUseCase : public IMetricsUseCase, public IMetricsNetworkHandler
{
public:
    void SetUI(IMetricsUI* ui)
    {
        this->ui = ui;
       
    }
    void SetNetwork(IMetricsNetwork* network)
    {
        this->network_ = network;
    }
    ~MetricsUseCase() override
    {
        
    }
    void OnFetchStatistics(IDevice& device) override;
    void RefreshData(int user_id, State state) override;
    void createDevice(State state) override;
    void change_graph(int id, State type) override;
private:
    IMetricsUI* ui;
    IMetricsNetwork* network_;
    Dialog* dialog;
    QVector<DeviceCard*> devices;
};