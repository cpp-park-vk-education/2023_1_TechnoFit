#include <iostream>
#include <string>
class Metrics {
 public:
  std::string pulse_zone(int age, int min_pulse, double current_pulse);
  double col(double weight, double pulse, int age);
};
