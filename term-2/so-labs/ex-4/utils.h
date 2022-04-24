#pragma once
#ifndef UTILS_H
#define UTILS_H

void producer(int file_desc, const char *file, int buffer_size);
void consumer(int file_desc, const char *file, int buffer_size);
unsigned random_number(unsigned min, unsigned max);

#endif
