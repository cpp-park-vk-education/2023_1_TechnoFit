#pragma once
#include "IServerUsecase.h"
#include "../Database/IRepository.h"


class ServerUsecase : public IServerUsecase
{
 public:
  std::string ProcessClientRequest(std::vector<unsigned char>& request) override;
  std::string ProcessDeviceRequest(std::vector<unsigned char>& request) override;
  std::vector<double> ProcessMLRequest(std::vector<unsigned char>& request) override;
  double ProcessPulseRequest(std::vector<unsigned char>& request) override;
  void setRepository(IRepository* repository)
  {
    repository_ = repository;
  }
 private:
  IRepository* repository_;
};