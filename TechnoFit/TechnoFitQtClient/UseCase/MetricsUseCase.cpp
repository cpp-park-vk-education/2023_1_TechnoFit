#include "MetricsUseCase.h"



void MetricsUseCase::RefreshData(int user_id)
{
   network_->FetchStatistics(user_id);
   // while(true)
   // {
   //    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   //    network_->FetchStatistics(user_id);
   // }
}

void MetricsUseCase::OnFetchStatistics(Device& device)
{
   ui->UpdateResults(device);
}

void MetricsUseCase::ThreadRefresher(int user_id)
{
   auto lambda = [this](int user_id){
        RefreshData(user_id);
   };
   std::thread th(lambda, user_id);
   th.join();
}