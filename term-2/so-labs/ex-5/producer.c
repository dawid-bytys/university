#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
  int buff_size = atoi(argv[3]);
  void *buffer = malloc(buff_size);
  ssize_t read_bytes;

  int in_storage = open(argv[2], O_RDONLY);
  if (in_storage == -1) {
    perror("Error while opening file in storage");
    exit(EXIT_FAILURE);
  }

  int stream = open(argv[1], O_WRONLY);
  if (stream == -1) {
    perror("Error while opening pipe");
    exit(EXIT_FAILURE);
  }

  while ((read_bytes = read(in_storage, buffer, buff_size)) > 0) {
    printf("\nWriting into pipe:\n");

    if (write(STDOUT_FILENO, buffer, read_bytes) == -1) {
      perror("Error while writing into console");
      exit(EXIT_FAILURE);
    }

    if (write(stream, buffer, read_bytes) == -1) {
      printf("Error while writing into pipe");
      exit(EXIT_FAILURE);
    }
  }

  if (close(stream) == -1) {
    perror("Error while closing pipe");
    exit(EXIT_FAILURE);
  }

  if (close(in_storage) == -1) {
    perror("Error while closing in storage");
    exit(EXIT_FAILURE);
  }

  free(buffer);

  return 0;
}
