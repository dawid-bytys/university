#pragma once
#ifndef SEM_H
#define SEM_H

#include <semaphore.h>

typedef sem_t *sem_id;

sem_id semaphore_create(const char *name, int value);
sem_id semaphore_open(const char *name, int value);
int semaphore_value(sem_id sem);
void semaphore_close(sem_id sem);
void semaphore_drop(sem_id sem);
void semaphore_lift(sem_id sem);
void semaphore_delete(const char *name);

#endif
