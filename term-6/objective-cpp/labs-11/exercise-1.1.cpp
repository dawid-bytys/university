#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};

  std::sort(std::execution::seq, data.begin(), data.end());

  for (const auto& elem : data) {
    std::cout << elem << " ";
  }
  
  std::cout << std::endl;

  return 0;
}
