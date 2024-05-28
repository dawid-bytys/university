#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
T max(T a, T b) {
  return a > b ? a : b;
}

template <typename T>
T* max(T* a, T* b) {
  return *a > *b ? a : b;
}

template <typename T>
T* max(T* data, size_t n) {
  T* max_ptr = data;

  for (size_t i = 1; i < n; ++i) {
    if (data[i] > *max_ptr) {
      max_ptr = &data[i];
    }
  }

  return max_ptr;
}

template <>
const char* max<const char*>(const char* a, const char* b) {
  return strcmp(a, b) > 0 ? a : b;
}

template <>
char* max<char*>(char* a, char* b) {
  return strcmp(a, b) > 0 ? a : b;
}

template <typename T>
const T* max(T* a, const T* b) {
  return *a > *b ? a : b;
}

int main() {
  int int_a = 5;
  int int_b = 10;
  double double_a = 3.5;
  double double_B = 7.8;
  char char_a = 'a';
  char char_b = 'z';
  const char* str_a = "hello";
  const char* str_b = "world";

  int max_int = max(int_a, int_b);
  double max_double = max(double_a, double_B);
  char max_char = max(char_a, char_b);
  const char* max_str = max(str_a, str_b);

  std::cout << "Max int: " << max_int << std::endl;
  std::cout << "Max double: " << max_double << std::endl;
  std::cout << "Max char: " << max_char << std::endl;
  std::cout << "Max string: " << max_str << std::endl;

  return 0;
}
