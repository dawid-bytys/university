#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long int convert(char *arr, int arr_size);

int main() {
  char *arr_of_first_number = malloc(0), *arr_of_second_number = malloc(0);
  int count_one = 0, count_two = 0;
  char char_one, char_two;

  printf("Podaj pierwszą liczbę: ");
  while ((char_one = getchar()) != '\n') {
    if (char_one == '-' || isalpha(char_one)) {
      printf("Wprowadź liczbę naturalną.");
      return 1;
    }

    count_one++;
    arr_of_first_number =
        realloc(arr_of_first_number, count_one * sizeof(char));
    arr_of_first_number[count_one - 1] = char_one;
  }

  printf("Podaj drugą liczbę: ");
  while ((char_two = getchar()) != '\n') {
    if (char_two == '-' || isalpha(char_two)) {
      printf("Wprowadź liczbę naturalną.");
      return 1;
    }

    count_two++;
    arr_of_second_number =
        realloc(arr_of_second_number, count_two * sizeof(char));
    arr_of_second_number[count_two - 1] = char_two;
  }

  unsigned long long int number_one = convert(arr_of_first_number, count_one);
  unsigned long long int number_two = convert(arr_of_second_number, count_two);

  if (number_one > 4294967295 || number_two > 4294967295) {
    printf("Wprowadzono za dużą liczbę.");
    return 1;
  }

  printf("Iloczyn: %llu", number_one * number_two);
  return 0;
}

unsigned long long int convert(char *arr, int arr_size) {
  unsigned long int number = 0;
  int i;

  for (i = 0; i < arr_size; i++) {
    number += ((int)arr[i] - 48) * pow(10, arr_size - 1 - i);
  }

  return number;
}
