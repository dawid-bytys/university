#include <iostream>

template<size_t N, typename T>
constexpr T dot_product(const T* x, const T* y, size_t index = 0) {
  if (index < N) {
    return x[index] * y[index] + dot_product<N, T>(x, y, index + 1);
  }

  return T(0);
}

int main() {
    constexpr int vec1i[3] = {1, 2, 3};
    constexpr int vec2i[3] = {4, 5, 6};

    constexpr double vec1d[3] = {1.0, 2.0, 3.0};
    constexpr double vec2d[3] = {4.0, 5.0, 6.0};

    constexpr int resulti = dot_product<3, int>(vec1i, vec2i);
    std::cout << "Iloczyn skalarny (int) = " << resulti << std::endl;

    constexpr double resultd = dot_product<3, double>(vec1d, vec2d);
    std::cout << "Iloczyn skalarny (double) = " << resultd << std::endl;

    return 0;
}
