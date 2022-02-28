#include <stdio.h>

#define MAX_SIZE 32

int Konwersja_Dec_Bin(unsigned dec, char *bin);

int main() {
  int number, input, length, i;
  char bin[MAX_SIZE];

  printf("Wprowadź liczbę całkowitą: ");
  input = scanf("%u", &number);

  if (input != 1 || number < 0) {
    printf("Niedozwolone wejście.\n");
    return 1;
  }

  length = Konwersja_Dec_Bin((unsigned)number, bin);
  printf("Długość liczby %u w systemie binarnym wynosi: %d\n", number, length);

  printf("Liczba %u w systemie binarnym: ", number);
  for (i = length - 1; i >= 0; i--) {
    printf("%c", bin[i]);
  }
  printf("\n");

  return 0;
}

int Konwersja_Dec_Bin(unsigned dec, char *bin) {
  int i = MAX_SIZE - 1, j, temp, length = MAX_SIZE;

  while (i >= 0) {
    temp = dec >> i;

    if (temp & 1)
      bin[i] = '1';
    else
      bin[i] = '0';

    i--;
  }

  for (j = MAX_SIZE - 1; j >= 0; j--) {
    if (bin[j] == '0' && bin[j - 1] == '1') {
      length -= (length - j);
      break;
    }
  }

  return length;
}
