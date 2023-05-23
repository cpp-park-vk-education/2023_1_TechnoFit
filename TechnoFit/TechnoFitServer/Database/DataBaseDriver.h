#pragma once
#include "IDataBaseDriver.h"
#include "IRepository.h"


class DataBaseDriver : public IDataBaseDriver
{
public:
    DataBaseDriver()
    {
       
    }
    void connect() override;
    void close() override;
    std::vector<double> get_n(std::string query) override;
    std::string get(std::string query) override;
    void save() override;
private:
};