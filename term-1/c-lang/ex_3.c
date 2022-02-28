#include <stdio.h>

void find_primes(unsigned long long int n);

int main() {
  unsigned long long int n, input;

  printf("Wprowadź końcowy limit: ");
  input = scanf("%llu", &n);

  if (input != 1) {
    printf("Nieprawidłowe dane.");
    return 1;
  }

  find_primes(n);

  return 0;
}

void find_primes(unsigned long long int n) {
  int i, j, k, l;
  unsigned long long int primary_arr[n - 1];

  for (i = 2; i < n; i++) {
    primary_arr[i] = i;
  }

  for (j = 2; j < n; j++) {
    if (!primary_arr[j])
      break;

    for (k = j; k * j < n; k++) {
      primary_arr[k * j] = 0;
    }
  }

  printf("\nLiczby pierwsze: ");

  for (l = 2; l < n; l++) {
    if (primary_arr[l]) {
      printf("%llu ", primary_arr[l]);
    }
  }
}
