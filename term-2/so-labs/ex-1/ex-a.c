#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void print_ids();

int main() {
  print_ids();

  return 0;
}

void print_ids() {
  printf("UID = %i GID = %i PID = %i PPID = %i PGID = %i \n", getuid(),
         getgid(), getpid(), getppid(), getpgrp());
}
