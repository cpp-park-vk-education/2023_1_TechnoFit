#include "Metrics.h"
std::string Metrics::pulse_zone(int age, int min_pulse, double current_pulse) {
  double max_pulse = 205.8 - (0.685 * age);
  if ((min_pulse - max_pulse) * 0.5 + max_pulse <= current_pulse && current_pulse < (min_pulse - max_pulse) * 0.4 + max_pulse){
    return "50% - 60%\nзона легкой активности";
  }

  if ((min_pulse - max_pulse) * 0.4 + max_pulse <= current_pulse && current_pulse < (min_pulse - max_pulse) * 0.3+ max_pulse){
    return "60% - 70%\nначало жиросжигающей зоны";
  }

  if ((min_pulse - max_pulse) * 0.3 + max_pulse <= current_pulse && current_pulse < (min_pulse - max_pulse) * 0.2 + max_pulse){
    return "70% - 80%\nаэробная зона";
  }

  if ((min_pulse - max_pulse) * 0.2 + max_pulse <= current_pulse && current_pulse < (min_pulse - max_pulse) * 0.1 + max_pulse){
    return "80% - 90%\nанаэробная зона";
  }

  if ((min_pulse - max_pulse) * 0.1 + max_pulse <= current_pulse && current_pulse < (min_pulse - max_pulse) * 0 + max_pulse){
    return "90% - 100%\nзона VO2";
  }

  return "Состояние покоя";
}
double Metrics::col(double weight, double pulse, int age) {
  return 0.6309 * pulse + 0.1988 * weight + 0.2017 * age - 55.0969;
}
