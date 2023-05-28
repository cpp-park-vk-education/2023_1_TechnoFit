#include <iostream>
#include <vector>
class Ml {
 public:
  explicit Ml(const std::vector<double> &ans);
  static std::vector<double> movingAverage(const std::vector<double> &x, int windowSize);
  double pulse_predict();
  double O2_predict();
  double temperarute_predict();
 private:
  std::vector<double> data;

};
