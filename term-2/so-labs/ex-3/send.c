// #############################
// Dawid Bytys Krakow 06.04.2022
// #############################
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
  if (argc != 3) {
    printf("Invalid number of arguments.\n");
    exit(EXIT_FAILURE);
  }

  pid_t process = fork();

  if (process == -1) {
    perror("fork error");
    exit(EXIT_FAILURE);
  } else if (process == 0) {
    if (execl("./signal.x", "signal.x", argv[1], argv[2], NULL) == -1) {
      perror("failed to exec file");
      exit(EXIT_FAILURE);
    }
  } else {
    sleep(1);

    if (kill(process, 0) == -1) {
      perror("Process does not exist.");
      exit(EXIT_FAILURE);
    }

    if (kill(process, atoi(argv[2])) == -1) {
      perror("kill error");
      exit(EXIT_FAILURE);
    }

    if (wait(NULL) == -1) {
      perror("wait error");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
