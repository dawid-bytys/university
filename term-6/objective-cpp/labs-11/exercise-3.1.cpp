#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

// Szybko przetwarza dużą ilość danych, przekształcając każdy element.
int main() {
  std::vector<int> input(1'000'000);
  std::iota(input.begin(), input.end(), 0);
  std::vector<int> output(input.size());

  std::transform(std::execution::par, input.begin(), input.end(),
                 output.begin(), [](int x) { return x * x; });

  return 0;
}
