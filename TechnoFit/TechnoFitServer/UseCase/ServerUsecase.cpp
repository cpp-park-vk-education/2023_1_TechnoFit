#include "ServerUsecase.h"



std::string ServerUsecase::ProcessClientRequest(std::vector<unsigned char>& id, std::vector<unsigned char>& type) 
{
    // std::string reply = "ok";
    // return reply;
    return repository_->formClientQuery(id, type);
}

std::string ServerUsecase::ProcessMLRequest(std::vector<unsigned char>& request) 
{
    return repository_->formMLQuery(request);
}

std::string ServerUsecase::ProcessDeviceRequest(std::vector<unsigned char>& request) 
{
    return repository_->formDeviceQuery(request);
}



