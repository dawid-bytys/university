#include <iostream>

template <typename To, typename From>
To convert(const From &value) {
  return static_cast<To>(value);
}

int main() {
  int int_value = 42;
  double double_value = convert<double>(int_value);
  std::cout << "Converted int to double: " << double_value << std::endl;

  float float_value = 3.14;
  int int_value_converted = convert<int>(float_value);
  std::cout << "Converted float to int: " << int_value_converted << std::endl;

  char char_value = 'A';
  int int_value_char = convert<int>(char_value);
  std::cout << "Converted char to int: " << int_value_char << std::endl;

  return 0;
}
