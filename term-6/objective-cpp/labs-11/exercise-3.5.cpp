#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

// Równoległe zliczanie elementów spełniających warunek jest bardziej wydajne przy dużych zbiorach danych.
int main() {
  std::vector<int> data(1'000'000);
  std::iota(data.begin(), data.end(), 0);

  int count = std::count_if(std::execution::par, data.begin(), data.end(),
                            [](int x) { return x % 2 == 0; });

  std::cout << "Count of even numbers: " << count << std::endl;

  return 0;
}
