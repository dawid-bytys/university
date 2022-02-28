#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100
#define ROW_MAX 50

int compare(const void *a, const void *b);

int main() {
  char *Tekst[N_MAX], row[ROW_MAX];
  int i, j;

  printf("Wprowadź wiersze tekstu po enterze lub kliknij [CTRL + D], żeby "
         "zakończyć: \n");
  for (i = 0; i < N_MAX; i++) {
    printf("[%d]: ", i + 1);

    if (fgets(row, ROW_MAX, stdin) != NULL) {
      if (row[strlen(row) - 1] != '\n') {
        printf("Przekroczono limit znaków.\n");
        return 1;
      }

      if (strcmp(row, "\n") == 0) {
        i--;
        continue;
      }

      Tekst[i] = strndup(row, ROW_MAX);
    } else
      break;
  }

  qsort(Tekst, i, sizeof(char *), compare);

  printf("\n\nW kolejności alfabetycznej: \n");
  for (j = 0; j < i; j++) {
    printf("[%d]: %s", j + 1, Tekst[j]);
  }

  return 0;
}

int compare(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}
