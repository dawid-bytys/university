#include <algorithm>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

// Równoległe sortowanie znacznie przyspiesza operacje sortowania na dużych zbiorach danych.
int main() {
  std::vector<int> data(1'000'000);
  std::mt19937 rng;
  std::generate(data.begin(), data.end(), rng);

  std::sort(std::execution::par, data.begin(), data.end());

  return 0;
}
