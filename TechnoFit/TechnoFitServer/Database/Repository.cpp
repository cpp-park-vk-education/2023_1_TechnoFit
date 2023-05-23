#include "Repository.h"
#include <QtGlobal>
#include <string>
#include <vector>

std::string Repository::formClientQuery(std::vector<unsigned char>& id, std::vector<unsigned char>& type)
{
    // формирует селект запрос для получения данных, передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string id_(id.begin(), id.end());
    std::string type_(type.begin(), type.end());
    std::string query;
    if (std::stoi(type_) == 0)
        query = "Standard";
    if (std::stoi(type_) == 1)
        query = "Intensive";
    if (std::stoi(type_) == 2)
        query = "Premium";
     //here should be query with id that came with request
    return databasedriver_->get(query, std::stoi(id_));
}

std::string Repository::formDeviceQuery(std::vector<unsigned char>& request)
{
    // формирует селект запрос для сохранения данных с девайса, передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string query = "here should be query";
    return databasedriver_->get(query, 0);
}

std::string Repository::formMLQuery(std::vector<unsigned char>& request)
{
    // формирует селект запрос для ML части, передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string query = "here should be query";
    return databasedriver_->get(query, 0);
}
