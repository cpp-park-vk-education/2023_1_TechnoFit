#pragma once
#include "IRepository.h"
#include "IDataBaseDriver.h"


class Repository : public IRepository
{
 public:
  std::string formClientQuery(std::vector<unsigned char>& request) override;
  std::string formDeviceQuery(std::vector<unsigned char>& request) override;
  std::vector<double> formMLQuery(std::vector<unsigned char>& request) override;
  double formPulseQuery(std::vector<unsigned char>& request) override;

  void setDatabaseDriver(IDataBaseDriver* databasedriver)
  {
    databasedriver_ = databasedriver;
  }
 private:
  IDataBaseDriver* databasedriver_;
};