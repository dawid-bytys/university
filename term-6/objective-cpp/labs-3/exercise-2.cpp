#include <iostream>

template <typename T, typename S>
T convert(S value) {
  return static_cast<S>(value);
}

template <>
double convert(int value) {
  return static_cast<double>(value);
}

int main() {
  int int_value = 42;
  double double_value = 3.14;

  int converted_int = convert<int>(double_value);
  std::cout << "Converted int value: " << converted_int << std::endl;

  double converted_double = convert<double>(int_value);
  std::cout << "Converted double value: " << converted_double << std::endl;

  return 0;
}
