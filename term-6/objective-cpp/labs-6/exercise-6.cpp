#include <iostream>

template <typename... Types>
constexpr std::size_t type_list_length() {
  return sizeof...(Types);
}

template <std::size_t Index, typename... Types>
struct type_at_index;

template <std::size_t Index, typename First, typename... Rest>
struct type_at_index<Index, First, Rest...> {
  using type = typename type_at_index<Index - 1, Rest...>::type;
};

template <typename First, typename... Rest>
struct type_at_index<0, First, Rest...> {
  using type = First;
};

template <typename T, typename... Types>
constexpr bool is_type_in_list() {
  return (std::is_same_v<T, Types> || ...);
}

int main() {
  std::cout << "type_list_length<int, double, char, float, long>: " << type_list_length<int, double, char, float, long>() << std::endl; 
  std::cout << "type_list_length<int, double, char>: " << type_list_length<int, double, char>() << std::endl;

  std::cout << "type_at_index<0, int, double, char>::type: " << std::is_same<type_at_index<0, int, double, char>::type, double>::value << std::endl;
  std::cout << "type_at_index<1, int, double, char>::type: " << std::is_same<type_at_index<1, int, double, char>::type, double>::value << std::endl;

  std::cout << "is_type_in_list<int, double, char>: " << is_type_in_list<int, double, char>() << std::endl;
  std::cout << "is_type_in_list<int, double, char, int>: " << is_type_in_list<int, double, char, int>() << std::endl;
}