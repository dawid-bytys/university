#include <cstdlib>
#include <iostream>

template <typename T>
T maximum(const T &first_value, const T &second_value) {
  if (first_value < second_value) {
    return second_value;
  }

  return first_value;
};

int main() {
  for (int i = 0; i < 10; ++i) {
    int first_value = rand() % 100;
    int second_value = rand() % 100;
    int max_value = maximum(first_value, second_value);

    std::cout << "Maximum value between " << first_value << " and "
              << second_value << " is " << max_value << "\n";
  }

  return 0;
}