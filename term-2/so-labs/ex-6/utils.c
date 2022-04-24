#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
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

void state_verification(int processes_count, int critical_sections_count) {
  int storage = open("state.txt", O_RDONLY);
  if (storage == -1) {
    perror("Failed to open the state.txt file.");
    _exit(EXIT_FAILURE);
  }

  if (fscanf(file, "%i", &state) == -1) {
    perror("Failed to read data from the state.txt file.");
    exit(EXIT_FAILURE);
  }

  printf("State from the end: %d\n State from the start: %d\n", state,
         processes_count * critical_sections_count);
}

void close_storage(int storage) {
  if (close(storage) == -1) {
    perror("Failed to close the storage.");
    exit(EXIT_FAILURE);
  }

  free(storage);
}