#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void print_ids();

int main() {
  int i, wait_status;
  pid_t pid;

  printf("Parent process ids: \n");
  print_ids();

  for (i = 0; i < 3; i++) {
    pid = fork();

    if (pid == -1) {
      perror("fork error\n");
      exit(1);
    } else if (pid == 0) {
      printf("Child process has started running: \n");
      print_ids();
      sleep(1);
    } else {
      waitpid(pid, &wait_status, 0);
    }
  }

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
