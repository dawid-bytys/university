#ifndef UTILS_H
#define UTILS_H

void execution_error(int arguments);
void wait_process(int processes_count);
void close_storage(int file_desc);
unsigned random_number(unsigned min, unsigned max);
const char *concat(const char *s1, const char *s2);

#endif
