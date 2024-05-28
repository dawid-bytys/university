#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

// Pozwala na równoległe wykonanie funkcji na każdym elemencie kolekcji.
int main() {
  std::vector<int> data(1'000'000);
  std::iota(data.begin(), data.end(), 0);

  std::for_each(std::execution::par, data.begin(), data.end(),
                [](int& x) { x = x * x; });

  return 0;
}
