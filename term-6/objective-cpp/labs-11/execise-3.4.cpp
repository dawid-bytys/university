#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

// Równoległe kopiowanie elementów spełniających warunek przyspiesza operacje filtrowania.
int main() {
  std::vector<int> input(1'000'000);
  std::iota(input.begin(), input.end(), 0);
  std::vector<int> output;

  std::copy_if(std::execution::par, input.begin(), input.end(),
               std::back_inserter(output), [](int x) { return x % 2 == 0; });

  return 0;
}
