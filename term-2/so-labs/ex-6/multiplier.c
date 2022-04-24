#include "sem.h"
#include "utils.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Global semaphore name variable
const char *name = "semaphore";

void exit_handler(void);

int main(int argc, const char *argv[]) {
  // Handle exit function
  if (atexit(exit_handler) != 0) {
    perror("atexit() error");
    exit(EXIT_FAILURE);
  }

  // Handle execution error
  execution_error(argc);

  // Convert arguments
  int processes_count = atoi(argv[2]);
  int critical_sections_count = atoi(argv[3]);

  // Open a file to store semaphore state
  int storage = open("store.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
  if (storage == -1) {
    perror("Failed to open a number storage.");
    _exit(EXIT_FAILURE);
  }

  // Write a initial state value to the file
  if (write(storage, "0", sizeof(char *)) == -1) {
    perror("Failed to write into number storage.");
    _exit(EXIT_FAILURE);
  }

  // Create a sepahore, get its value and print info
  sem_id new_semaphore = semaphore_create(name, 1);
  int new_semaphore_value = semaphore_value(new_semaphore);
  printf("The new semaphore's address: %p", new_semaphore);
  printf("The new semaphore's value: %d", new_semaphore_value);

  // Handle CTRL-C
  if (signal(SIGINT, signal_handler) == SIG_ERR) {
    perror("Failed to handle the signal.");
    _exit(EXIT_FAILURE);
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
        _exit(EXIT_FAILURE);
      }
    }
  }

  // Wait for the processes to end
  wait_process(processes_count);

  // Verify the states
  state_verification(processes_count, critical_sections_count);

  // Close the storage
  close_storage(storage);

  return 0;
}

void exit_handler(void) { semaphore_delete(name); }