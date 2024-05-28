#include <concepts>
#include <iostream>
#include <vector>

template <typename T>
class MyVector {
 public:
  void push_back(const T& value)
    requires std::copyable<T>
  {
    data.push_back(value);
  }

  void display() const {
    for (const auto& item : data) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }

 private:
  std::vector<T> data;
};

class NonCopyable {
 public:
  NonCopyable(int v) : value(v) {}

  NonCopyable(const NonCopyable&) = delete;
  NonCopyable& operator=(const NonCopyable&) = delete;

  NonCopyable(NonCopyable&&) = default;
  NonCopyable& operator=(NonCopyable&&) = default;

  int get_value() const { return value; }

 private:
  int value;
};

std::ostream& operator<<(std::ostream& os, const NonCopyable& obj) {
  os << obj.get_value();
  return os;
}

int main() {
  MyVector<int> int_vector;
  int_vector.push_back(1);
  int_vector.push_back(2);
  int_vector.push_back(3);
  int_vector.display();

  NonCopyable nc1(10);
  NonCopyable nc2(20);

  MyVector<NonCopyable> non_copyable_vector;

  return 0;
}
