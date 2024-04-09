#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
struct has_value_type {
  private:
    template <typename U>
    static std::true_type test(typename U::value_type*);

    template <typename U>
    static std::false_type test(...);

  public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

int main() {
    std::cout << "std::vector<int>: " << has_value_type<std::vector<int>>::value << std::endl;
    std::cout << "int: " << has_value_type<int>::value << std::endl;

    return 0;
}
