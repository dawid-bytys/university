// Dawid Bytys Krakow 06.04.2022
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void invalid_argument_error();
void handle_signal(int);
int get_signal_action(const char *);

int main(int argc, char *argv[]) {
  int signal_type = get_signal_action(argv[1]);
  int signal_num = atoi(argv[2]);

  if (signal_num == 9 || signal_num == 19) {
    printf("Cannot handle this type of signal, try different one\n");
    exit(EXIT_FAILURE);
  }

  if (argc == 2) {
    printf("3rd argument wasn't provided, doing default operation\n");

    if (signal(signal_num, SIG_DFL) == SIG_ERR) {
      perror("Signal error.");
      exit(EXIT_FAILURE);
    }
  } else {
    if (signal_type == -1) {
      invalid_argument_error();
      exit(EXIT_FAILURE);
    } else if (signal_type == 1) {
      printf("[DEFAULT SIGNAL]\n");

      if (signal(signal_num, SIG_DFL) == SIG_ERR) {
        perror("Signal error.");
        exit(EXIT_FAILURE);
      }
    } else if (signal_type == 2) {
      printf("[IGNORING SIGNAL]\n");

      if (signal(signal_num, SIG_IGN) == SIG_ERR) {
        perror("Signal error.");
        exit(EXIT_FAILURE);
      }
    } else {
      printf("[SELF-HANDLING]\n");

      if (signal(signal_num, handle_signal) == SIG_ERR) {
        perror("Signal error.");
        exit(EXIT_FAILURE);
      }
    }
  }

  pause();

  return 0;
}

void handle_signal(int signal) { printf("\nSignal: %d\n", signal); }

void invalid_argument_error() {
  printf("Invalid arguments:\n");
  printf("d - default operation\n");
  printf("i - ignore signal\n");
  printf("p - signal interception and self-handling\n");
  printf("\n");
}

int get_signal_action(const char *signal_action) {
  if (strcmp(signal_action, "d") == 0) {
    return 1;
  }

  if (strcmp(signal_action, "i") == 0) {
    return 2;
  }

  if (strcmp(signal_action, "p") == 0) {
    return 3;
  }

  return -1;
}
