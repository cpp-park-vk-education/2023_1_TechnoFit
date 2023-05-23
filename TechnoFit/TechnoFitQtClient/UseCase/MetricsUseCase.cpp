#include "MetricsUseCase.h"



void MetricsUseCase::RefreshData(int user_id, State state)
{
   network_->FetchStatistics(user_id, state);
}

void MetricsUseCase::OnFetchStatistics(IDevice& device)
{
   ui->UpdateResults(device);
}


void MetricsUseCase::createDevice(State state)
{
   ui->createDevice(state);
}

void MetricsUseCase::change_graph(int id, State type)
{
   ui->change_graph(id, type);
}