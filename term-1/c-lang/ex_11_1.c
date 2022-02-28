#include <stdio.h>
#include <stdlib.h>

int Konwersja_Dec_Bin(unsigned dec, char *bin);

int main() {
  int number, input, length, i;
  char *bin = malloc(0);

  printf("Wprowadź liczbę całkowitą: ");
  input = scanf("%u", &number);

  if (input != 1 || number < 0) {
    printf("Niedozwolone wejście.\n");
    return 1;
  }

  length = Konwersja_Dec_Bin((unsigned)number, bin);
  printf("Długość liczby %u w systemie binarnym wynosi: %d\n", number, length);

  printf("Liczba %u w systemie binarnym: ", number);
  for (i = length; i >= 0; i--) {
    printf("%c", bin[i]);
  }
  printf("\n");

  return 0;
}

int Konwersja_Dec_Bin(unsigned dec, char *bin) {
  int i = 0;

  while (dec > 0) {
    bin = realloc(bin, (i + 1) * sizeof(char));
    bin[i] = (dec % 2) + '0';
    dec /= 2;
    i++;
  }

  return i;
}
