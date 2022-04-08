#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void get_ids();
void print_usage();
void check_arguments();

int main(int argc, char *argv[]) {
  pid_t pid;

  check_arguments(argc);

  printf("Proces macierzysty: ");
  get_ids();

  for (int i = 0; i < 3; i++) {
    pid = fork();

    if (pid == -1) {
      perror("fork error");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      execlp(argv[1], argv[1], NULL);
    } else {
      wait(0);
    }
  }

  return 0;
}

void get_ids() {
  printf("UID = %i GID = %i PID = %i PPID = %i PGID = %i \n", getuid(),
         getgid(), getpid(), getppid(), getpgrp());
}

void print_usage() { printf("Correct usage: make run program=<file.x>\n"); }

void check_arguments(int number_of_args) {
  if (number_of_args != 2) {
    printf("Invalid number of arguments\n");
    print_usage();
    exit(EXIT_FAILURE);
  }
}
