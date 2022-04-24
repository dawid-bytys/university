#pragma once
#ifndef UTILS_H
#define UTILS_H

void execution_error(int argc);
void signal_handler(int signal);
const char *concat(const char *s1, const char *s2);
void wait_process(int processes_count);
void state_verification(int processes_count, int critical_sections_count);
void close_storage(int storage);

#endif