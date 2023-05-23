#include "DataHandlers.h"

#include <iostream>

void DeviceDataHandler::service(IRequest &request, IResponse &response)
{
    // получает данные в request`e из девайса
    // преобразует их в плюсовые структуры 

    // ....

    //  сохраняет их в бд
    // ....
    std::vector<unsigned char>& vc = request.GetBody();
    std::string reply_ = usecase_->ProcessDeviceRequest(vc);
    std::cout << reply_ << std::endl;
    response.flush();
}

void ClientDataHandler::service(IRequest &request, IResponse &response)
{
    auto id = request.getParameter("id");
    auto type = request.getParameter("type");
    std::string reply_ = usecase_->ProcessClientRequest(id, type);
    std::cout << reply_ << std::endl;
    std::vector<unsigned char> reply(reply_.begin(), reply_.end());
    for(auto i = reply.cbegin(); i != reply.cend(); i++)
    {
        std::cout << *i;
    }
    std::cout << std::endl;
    std::cout << "ready to write into response" << std::endl;
    response.write(reply);
    response.flush();
}

void ClientMLHandler::service(IRequest &request, IResponse &response)
{
    // получает запрос от клиента на прогнозирование данных 

    // вызывает функцию которая прогнозируется данные и отдаёт их

    // преобразует в json отправляет клиенту
}
