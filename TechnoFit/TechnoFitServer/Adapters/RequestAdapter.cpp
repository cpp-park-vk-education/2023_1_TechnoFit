#include "RequestAdapter.h"


void RequestAdapter::SetHeader(std::string header)
{
    return;
}

void RequestAdapter::SetUrl(std::string url)
{
    return;
}

void RequestAdapter::SetBody(std::vector<unsigned char>& body)
{
    return;
}

std::vector<unsigned char>& RequestAdapter::GetBody()
{
    std::vector<unsigned char> vc;
    return vc;
}

std::vector<unsigned char> RequestAdapter::getParameter(const std::string& name)
{
    QByteArray qdata;
    QByteArray bytename(name.c_str(), name.length());
    qdata = request_->getParameter(bytename);
    const unsigned char* begin = reinterpret_cast<unsigned char*>(qdata.data());
    const unsigned char* end = begin + qdata.length();
    std::vector<unsigned char> params( begin, end );  
    for(auto i = params.cbegin(); i != params.cend(); i++)
    {
        qInfo() << *i;
    }
    qInfo() << qdata;
    return params;
}

std::string RequestAdapter::GetUrl()
{
    return "OK";
}

std::string RequestAdapter::GetHeader()
{
    return "OK";
}