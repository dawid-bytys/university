#include <iostream>
#include <memory>

int main() {
  int* raw_pointer;
  std::unique_ptr<int> unique_ptr;
  std::shared_ptr<int> shared_ptr;

  std::cout << "Rozmiar zwykłego wskaźnika: " << sizeof(raw_pointer) << " bajtów" << std::endl;
  std::cout << "Rozmiar std::unique_ptr: " << sizeof(unique_ptr) << " bajtów" << std::endl;
  std::cout << "Rozmiar std::shared_ptr: " << sizeof(shared_ptr) << " bajtów" << std::endl;

  return 0;
}
