#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void producer(int fd_storage, const char *file, int buffer_size) {
  void *buffer = malloc(buffer_size);
  ssize_t read_bytes;

  int in_storage = open(file, O_RDONLY);
  if (in_storage == -1) {
    perror("Error while opening 'in_storage'");
    exit(EXIT_FAILURE);
  }

  while ((read_bytes = read(in_storage, buffer, buffer_size))) {
    if (read_bytes == -1) {
      perror("Error while reading from storage");
      exit(EXIT_FAILURE);
    }

    printf("\n[PRODUCER] - Writing into pipe:\n");
    sleep(random_number(1, 3));

    if (write(STDOUT_FILENO, buffer, read_bytes) == -1) {
      perror("Error while writing into console");
      exit(EXIT_FAILURE);
    }

    if (write(fd_storage, buffer, read_bytes) == -1) {
      perror("Error while writing into storage");
      exit(EXIT_FAILURE);
    }
  }

  close_storage(in_storage);
  free(buffer);
}

void consumer(int fd_storage, const char *file, int buffer_size) {
  void *buffer = malloc(buffer_size);
  ssize_t read_bytes;

  int out_storage = open(file, O_WRONLY);
  if (out_storage == -1) {
    perror(" Error while opening 'out_storage'");
    exit(EXIT_FAILURE);
  }

  while ((read_bytes = read(fd_storage, buffer, buffer_size))) {
    if (read_bytes == -1) {
      perror("Error while reading from storage");
      exit(EXIT_FAILURE);
    }

    printf("\n[CONSUMER] - Writing from pipe:\n");
    sleep(random_number(1, 3));

    if (write(STDOUT_FILENO, buffer, read_bytes) == -1) {
      perror("Error while writing into console");
      exit(EXIT_FAILURE);
    }

    if (write(out_storage, buffer, read_bytes) == -1) {
      perror("Error while writing into storage");
      exit(EXIT_FAILURE);
    }
  }

  close_storage(out_storage);
  free(buffer);
}

void close_storage(int file_desc) {
  if (close(file_desc) == -1) {
    exit(EXIT_FAILURE);
  }
}

unsigned random_number(unsigned min, unsigned max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
