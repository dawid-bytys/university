#include <math.h>
#include <stdio.h>

double function(double num);

int main() {
  double x0, x1, l1, l2, r, f1, f2, f3;
  int max_iterations, count = 1;

  printf("Znajdź pierwiastek poniższej funkcji używajac metody Bisekcji: \n");
  printf("x^4 - 7x^3 + 2x^2 - 4\n");

  printf("\nWprowadź początek przedziału poszukiwań: ");
  scanf("%lf", &x0);

  printf("Wprowadź koniec przedziału poszukiwań: ");
  scanf("%lf", &x1);

  if (function(x0) * function(x1) > 0) {
    printf("\nFunkcja nia ma różnych znaków na krańcach przedziału.\n");
    return 1;
  }

  printf("Wprowadź liczbę iteracji: ");
  scanf("%d", &max_iterations);

  l1 = x0;
  l2 = x1;

  if (function(l1) == 0) {
    r = l1;
  } else if (function(l2) == 0) {
    r = l2;
  } else {
    while (count <= max_iterations) {
      f1 = function(l1);
      r = (l1 + l2) / 2.0;
      f2 = function(r);
      f3 = function(l2);

      if (f2 == 0) {
        r = f2;
        break;
      }

      printf("\nPierwiastek po %d iteracji w przybliżeniu wynosi %lf.", count,
             r);

      if (f1 * f2 < 0) {
        l2 = r;
      } else if (f2 * f3 < 0) {
        l1 = r;
      }

      count++;
    }
  }

  printf("\n\nPrzybliżona wartość finalna pierwiastka: %lf \n", r);
  return 0;
}

double function(double x) {
  return (pow(x, 4) - 7 * pow(x, 3) + 2 * pow(x, 2) - 4);
}
