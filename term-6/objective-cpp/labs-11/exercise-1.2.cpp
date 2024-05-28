#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> data(1000);
  std::iota(data.begin(), data.end(),
            1);

  int sum = std::reduce(std::execution::par, data.begin(), data.end());

  std::cout << "Sum: " << sum << std::endl;

  return 0;
}
