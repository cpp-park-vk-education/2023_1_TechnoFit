#include "../Headers/Metrics.h"

Zone pulse_zone(int age, int resting_pulse, double current_pulse) {
  double max_pulse = 205.8 - (0.685 * age);
  Zone zone;
  if (current_pulse < (resting_pulse - max_pulse) * 0.4 + max_pulse)
  {
    zone = LightWeight;
  }
  else if ((resting_pulse - max_pulse) * 0.4 + max_pulse <= current_pulse && current_pulse < (resting_pulse - max_pulse) * 0.3 + max_pulse)
  {
    zone = Fatburning;
  }
  else if ((resting_pulse - max_pulse) * 0.3 + max_pulse <= current_pulse && current_pulse < (resting_pulse - max_pulse) * 0.2 + max_pulse)
  {
    zone = Airobe;
  }
  else if ((resting_pulse - max_pulse) * 0.2 + max_pulse <= current_pulse && current_pulse < (resting_pulse - max_pulse) * 0.1 + max_pulse)
  {
    zone = Anarob;
  }
  else if ((resting_pulse - max_pulse) * 0.1 + max_pulse <= current_pulse && current_pulse < (resting_pulse - max_pulse) * 0 + max_pulse)
  {
    zone = VO2;
  }
  else
  {
    zone = Maximum;
  }
  return zone;
}


double calories(double weight, double current_pulse, int age) {
  return 0.6309 * current_pulse + 0.1988 * weight + 0.2017 * age - 55.0969;
}
