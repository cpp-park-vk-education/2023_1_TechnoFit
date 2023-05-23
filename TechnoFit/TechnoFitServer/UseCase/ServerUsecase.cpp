#include "ServerUsecase.h"



std::string ServerUsecase::ProcessClientRequest(std::vector<unsigned char>& request)
{
  return repository_->formClientQuery(request);
}

std::vector<double> ServerUsecase::ProcessMLRequest(std::vector<unsigned char>& request)
{
  return repository_->formMLQuery(request);
}

std::string ServerUsecase::ProcessDeviceRequest(std::vector<unsigned char>& request)
{
  return repository_->formDeviceQuery(request);
}