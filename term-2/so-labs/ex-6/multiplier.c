#include "sem.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const char *name = "semaphore";

void execution_error(int argc);
void exit_handler(void);
void signal_handler(int signal);
const char *concat(const char *s1, const char *s2);
void wait_process(void);

int main(int argc, const char *argv[]) {
  // Handle exit function
  if (atexit(exit_handler) != 0) {
    perror("atexit() error");
    exit(EXIT_FAILURE);
  }

  // Handle execution error
  execution_error(argc);

  int processes_count = atoi(argv[2]);
  int critical_sections_count = atoi(argv[3]);

  // Open a file to store semaphore state
  int number_storage = open("number.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
  if (number_storage == -1) {
    perror("Failed to open a number storage.");
    exit(EXIT_FAILURE);
  }

  // Write a initial state value to the file
  if (write(number_storage, "0", sizeof(char)) == -1) {
    perror("Failed to write into number storage.");
    exit(EXIT_FAILURE);
  }

  // Create a sepahore
  sem_id new_semaphore = semaphore_create(name, 1);
  int new_semaphore_value = semaphore_value(new_semaphore);
  printf("The new semaphore's address: %p", new_semaphore);
  printf("The new semaphore's value: %d", new_semaphore_value);

  // Handle own signal
  if (signal(SIGINT, signal_handler) == SIG_ERR) {
    perror("Failed to ignore the signal.");
    exit(EXIT_FAILURE);
  }

  // Create new processes
  for (int i = 0; i < processes_count; i++) {
    pid_t process = fork();

    if (process == -1) {
      perror("Failed to create a new process.");
      exit(EXIT_FAILURE);
    } else if (process == 0) {
      if (execl(concat("./", argv[1]), processes_count, critical_sections_count,
                NULL) == -1) {
        perror("Failed to exec a program.");
        exit(EXIT_FAILURE);
      }
    }
  }

  wait_process();

  return 0;
}

void execution_error(int argc) {
  if (argc != 4) {
    printf("Invalud usage.\n Correct: ./multiplier.x ./main.x "
           "<processes_count> <critical_sections_count>");
    exit(EXIT_FAILURE);
  }
}

void exit_handler(void) { sem_close(name); }

void signal_handler(int signal) {
  printf("Signal: %d", signal);
  exit(EXIT_SUCCESS);
}

const char *concat(const char *s1, const char *s2) {
  char *ns = malloc(strlen(s1) + strlen(s2) + 1);
  ns[0] = '\0';
  strcat(ns, s1);
  strcat(ns, s2);
  return ns;
}

void wait_process(void) {
  for (int i = 0; i < PROCESSES_COUNT; i++) {
    pid_t process_end;
    int status;

    if ((process_end = wait(&status)) == -1) {
      perror("wait error");
      exit(EXIT_FAILURE);
    }

    printf("\nProcess %d has been terminated with status %d", process_end,
           status);
  }
}