#include "DataBaseDriver.h"
#include <random>
#include <string>



void DataBaseDriver::connect() 
{

}
void DataBaseDriver::close() 
{

}
std::string DataBaseDriver::get(std::string query, int id)
{
    std::string reply;
    if(query == "Premium") // заменяем здесь на айди конкретного девайса
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution_for_pulse(60, 150);
        std::uniform_int_distribution<> distribution_for_O2(80, 100);
        std::uniform_int_distribution<> distribution_for_temprature(35, 40);
        std::uniform_int_distribution<> distribution_for_ECG(0, 40);
        std::uniform_int_distribution<> distribution_for_BloodPressure(150, 200);
        std::string pulse = std::to_string(distribution_for_pulse(generator));
        std::string O2 = std::to_string(distribution_for_O2(generator));
        std::string temprature = std::to_string(distribution_for_temprature(generator));
        std::string ECG = std::to_string(distribution_for_ECG(generator));
        std::string BloodPressure = std::to_string(distribution_for_BloodPressure(generator));
        reply = std::to_string(id) + " " + "2" +  " " + pulse + " " + O2 + " " + temprature + " " + ECG + " " + BloodPressure;
    }
    if(query == "Standard") // заменяем здесь на айди конкретного девайса
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution_for_pulse(60, 150);
        std::uniform_int_distribution<> distribution_for_O2(80, 100);
        std::uniform_int_distribution<> distribution_for_temprature(35, 40);
        std::string pulse = std::to_string(distribution_for_pulse(generator));
        std::string O2 = std::to_string(distribution_for_O2(generator));
        std::string temprature = std::to_string(distribution_for_temprature(generator));
        reply = std::to_string(id) + " " + "0" + " " + pulse + " " + O2 + " " + temprature;
    }
    if(query == "Intensive") // заменяем здесь на айди конкретного девайса
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution_for_temprature(35, 40);
        std::uniform_int_distribution<> distribution_for_ECG(0, 40);
        std::string temprature = std::to_string(distribution_for_temprature(generator));
        std::string ECG = std::to_string(distribution_for_ECG(generator));
        reply = std::to_string(id) + " " + "1" + " " + temprature + " " + ECG;
    }
    return reply;
}
void DataBaseDriver::save()
{
    
}