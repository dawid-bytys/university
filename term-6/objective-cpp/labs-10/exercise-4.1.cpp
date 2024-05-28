#include <iostream>
#include <memory>

class MyClass {
 public:
  MyClass(int x, double y) {
    std::cout << "MyClass constructor: " << x << ", " << y << std::endl;
  }
  
  ~MyClass() {
    std::cout << "MyClass destructor" << std::endl;
  }
};

int main() {
  auto ptr = std::make_unique<MyClass>(42, 3.14);
  return 0;
}