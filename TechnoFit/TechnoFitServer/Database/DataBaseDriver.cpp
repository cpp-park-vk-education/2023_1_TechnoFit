#include "DataBaseDriver.h"
#include <random>
#include <string>



void DataBaseDriver::connect() 
{

}
void DataBaseDriver::close() 
{

}
std::string DataBaseDriver::get(std::string query)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution_for_pulse(60, 150);
    std::uniform_int_distribution<> distribution_for_O2(80, 100);
    std::uniform_int_distribution<> distribution_for_temprature(35, 40);
    std::string pulse = std::to_string(distribution_for_pulse(generator));
    std::string O2 = std::to_string(distribution_for_O2(generator));
    std::string temprature = std::to_string(distribution_for_temprature(generator));
    std::string reply = pulse + " " + O2 + " " + temprature;
    return reply;
}
void DataBaseDriver::save()
{
    
}