#ifndef LIBASM_H
#define LIBASM_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

ssize_t _ft_strlen(const char* s);
int     _ft_strcmp(const char* s1, const char* s2);
char*   _ft_strcpy(char* dest, const char* src);
char*   _ft_strdup(const char* s);

#endif