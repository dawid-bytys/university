#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last_month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *week_days[7] = {"Niedziela", "Poniedziałek", "Wtorek", "Środa",
                      "Czwartek",  "Piątek",       "Sobota"};

int main() {
  int day, month, year, i;
  char command[100];

  printf("Podaj datę w formacie DD-MM-RRRR: ");
  scanf("%d-%d-%d", &day, &month, &year);

  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    last_month_days[1] = 29;

  if (year < 1900 || month < 1 || month > 12 || day < 1 ||
      day > last_month_days[month - 1]) {
    printf("Nieprawidłowy format.\n");
    return 1;
  }

  for (i = 1900; i < year; i++)
    if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
      day += 366;
    else
      day += 365;

  for (i = 0; i < month - 1; i++)
    day += last_month_days[i];

  printf("Dzień tygodnia: %s.\n", week_days[day % 7]);

  sprintf(command, "cal %d %d", month, year);
  system(command);

  return 0;
}
