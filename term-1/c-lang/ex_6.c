#include <stdio.h>
#include <string.h>

#define REQUIRED_ARGUMENTS 2
#define MAX_NUMBER 13

int help();
int factorial_recursive_int(int n);
int factorial_iterative_int(int n);
double factorial_recursive_double(int n);
double factorial_iterative_double(int n);

int main(int argc, char *argv[]) {
  if (argc != REQUIRED_ARGUMENTS) {
    return help();
  }

  int is_recursive = strcmp("-r", argv[1]);
  int is_iterative = strcmp("-i", argv[1]);
  int number, c;

  if (is_iterative && is_recursive) {
    return help();
  }

  printf("Podaj liczbę: ");
  c = scanf("%d", &number);

  if (c != 1 || number < 0) {
    printf("Podaj liczbę naturalną.\n");
    return 1;
  }

  if (number >= MAX_NUMBER) {
    printf("Silnia z %d %s wynosi: %.0lf\n", number,
           !is_iterative ? "iteracyjnie" : "rekurencyjnie",
           !is_iterative ? factorial_iterative_double(number)
                         : factorial_recursive_double(number));
  } else {
    printf("Silnia z %d %s wynosi: %d\n", number,
           !is_iterative ? "iteracyjnie" : "rekurencyjnie",
           !is_iterative ? factorial_iterative_int(number)
                         : factorial_recursive_int(number));
  }

  return 0;
}

int help() {
  printf("Usage: program [-i] [-r]\n");
  printf("-i: using iterative function\n");
  printf("-r: using recursive function\n");
  return 1;
}

int factorial_recursive_int(int n) {
  if (n < 2) {
    return 1;
  }

  return n * factorial_recursive_int(n - 1);
}

int factorial_iterative_int(int n) {
  int i, result = 1;

  if (n < 2) {
    return 1;
  }

  for (i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}

double factorial_recursive_double(int n) {
  if (n < 2) {
    return (double)n;
  }

  return (double)n * factorial_recursive_double(n - 1);
}

double factorial_iterative_double(int n) {
  double result = 1.0;
  int i;

  for (i = 2; i <= n; i++) {
    result *= (double)i;
  }

  return result;
}
