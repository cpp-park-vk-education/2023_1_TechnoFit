#include "DataBaseDriver.h"




void DataBaseDriver::connect() 
{

}
void DataBaseDriver::close() 
{

}
std::string DataBaseDriver::get(std::string query)
{
    // получает запрос как входной параметр делает запрос отдаёт репозиторию результат
    std::string reply = "32 45 12";
    return reply;
}

std::vector<double> DataBaseDriver::get_n(std::string query){
  std::string filename = "/home/dzhavid/untitled3/data.txt";
  std::vector<double> data;

  std::ifstream inputFile(filename);

  if (inputFile.is_open()) {
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(inputFile, line)) {
      lines.push_back(line);
      if (lines.size() > 5) {
        lines.erase(lines.begin());
      }
    }


    for (const std::string &line: lines) {
      std::istringstream iss(line);
      double pulse, O2, temperature;
      if (iss >> pulse >> O2 >> temperature) {
        data.push_back(pulse);
        data.push_back(O2);
        data.push_back(temperature);
      }
    }

    inputFile.close();
  }

  return data;
}

void DataBaseDriver::save()
{
    
}