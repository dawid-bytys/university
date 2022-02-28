#include <stdio.h>

void gcd(unsigned int m, unsigned int n);

int main() {
  unsigned int m, n;
  int input;

  printf("Wprowadź dwie liczby naturalne po spacji z warunkiem, że m >= n: ");
  input = scanf("%u %u", &m, &n);

  if (input != 2 || m < n) {
    printf("Błędne dane.");
    return 1;
  }

  gcd(m, n);
  return 0;
}

void gcd(unsigned int m, unsigned int n) {
  if (n == 0 || n == m) {
    printf("NWD: %u", m);
  } else {
    unsigned int result = 0;
    int i;

    for (i = 0; i <= n; i++) {
      if (n % i == 0 && m % i == 0) {
        if (i > result) {
          result = i;
        }
      }
    }

    printf("NWD: %u", result);
  }
}
