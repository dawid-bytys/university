#include <concepts>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <typename T>
concept Container = std::ranges::range<T>;

template <typename T>
void process(const T& value) {
  std::cout << "Processing general type: " << value << std::endl;
}

template <Arithmetic T>
void process(const T& value) {
  std::cout << "Processing arithmetic value: " << value << std::endl;
}

template <Container T>
void process(const T& container) {
  std::cout << "Processing container with elements: ";

  for (const auto& element : container) {
    std::cout << element << " ";
  }

  std::cout << std::endl;
}

int main() {
  int number = 42;
  process(number);

  std::vector<int> vec = {1, 2, 3, 4, 5};
  process(vec);

  std::list<double> lst = {1.1, 2.2, 3.3};
  process(lst);

  std::string str = "Hello";
  process(str);

  return 0;
}
