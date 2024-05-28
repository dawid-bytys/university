#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> data(1000);
  std::iota(data.begin(), data.end(),
            1);

  std::for_each(std::execution::par_unseq, data.begin(), data.end(),
                [](int& x) {
                  x *= 2;
                });

  for (const auto& elem : data) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}
