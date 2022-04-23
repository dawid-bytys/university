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

  int out_storage = open(argv[2], O_WRONLY);
  if (out_storage == -1) {
    perror("Error while opening file out storage");
    exit(EXIT_FAILURE);
  }

  int stream = open(argv[1], O_RDONLY);
  if (stream == -1) {
    perror("Error while opening pipe");
    exit(EXIT_FAILURE);
  }

  while ((read_bytes = read(pipe, buffer, buff_size)) > 0) {
    printf("\nWriting from pipe:\n");

    if (write(STDOUT_FILENO, buffer, read_bytes) == -1) {
      perror("Error while writing into console");
      exit(EXIT_FAILURE);
    }

    if (write(out_storage, buffer, read_bytes) == -1) {
      printf("Error while writing from pipe");
      exit(EXIT_FAILURE);
    }
  }

  if (close(stream) == -1) {
    perror("Error while closing pipe");
    exit(EXIT_FAILURE);
  }

  if (close(out_storage) == -1) {
    perror("Error while closing out storage");
    exit(EXIT_FAILURE);
  }

  free(buffer);

  return 0;
}
