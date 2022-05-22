#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execution_error(int argc) {
  if (argc != 4) {
    printf("Invalid usage.\n Correct: ./multiplier.x ./main.x "
           "<processes_count> <critical_sections_count>");
    exit(EXIT_FAILURE);
  }
}

void signal_handler(int signal) {
  printf("Signal: %d", signal);
  exit(EXIT_SUCCESS);
}

const char *concat(const char *s1, const char *s2) {
  char *ns = malloc(strlen(s1) + strlen(s2) + 1);
  ns[0] = '\0';
  strcat(ns, s1);
  strcat(ns, s2);
  return ns;
}

void wait_process(int processes_count) {
  for (int i = 0; i < processes_count; i++) {
    pid_t process_end;
    int status;

    if ((process_end = wait(&status)) == -1) {
      perror("wait error");
      exit(EXIT_FAILURE);
    }

    printf("\nProcess %d has been terminated with status %d", process_end,
           status);
  }
}

void close_storage(int storage) {
  if (close(storage) == -1) {
    perror("Failed to close the storage.");
    exit(EXIT_FAILURE);
  }
}

void state_verification(const char *file, int processes_count,
                        int critical_sections_count) {
  char value[2];

  int storage = open(file, O_RDONLY);
  if (storage == -1) {
    perror("Failed to open the state.txt file.");
    _exit(EXIT_FAILURE);
  }

  if (read(storage, value, sizeof(char *)) == -1) {
    perror("Failed to read the data from the state.txt file.");
    _exit(EXIT_FAILURE);
  }

  printf("State from the end: %d\n State from the start: %d\n", atoi(value),
         processes_count * critical_sections_count);

  if (atoi(value) == (processes_count * critical_sections_count)) {
    printf("States match!\n");
  } else {
    printf("States do not match!\n");
  }
}

unsigned random_number(unsigned min, unsigned max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
