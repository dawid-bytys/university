#include "utils.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void execution_error(int argc) {
  if (argc != 7) {
    printf("Invalid usage. Correct: ./fifo.x <producer> <consumer> <fifo> <in> "
           "<out> "
           "<buffer_size>\n");
    exit(EXIT_FAILURE);
  }
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

void close_storage(int file_desc) {
  if (close(file_desc) == -1) {
    exit(EXIT_FAILURE);
  }
}

unsigned random_number(unsigned min, unsigned max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

const char *concat(const char *s1, const char *s2) {
  char *ns = malloc(strlen(s1) + strlen(s2) + 1);
  ns[0] = '\0';
  strcat(ns, s1);
  strcat(ns, s2);
  return ns;
}
