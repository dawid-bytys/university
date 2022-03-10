#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void print_ids();

int main() {
  print_ids();

  return 0;
}

void print_ids() {
  uid_t UID = getuid();
  gid_t GID = getgid();
  pid_t PID = getpid();
  pid_t PPID = getppid();
  pid_t PGID = getpgrp();

  printf("UID of the current process: %d\n", UID);
  printf("GID of the current process: %d\n", GID);
  printf("PID of the current process: %d\n", PID);
  printf("PPID of the current process: %d\n", PPID);
  printf("PGID of the current process: %d\n\n", PGID);
}
