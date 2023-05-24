#include <cmath>
#include <vector>
#include "Ml.h"

Ml::Ml(const std::vector<double> &input) {
  for (double l: input) {
    data.push_back(l);
  }
}
std::vector<double> Ml::movingAverage(const std::vector<double> &x, int windowSize) {
  std::vector<double> predictions;
  for (int i = windowSize; i < x.size(); i++) {
    double sum = 0;
    for (int j = i - windowSize; j < i; j++) {
      sum += x[j];
    }
    double average = sum / windowSize;
    predictions.push_back(std::round(average * 10) / 10);
  }
  return predictions;
}

double Ml::pulse_predict() {
  std::vector<double> x;
  for (int i = 0; i < 15; i += 3) {
    x.push_back(data[i]);
  }
  std::vector<double> ans = movingAverage(x, 4);
  return ans[0];
}

double Ml::O2_predict() {
  std::vector<double> x;
  for (int i = 1; i < 15; i += 3) {
    x.push_back(data[i]);
  }
  std::vector<double> ans = movingAverage(x, 4);
  return ans[0];
}

double Ml::temperarute_predict() {
  std::vector<double> x;
  for (int i = 2; i < 15; i += 3) {
    x.push_back(data[i]);
  }
  std::vector<double> ans = movingAverage(x, 4);
  return ans[0];
}