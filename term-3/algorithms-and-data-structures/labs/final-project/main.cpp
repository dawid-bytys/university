#include "Poly.hpp"

int main() {
  double coeffs_p[3] = {1, 2, 3};
  Poly<double> p(coeffs_p, 2);

  double coeffs_q[3] = {3, 2, 1};
  Poly<double> q(coeffs_q, 2);

  Poly<double> r = p * q;
  r.print();  // -2x^2 + 2

  return 0;
}