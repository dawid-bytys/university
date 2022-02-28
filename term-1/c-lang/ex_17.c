#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100
#define ROW_MAX 50

int compare_asc(const void *a, const void *b);
int compare_desc(const void *a, const void *b);

int main(int argc, char *argv[]) {
  char *Tekst[N_MAX], row[ROW_MAX];
  int i, j, flag;

  if (argc >= 2) {
    if (strcmp(argv[1], "-asc") == 0)
      flag = 1;
    else if (strcmp(argv[1], "-desc") == 0)
      flag = 0;
    else {
      printf("Niepoprawny argument.\n");
      return 1;
    }
  } else {
    printf("Błędnie podano argumenty.\n");
    return 1;
  }

  printf("Wprowadź ciągi liczb po enterze lub kliknij [CTRL + D], żeby "
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

  if (flag == 1) {
    qsort(Tekst, i, sizeof(char *), compare_asc);
    printf("\n\nRosnąco na podstawie pierwszej cyfry: \n");
  } else {
    qsort(Tekst, i, sizeof(char *), compare_desc);
    printf("\n\nMalejąco na podstawie pierwszej cyfry: \n");
  }

  for (j = 0; j < i; j++) {
    printf("[%d]: %s", j + 1, Tekst[j]);
  }

  return 0;
}

int compare_asc(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int compare_desc(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b) * -1;
}
