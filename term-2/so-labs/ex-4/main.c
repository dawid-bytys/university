// Dawid Bytys, Krakow 08.04.2022
// Program czyta dane z pliku tekstowego
// do pipe'a, a następnie zczytuje dane z tego pipe'a
// i zapisuje je w nowym pliku.
// Ile danych zczyta zalezy od makra BUFF_SIZE
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFF_SIZE_PRODUCER 15
#define BUFF_SIZE_CONSUMER 10

int main(int argc, char *argv[]) {
  // Check arguments count
  if (argc != 3) {
    printf("Invalid arguments\n");
    printf("Usage: ./main.x <in> <out>\n");
    exit(EXIT_FAILURE);
  }

  // Create a file descriptor storage
  int fd_storage[2];
  if (pipe(fd_storage) == -1) {
    printf("Error while creating a file descriptor storage");
    exit(EXIT_FAILURE);
  }

  // Create a new process
  pid_t process = fork();
  int wait_status;

  if (process == -1) {
    perror("Error while creating a new process");
    exit(EXIT_FAILURE);
  } else if (process == 0) {
    close_storage(fd_storage[0]);
    producer(fd_storage[1], argv[1], BUFF_SIZE_PRODUCER);
    close_storage(fd_storage[1]);
  } else {
    // Wait for the child to end
    if (wait(&wait_status) == -1) {
      perror("wait error");
      exit(wait_status);
    }

    close_storage(fd_storage[1]);
    consumer(fd_storage[0], argv[2], BUFF_SIZE_CONSUMER);
    close_storage(fd_storage[0]);
  }

  return 0;
}
