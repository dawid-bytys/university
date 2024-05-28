#include <iostream>
#include <type_traits>

template<typename From, typename To>
class is_convertible {
  private:
    static char test(To) ;
    static int test(...);
    static From make_from();

  public:
    static constexpr bool value = sizeof(test(make_from())) == sizeof(char);
};

int main() {
    std::cout << "int -> double: " << is_convertible<int, double>::value << std::endl;
    std::cout << "int -> char: " << is_convertible<int, char>::value << std::endl;
    std::cout << "void* -> int: " << is_convertible<void*, int>::value << std::endl;

    return 0;
}
