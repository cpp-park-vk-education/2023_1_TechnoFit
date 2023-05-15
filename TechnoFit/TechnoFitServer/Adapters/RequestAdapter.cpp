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

std::string RequestAdapter::GetUrl()
{
    return "OK";
}

std::string RequestAdapter::GetHeader()
{
    return "OK";
}