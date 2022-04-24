// Dawid Bytys Krakow, 24.04.2022
// Program tworzy strumień nazwany,
// zczytuje dane z pliku, zapisuje
// je do strumienia, a następnie
// pobiera je z tego strumienia i
// zapisuje w drugim pliku
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define PROCESSES_COUNT 2

const char *fifo;

void execution_error(int arguments);
void remove_fifo(void);
void wait_process(void);
unsigned random_number(unsigned min, unsigned max);
const char *concat(const char *s1, const char *s2);

int main(int argc, const char *argv[]) {
  execution_error(argc);

  fifo = argv[3];

  if (atexit(remove_fifo) != 0) {
    perror("atexit error");
    exit(EXIT_FAILURE);
  }

  if (mkfifo(fifo, 0777) == -1) {
    perror("mkfifo error");
    exit(EXIT_FAILURE);
  }

  // PRODUCER
  pid_t producer_process = fork();
  if (producer_process == -1) {
    perror("producer fork error");
    exit(EXIT_FAILURE);
  } else if (producer_process == 0) {
    if (execl(concat("./", argv[1]), argv[1], argv[3], argv[4], argv[6],
              NULL) == -1) {
      perror("execl error");
      exit(EXIT_FAILURE);
    }
  }

  // CONSUMER
  pid_t consumer_process = fork();
  if (consumer_process == -1) {
    perror("consumer fork error");
    exit(EXIT_FAILURE);
  } else if (consumer_process == 0) {
    if (execl(concat("./", argv[2]), argv[2], argv[3], argv[5], argv[6],
              NULL) == -1) {
      perror("execl error");
      exit(EXIT_FAILURE);
    }
  }

  sleep(random_number(1, 5));
  wait_process();

  return 0;
}

void execution_error(int argc) {
  if (argc != 7) {
    printf("Invalid usage. Correct: ./fifo.x <producer> <consumer> <fifo> <in> "
           "<out> "
           "<buffer_size>\n");
    exit(EXIT_FAILURE);
  }
}

void remove_fifo(void) {
  if (unlink(fifo) == -1) {
    perror("unlink error");
    exit(EXIT_FAILURE);
  }

  printf("\nfifo queue has been removed.\n");
}

unsigned random_number(unsigned min, unsigned max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void wait_process(void) {
  for (int i = 0; i < PROCESSES_COUNT; i++) {
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

const char *concat(const char *s1, const char *s2) {
  char *ns = malloc(strlen(s1) + strlen(s2) + 1);
  ns[0] = '\0';
  strcat(ns, s1);
  strcat(ns, s2);
  return ns;
}
