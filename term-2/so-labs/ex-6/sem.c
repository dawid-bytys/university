#include "sem.h"
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

sem_id semaphore_create(const char *name, int value) {
  printf("Creating a new semaphore...\n");

  sem_t *sem = sem_open(name, O_CREAT | O_EXCL, 0666, value);
  if (sem == SEM_FAILED) {
    perror("Failed to create a new semaphore.");
    exit(EXIT_FAILURE);
  }

  return sem;
}

sem_id semaphore_open(const char *name, int value) {
  printf("Opening the semaphore...\n");

  sem_t *sem = sem_open(name, value);
  if (sem == SEM_FAILED) {
    perror("Failed to open the semaphore.");
    exit(EXIT_FAILURE);
  }

  return sem;
}

int semaphore_value(sem_id sem) {
  int sem_value;

  if (sem_getvalue(sem, &sem_value) == -1) {
    perror("Failed to retrieve the sempahore's value.");
    exit(EXIT_FAILURE);
  }

  return sem_value;
}

void semaphore_close(sem_id sem) {
  printf("Closing the semaphore...\n");

  if (sem_close(sem) == -1) {
    perror("Failed to close the semaphore.");
    exit(EXIT_FAILURE);
  }

  printf("The semaphore has been closed.\n");
}

void semaphore_drop(sem_id sem) {
  printf("Dropping the semaphore...\n");

  if (sem_wait(sem) == -1) {
    perror("Failed to drop the semaphore.");
    exit(EXIT_FAILURE);
  }

  printf("The semaphore has been successfully dropped.\n");
}

void semaphore_lift(sem_id sem) {
  printf("Lifting the semaphore...\n");

  if (sem_post(sem) == -1) {
    perror("Failed to lift the semaphore.");
    exit(EXIT_FAILURE);
  }

  printf("The semaphore has been successfully lifted.\n");
}

void semaphore_delete(const char *name) {
  printf("Deleting the semaphore...\n");

  if (sem_unlink(name) == -1) {
    perror("Failed to delete the semaphore.");
    exit(EXIT_FAILURE);
  }

  printf("The semaphore has been successfully deleted.\n");
}
