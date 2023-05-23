#pragma once
#include "../../IRequest.h"
#include "httprequest.h"
#include <vector>




class RequestAdapter : public IRequest
{
public:
    RequestAdapter(qtwebapp::HttpRequest* request)
    {
        request_ = request;
    }
    void SetHeader(std::string header) override;
    void SetUrl(std::string url) override;
    void SetBody(std::vector<unsigned char>& body) override;
    std::vector<unsigned char>& GetBody() override;
    std::string GetUrl() override;
    std::string GetHeader() override;
    std::vector<unsigned char> getParameter(const std::string& name) override;
private:
    qtwebapp::HttpRequest* request_;
};
