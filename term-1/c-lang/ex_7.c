#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binomial_iterative(int n, int k);
int binomial_recursive(int n, int k);
double bernoulli_distribution(int n, int k, double p, int w);

int main(int argc, char *argv[]) {
  int n, k, input;
  int w = !strcmp("-r", argv[1]) ? 1 : 0;
  double p;

  printf("Podaj n, k, p po spacji: ");
  input = scanf("%d %d %lf", &n, &k, &p);

  if (input != 3) {
    printf("Niepoprawne dane!\n");
    return 1;
  }

  printf("Wynik dwumianu Newtona %s: %d\n", w ? "rekurencyjnie" : "iteracyjnie",
         w ? binomial_recursive(n, k) : binomial_iterative(n, k));
  printf("Prawdopodobieństwo Bernoulliego: %0.10lf\n",
         bernoulli_distribution(n, k, p, w));

  return 0;
}

int binomial_iterative(int n, int k) {
  int i, j, *binomial_array;
  binomial_array = malloc((n + 1) * sizeof(int));
  binomial_array[0] = 1;
  binomial_array[1] = 1;

  for (i = 2; i <= n; i++) {
    binomial_array[i] = 1;
    for (j = i - 1; j > 0; j--) {
      binomial_array[j] += binomial_array[j - 1];
    }
  }

  return binomial_array[k];
}

int binomial_recursive(int n, int k) {
  if (k == 0 || k == n) {
    return 1;
  }

  return binomial_recursive(n - 1, k - 1) + binomial_recursive(n - 1, k);
}

double bernoulli_distribution(int n, int k, double p, int w) {
  int binomial = w ? binomial_recursive(n, k) : binomial_iterative(n, k);

  return binomial * pow(p, k) * pow((1 - p), n - k);
}
