// Dawid Bytys, Krakow 08.04.2022
// Program czyta dane z pliku tekstowego
// do pipe'a, a następnie zczytuje dane z tego pipe'a
// i zapisuje je w nowym pliku.
// Ile danych zczyta zalezy od makra BUFF_SIZE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define BUFF_SIZE 5

void producer(int file_desc, const char *file);
void consumer(int file_desc, const char *file);
unsigned random_number(unsigned min, unsigned max);

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
    producer(fd_storage[1], argv[1]);
    close(fd_storage[1]);
  } else {
    sleep(random_number(1, 5));
    close(fd_storage[1]);
    consumer(fd_storage[0], argv[2]);
    close(fd_storage[0]);

    if (wait(&wait_status) == -1) {
      perror("wait error");
      exit(wait_status);
    }
  }

  return 0;
}

void producer(int fd_storage, const char *file) {
  void *buffer = malloc(BUFF_SIZE);
  ssize_t read_bytes;

  int in_storage = open(file, O_RDONLY);
  if (in_storage == -1) {
    perror("Error while opening 'in_storage'");
    exit(EXIT_FAILURE);
  }

  while ((read_bytes = read(in_storage, buffer, BUFF_SIZE)) > 0) {
    printf("\nWriting into pipe:\n");

    if (write(STDOUT_FILENO, buffer, read_bytes) == -1) {
      perror("Error while writing into console");
      exit(EXIT_FAILURE);
    }

    if (write(fd_storage, buffer, read_bytes) == -1) {
      perror("Error while writing into storage");
      exit(EXIT_FAILURE);
    }
  }

  if (close(in_storage) == -1) {
    perror("Error while closing");
    exit(EXIT_FAILURE);
  }

  free(buffer);
}

void consumer(int fd_storage, const char *file) {
  void *buffer = malloc(BUFF_SIZE);
  ssize_t read_bytes;

  int out_storage = open(file, O_WRONLY);
  if (out_storage == -1) {
    perror("Error while opening 'out_storage'");
    exit(EXIT_FAILURE);
  }

  while ((read_bytes = read(fd_storage, buffer, BUFF_SIZE)) > 0) {
    printf("\nWriting from pipe:\n");

    if (write(STDOUT_FILENO, buffer, read_bytes) == -1) {
      perror("Error while writing into console");
      exit(EXIT_FAILURE);
    }

    if (write(out_storage, buffer, read_bytes) == -1) {
      perror("Error while writing into storage");
      exit(EXIT_FAILURE);
    }
  }

  if (close(out_storage) == -1) {
    perror("Error while closing");
    exit(EXIT_FAILURE);
  }

  free(buffer);
}

unsigned random_number(unsigned min, unsigned max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
