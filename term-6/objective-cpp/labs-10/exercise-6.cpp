#include <iostream>
#include <memory>

class B;

class A {
 public:
  std::shared_ptr<B> ptr_b;

  ~A() {
    std::cout << "A destructor" << std::endl;
  }
};

class B {
 public:
  std::weak_ptr<A> ptr_a;

  ~B() {
    std::cout << "B destructor" << std::endl;
  }
};

int main() {
  {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->ptr_b = b;
    b->ptr_a = a;

    std::cout << "a use count: " << a.use_count() << std::endl;
    std::cout << "b use count: " << b.use_count() << std::endl;
  }

  std::cout << "End of main, destructors should be called" << std::endl;

  return 0;
}
