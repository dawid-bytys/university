#include <math.h>
#include <stdio.h>

void count_roots(double a, double b, double c, double delta);
void check_factors(double a, double b, double c, double delta);

int main() {
  double a, b, c, delta;
  int input;

  printf("Wprowadź współczynniki a, b, c po spacji: ");
  input = scanf("%lf %lf %lf", &a, &b, &c);

  if (input != 3) {
    printf("\nWprowadziłeś błędne dane.");
    return 1;
  }

  delta = pow(b, 2) - 4 * a * c;

  if (delta < 0) {
    printf("\nFunkcja nie ma pierwiastków.");
    return 0;
  }

  check_factors(a, b, c, delta);

  return 0;
}

void count_roots(double a, double b, double c, double delta) {
  if (delta == 0) {
    double x = (b * -1) / 2 * a;

    printf("\nFunkcja ma jeden pierwiastek: %0.2lf", x);
  } else {
    double x1, x2;
    b = -1 * b;

    x1 = (b + sqrt(delta)) / 2 * a;
    x2 = (b - sqrt(delta)) / 2 * a;

    printf("\nFunkcja ma dwa pierwiastki: %0.2lf i %0.2lf", x1, x2);
  }
}

void check_factors(double a, double b, double c, double delta) {
  if (a == 0 && b == 0) {
    printf("\nFunkcja nie ma pierwiastków.");
  } else if (a == 0 || (b == 0 && c == 0)) {
    printf("\nFunkcja ma jeden pierwiastek: %d", 0);
  } else {
    count_roots(a, b, c, delta);
  }
}
