#include "NetworkManager.h"
#include "../ResponseAdapter.h"
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QByteArray>
#include <QNetworkRequest>
#include <vector>
#include <iostream>


void NetworkManager::post(IRequest& request, std::vector<unsigned char>& body, std::function<void(IResponse&)> const& OnGetReply)
{
    QNetworkRequest Qrequest;
    Qrequest.setUrl(QUrl(QString::fromStdString(request.GetUrl())));
    QByteArray data;
    std::copy(body.begin(), body.end(), std::back_inserter(data));
    QNetworkReply *reply = networkmanager->post(Qrequest, data);
    QObject::connect(reply, &QNetworkReply::finished, [reply, OnGetReply]()
    {
        ResponseAdapter response;
        response.SetReply(reply);
        OnGetReply(response);
    }); 
}    

void NetworkManager::get(IRequest& request, std::function<void(IResponse&)> const& OnGetReply)
{
    QNetworkRequest Qrequest;
    Qrequest.setUrl(QUrl(QString::fromStdString(request.GetUrl())));
    QNetworkReply *reply = networkmanager->get(Qrequest);
    QObject::connect(reply, &QNetworkReply::finished, [reply, OnGetReply]()
    {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qInfo() << statusCode ;
        ResponseAdapter response;
        response.SetReply(reply);
        OnGetReply(response);
    });
}