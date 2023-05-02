#include "RequestHandler.h"
#include "../global.h"
#include "DataHandlers.h"
#include "../Adapters/RequestAdapter.h"
#include "../Adapters/ResponseAdapter.h"
#include "../ClientAppRoot.h"
#include <QCoreApplication>
#include <iostream>

using namespace qtwebapp;

RequestHandler::RequestHandler(QObject *parent) : HttpRequestHandler(parent) 
{
	qDebug("RequestHandler: created");
}

RequestHandler::~RequestHandler() 
{
	qDebug("RequestHandler: deleted");
}

void RequestHandler::service(qtwebapp::HttpRequest &request, qtwebapp::HttpResponse &response) 
{
	QByteArray path = request.getPath();
	qDebug("RequestHandler: path=%s", path.data());


	// Тут должны быть условия при которых вызывается нужный хендлер исходя из параметров урла запроса 

	if (path.startsWith("/refresh")) {
		std::cout << " refreshing " << std::endl;
		ClientAppRoot root;
		root.cdh_->setUsecase(root.usecase_);
		root.usecase_->setRepository(root.repository_);
		root.repository_->setDatabaseDriver(root.databasedriver_);
		RequestAdapter req(&request);
		ResponseAdapter res(&response);
		root.cdh_->service(req, res);
	}

	if (path.startsWith("/arduino"))
	{
		// DeviceDataHandler ddh;
		// ddh.service(request, response);
	}

	if (path.startsWith("/ML"))
	{
		// ClientMLHandler mlh;
		// mlh.service(request,response);
	}

	qDebug("RequestHandler: finished request");

	// Clear the log buffer
	if (logger) {
		logger->clear();
	}
}
