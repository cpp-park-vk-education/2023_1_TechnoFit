#include "RequestAdapter.h"
#include <QString>
#include <QUrl>
#include <QUrlQuery>

void RequestAdapter::SetHeader(std::string header)
{

}

void RequestAdapter::SetUrl(std::string url_, int id, int type)
{
    QUrl url(QString::fromStdString(url_));
    QUrlQuery query;
    query.addQueryItem("id", QString::number(id));
    query.addQueryItem("type", QString::number(type));
    url.setQuery(query.query());
    request.setUrl(url);
}

void RequestAdapter::SetUrl(std::string url_)
{
    QUrl url(QString::fromStdString(url_));
    request.setUrl(url);
}


void RequestAdapter::SetBody(std::vector<unsigned char>& body)
{
    data = body;
}

std::vector<unsigned char>& RequestAdapter::GetBody()
{
    return data;
}

std::vector<unsigned char> RequestAdapter::getParameter(const std::string& name)
{
    return data;
}

std::string RequestAdapter::GetUrl()
{
    QString qs = request.url().toString();
    return qs.toStdString();
}

std::string RequestAdapter::GetHeader()
{
    return "Hello";
}

QNetworkRequest RequestAdapter::GetQtRequest()
{
    return request;
}