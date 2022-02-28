#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Counterparts {
  int arab;
  char *rzym;
} Counterparts;

typedef struct RomanResult {
  char **symbols;
  int size;
} RomanResult;

int validate_type(char *digits, int size);
int roman_to_arabic(char *digits, int size);
RomanResult arabic_to_roman(char *digits, int size);

Counterparts counterparts_arr[13] = {
    {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
    {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
    {500, "D"}, {900, "CM"}, {1000, "M"}};

int main() {
  char *digits = malloc(0), input_char;
  int count = 0, sum = 0, i, j;
  RomanResult roman_result;

  printf("Podaj liczbę rzymską/arabską: ");
  while ((input_char = getchar()) != '\n') {
    if (input_char == '-') {
      printf("Błędny input.\n");
      return 1;
    }

    count++;
    digits = realloc(digits, count * sizeof(char));
    digits[count - 1] = input_char;
  }

  if (validate_type(digits, count) == 0) {
    for (i = 0; i < count; i++) {
      sum += ((int)digits[i] - 48) * pow(10, count - 1 - i);
    }

    if (sum < 1 || sum > 3999) {
      printf("Przekroczono zakres liczb, domyślny to [1, 3999].\n");
      return 1;
    }

    roman_result = arabic_to_roman(digits, count);
    printf("Arabska -> Rzymska: ");

    for (j = 0; j < roman_result.size; j++) {
      printf("%s", roman_result.symbols[j]);
    }

  } else if (validate_type(digits, count) == 1) {
    printf("Rzymska -> Arabska: %d\n", roman_to_arabic(digits, count));
  } else {
    printf("Coś poszło nie tak, sprawdź czy poprawnie wprowadziłeś dane.\n");
    return 1;
  }

  return 0;
}

int validate_type(char *digits, int size) {
  int arabic_count = 0, roman_count = 0, i, j;

  for (i = 0; i < size; i++) {
    if (isdigit(digits[i])) {
      arabic_count++;
    } else {
      for (j = 0; j < 13; j++) {
        if (digits[i] == counterparts_arr[j].rzym[0]) {
          roman_count++;
          break;
        }
      }
    }
  }

  if (arabic_count == size) {
    return 0;
  } else if (roman_count == size) {
    return 1;
  } else {
    return 2;
  }
}

int roman_to_arabic(char *digits, int size) {
  int i, j, sum = 0;

  for (i = 0; i < size; i++) {
    if (digits[i] == 'I' && digits[i + 1] == 'V') {
      sum += counterparts_arr[1].arab;
      i++;
    } else if (digits[i] == 'I' && digits[i + 1] == 'X') {
      sum += counterparts_arr[1].arab;
      i++;
    } else if (digits[i] == 'X' && digits[i + 1] == 'L') {
      sum += counterparts_arr[5].arab;
      i++;
    } else if (digits[i] == 'X' && digits[i + 1] == 'C') {
      sum += counterparts_arr[7].arab;
      i++;
    } else if (digits[i] == 'C' && digits[i + 1] == 'M') {
      sum += counterparts_arr[11].arab;
      i++;
    } else if (digits[i] == 'C' && digits[i + 1] == 'D') {
      sum += counterparts_arr[9].arab;
      i++;
    } else {
      for (j = 0; j < 13; j++) {
        if (*counterparts_arr[j].rzym == digits[i]) {
          sum += counterparts_arr[j].arab;
          break;
        }
      }
    }
  }

  return sum;
}

RomanResult arabic_to_roman(char *digits, int size) {
  int i, j, k = 0, l;
  char **result = malloc(0);
  int temp = atoi(digits);
  RomanResult roman_result;

  while (temp > 0) {
    for (j = 12; j >= 0; j--) {
      if (temp >= counterparts_arr[j].arab) {
        k++;
        result = realloc(result, k * sizeof(char *));
        result[k - 1] = counterparts_arr[j].rzym;
        temp -= counterparts_arr[j].arab;
        j++;
      }
    }
  }

  roman_result.symbols = result;
  roman_result.size = k;

  return roman_result;
}
