#include "Repository.h"


std::string Repository::formClientQuery(std::vector<unsigned char>& request)
{
    // формирует селект запрос для получения данных, передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string query = "here should be query";
    return databasedriver_->get(query);
}

std::string Repository::formDeviceQuery(std::vector<unsigned char>& request)
{
    // формирует селект запрос для сохранения данных с девайса, передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string query = "here should be query";
    return databasedriver_->get(query);
}

std::string Repository::formMLQuery(std::vector<unsigned char>& request)
{
    // формирует селект запрос для ML части, передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string query = "here should be query";
    return databasedriver_->get(query);
}
