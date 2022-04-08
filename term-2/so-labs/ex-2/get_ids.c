#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void get_ids();

int main() {
  get_ids();

  return 0;
}

void get_ids() {
  printf("UID = %i GID = %i PID = %i PPID = %i PGID = %i \n", getuid(),
         getgid(), getpid(), getppid(), getpgrp());
}
