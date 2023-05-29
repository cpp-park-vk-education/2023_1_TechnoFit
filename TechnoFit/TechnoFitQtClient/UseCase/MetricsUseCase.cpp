#include "MetricsUseCase.h"



void MetricsUseCase::RefreshData(int user_id, State state)
{
   network_->FetchStatistics(user_id, state);
}

void MetricsUseCase::OnFetchStatistics(IDevice& device)
{
   ui->UpdateResults(device);
}


void MetricsUseCase::createDevice(State type, QString name, int age, float weight)
{
   ui->createDevice(type, name, age, weight);
}

void MetricsUseCase::change_graph(int id, State type)
{
   ui->change_graph(id, type);
}