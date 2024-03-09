#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class sequence_gen {
 private:
  int current_value;

 public:
  sequence_gen() : current_value(1) {}

  int operator()() {
    int value = current_value;
    current_value += 2;
    return value;
  }
};

int main() {
  sequence_gen seq_gen;
  std::vector<int> odd_integers(20);
  std::generate_n(odd_integers.begin(), 20, seq_gen);

  std::cout << "Generated Sequence of First 20 Odd Integers: ";
  for (const int& num : odd_integers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  auto greater_than_4 = std::bind(std::greater<int>(), 4);
  auto result =
      std::find_if(odd_integers.begin(), odd_integers.end(), greater_than_4);

  if (result != odd_integers.end()) {
    std::cout << "Element greater than 4 found: " << *result << std::endl;
  } else {
    std::cout << "No element greater than 4 found." << std::endl;
  }

  return 0;
}
