#include <vector>
#include <iostream>

template <typename T1, typename T2>
struct Promote {
  using type = std::conditional_t<(sizeof(T1) >= sizeof(T2)), T1, T2>;
};

template <typename T>
struct Promote<T, T> {
  using type = T;
};

#define MK_PROMOTE(T1, T2, Tr) \
  template <>                \
  struct Promote<T1, T2> {   \
      using type = Tr;       \
}

template <typename T, typename U>
std::vector<typename Promote<T, U>::type> operator+(const std::vector<T>& a, const std::vector<U>& b) {
  std::vector<typename Promote<T, U>::type> result;
  const size_t size = std::min(a.size(), b.size());
  result.reserve(size);

  for (size_t i = 0; i < size; ++i) {
      result.push_back(static_cast<typename Promote<T, U>::type>(a[i]) + static_cast<typename Promote<T, U>::type>(b[i]));
  }

  return result;
}

int main() {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<double> vec2 = {2.5, 3.5, 4.5};

  auto sum = vec1 + vec2;

  for (const auto& val : sum) {
      std::cout << val << " ";
  }

  std::cout << std::endl;

  return 0;
}
