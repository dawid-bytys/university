// Dawid Bytys Krakow, 24.04.2022
// Program tworzy strumień nazwany,
// zczytuje dane z pliku, zapisuje
// je do strumienia, a następnie
// pobiera je z tego strumienia i
// zapisuje w drugim pliku
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define PROCESSES_COUNT 2

const char *fifo;

void remove_fifo(void);

int main(int argc, const char *argv[]) {
  execution_error(argc);

  fifo = argv[3];

  // Remove fifo on exit
  if (atexit(remove_fifo) != 0) {
    perror("atexit error");
    exit(EXIT_FAILURE);
  }

  // Create a fifo with all permisions
  if (mkfifo(fifo, 0777) == -1) {
    perror("mkfifo error");
    _exit(EXIT_FAILURE);
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

  // Wait for the processes to end
  wait_process(PROCESSES_COUNT);

  return 0;
}

void remove_fifo(void) {
  if (unlink(fifo) == -1) {
    perror("unlink error");
    exit(EXIT_FAILURE);
  }

  printf("\nfifo queue has been removed.\n");
}
