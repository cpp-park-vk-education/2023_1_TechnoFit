#include "../Headers/mainwindow.h"
#include <QApplication>
#include "../Network/MetricsNetwork.h"
#include "../UseCase/MetricsUseCase.h"
#include <memory>
#include "../UseCase/IMetricsUseCase.h"
#include "../AppRoot.h"
#include <QNetworkAccessManager>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow mw_;
    AppRoot root(&mw_);
    root.usecase_->SetUI(&mw_);
    root.usecase_->SetNetwork(root.network_);
    root.network_->setReplyHandler(root.usecase_);
    root.network_->setNetworkManager(root.networkManager_);
    root.networkManager_->setMetricsNetwork(root.network_);
    root.networkManager_->setQNetworkAccessManager(root.qnetworkmanager);
    mw_.setUseCase(root.usecase_);
    mw_.show();
    mw_.RefreshGUIdata();
    return a.exec();
}