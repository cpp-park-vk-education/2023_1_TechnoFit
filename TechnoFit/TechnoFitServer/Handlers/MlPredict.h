#include <iostream>
#include <vector>
class MlPredict{
 public:
  explicit MlPredict(const std::vector<double>&ans);
  static std::vector<double> movingAverage(const std::vector<double>& x, int windowSize);
  double pulse_predict();
  double O2_predict();
  double temperarute_predict();
 private:
  std::vector<double> data;

};