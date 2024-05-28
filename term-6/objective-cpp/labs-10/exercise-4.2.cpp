#include <iostream>
#include <memory>

int main() {
  std::size_t size = 5;
  auto ptr = std::make_unique<int[]>(size);

  for (std::size_t i = 0; i < size; ++i) {
    ptr[i] = static_cast<int>(i);
    std::cout << "Element " << i << ": " << ptr[i] << std::endl;
  }

  return 0;
}
