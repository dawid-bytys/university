#include "sem.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
  sem_id sem = semaphore_open(argv[2], 1);
  char value[2];
  int storage;
  int number;

  for (int i = 0; i < atoi(argv[2]); i++) {
    // *** PRIVATE SECTION BEFORE CRITICAL SECTION ****
    printf("[PRIVATE SECTION BEFORE CRITICAL SECTION OF %d]\n", getpid());

    // Print the current semaphore's value
    printf("Current semaphore's value: %d\n", semaphore_value(sem));

    // Simulate delay
    sleep(random_number(1, 3));

    // Drop the semaphore
    semaphore_drop(sem);

    // **** CRITICAL SECTION
    printf("[CRITICAL SECTION NO. %d OF %d\n", i + 1, getpid());

    // Print the current semaphore's value
    printf("Current semaphore's value: %d\n", semaphore_value(sem));

    // Open the file in readonly mode
    storage = open(argv[1], O_RDONLY);
    if (storage == -1) {
      perror("Failed to open a state.txt file.");
      _exit(EXIT_FAILURE);
    }

    // Read the current value from the file
    if (read(storage, value, 2) == -1) {
      perror("Failed to read the data from the file.");
      _exit(EXIT_FAILURE);
    }

    // Close the file storage
    close_storage(storage);

    // Simulate delay
    sleep(random_number(1, 3));

    // Increment
    number = atoi(value);
    number++;

    // Convert int to char *
    if (sprintf(value, "%d", number) < 0) {
      perror("Failed to convert int to char *.");
      _exit(EXIT_FAILURE);
    }

    // Open the file in writeonly mode
    storage = open(argv[1], O_WRONLY);
    if (storage == -1) {
      perror("Failed to open a state.txt file.");
      _exit(EXIT_FAILURE);
    }

    // Write the current value to the file
    if (write(storage, value, 2) == -1) {
      perror("Failed to write the data to the file.");
      _exit(EXIT_FAILURE);
    }

    // Close the file storage
    close_storage(storage);

    // *** PRIVATE SECTION AFTER CRITICAL SECTION ****
    printf("[PRIVATE SECTION AFTER CRITICAL SECTION OF %d]\n", getpid());

    // Print the current semaphore's value
    printf("Current semaphore's value: %d\n", semaphore_value(sem));
  }

  semaphore_close(sem);

  return 0;
}
