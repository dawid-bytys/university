#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void print_ids();

int main() {
  printf("Parent process ids: \n");
  print_ids();

  for (int i = 0; i < 3; i++) {
    pid_t pid = fork();

    if (pid == -1) {
      perror("fork error");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      printf("Child process has started running: \n");
      print_ids();
    } else {
      if (wait(NULL) == -1) {
        perror("wait error");
        exit(EXIT_FAILURE);
      }
    }
  }

  return 0;
}

void print_ids() {
  pid_t PID = getpid();
  setpgid(PID, 0);

  printf("UID = %i GID = %i PID = %i PPID = %i PGID = %i \n", getuid(),
         getgid(), PID, getppid(), getpgrp());
}
