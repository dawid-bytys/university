#include <math.h>
#include <stdio.h>

double average(double arr[], int size);
double deviation(double arr[], int size);

int main() {
  double arr_of_numbers[1000];
  int c = 0;
  int i = -1;

  do {
    if (i == 1000) {
      printf("Przekroczono limit.\n");
      return 1;
    }

    if (c == 0) {
      printf("TO NIE LICZBA!!!\n");
      return 1;
    }

    printf("Wprowadź liczbę: ");
    i++;
  } while ((c = scanf("%lf", &arr_of_numbers[i])) != EOF);

  printf("\n");
  printf("\nŚrednia arytmetyczna: %lf", average(arr_of_numbers, i));
  printf("\nOdchylenie standardowe: %lf", deviation(arr_of_numbers, i));
  printf("\n");

  return 0;
}

double average(double arr[], int size) {
  double sum = 0;
  int i;

  for (i = 0; i < size; i++) {
    sum += arr[i];
  }

  return sum / size;
}

double deviation(double arr[], int size) {
  double sum = 0;
  double avg = average(arr, size);
  int i;

  for (i = 0; i < size; i++) {
    sum += pow(arr[i] - avg, 2);
  }

  return sqrt(sum / size);
}
