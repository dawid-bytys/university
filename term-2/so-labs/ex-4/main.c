// Dawid Bytys, Krakow 08.04.2022
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define _XOPEN_SOURCE 500
#define BUFF_SIZE 5

void producer(int, const char *);
void consumer(int, const char *);
unsigned random_number(unsigned, unsigned);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid arguments\n");
    printf("Usage: ./main.x <in> <out>\n");
    exit(EXIT_FAILURE);
  }

  int file_desc[2];
  if (pipe(file_desc) == -1) {
    printf("pipe error");
    exit(EXIT_FAILURE);
  }

  pid_t process = fork();

  if (process == -1) {
    perror("fork error");
    exit(EXIT_FAILURE);
  } else if (process == 0) {
    close(file_desc[0]);
    producer(file_desc[1], argv[1]);
    close(file_desc[1]);
  } else {
    sleep(random_number(1, 5));
    close(file_desc[1]);
    consumer(file_desc[0], argv[2]);
    close(file_desc[0]);

    if (wait(NULL) == -1) {
      perror("wait error");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}

void producer(int file_desc, const char *file) {
  void *buffer = malloc(BUFF_SIZE);
  ssize_t reading;
  ssize_t writing;

  int storage = open(file, O_RDONLY);
  if (storage == -1) {
    printf("Error while opening file %s\n", file);
    exit(EXIT_FAILURE);
  }

  while ((reading = read(storage, buffer, BUFF_SIZE)) > 0) {
    printf("\nWriting into pipe:\n");

    writing = write(file_desc, buffer, reading);
    if ((write(STDOUT_FILENO, buffer, writing)) == -1) {
      printf("Error while writing");
      exit(EXIT_FAILURE);
    }
  }

  if (close(storage) == -1) {
    printf("Error while closing");
    exit(EXIT_FAILURE);
  }

  free(buffer);
}

void consumer(int file_desc, const char *file) {
  void *buffer = malloc(BUFF_SIZE);
  ssize_t reading;
  ssize_t writing;

  int clipboard = open(file, O_WRONLY);
  if (clipboard == -1) {
    printf("Error while opening file %s\n", file);
    exit(EXIT_FAILURE);
  }

  while ((reading = read(file_desc, buffer, BUFF_SIZE)) > 0) {
    printf("\nWriting from pipe:\n");

    writing = write(clipboard, buffer, reading);
    if ((write(STDOUT_FILENO, buffer, writing)) == -1) {
      printf("Error while writing");
      exit(EXIT_FAILURE);
    }
  }

  if (close(clipboard) == -1) {
    printf("Error while closing");
    exit(EXIT_FAILURE);
  }

  free(buffer);
}

unsigned random_number(unsigned start, unsigned end) {
  srand(time(NULL));
  return rand() % (end + start + 1) + start;
}
