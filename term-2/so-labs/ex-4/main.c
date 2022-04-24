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

#define BUFF_SIZE 5

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid arguments\n");
    printf("Usage: ./main.x <in> <out>\n");
    exit(EXIT_FAILURE);
  }

  int fd_storage[2];
  if (pipe(fd_storage) == -1) {
    printf("pipe error");
    exit(EXIT_FAILURE);
  }

  pid_t process = fork();
  int wait_status;

  if (process == -1) {
    perror("fork error");
    exit(EXIT_FAILURE);
  } else if (process == 0) {
    close(fd_storage[0]);
    producer(fd_storage[1], argv[1], BUFF_SIZE);
    close(fd_storage[1]);
  } else {
    sleep(random_number(1, 5));
    close(fd_storage[1]);
    consumer(fd_storage[0], argv[2], BUFF_SIZE);
    close(fd_storage[0]);

    if (wait(&wait_status) == -1) {
      perror("wait error");
      exit(wait_status);
    }
  }

  return 0;
}
