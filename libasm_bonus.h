#ifndef LIBASM_H
#define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

//mandatory
ssize_t ft_strlen(const char* s);
int     ft_strcmp(const char* s1, const char* s2);
char*   ft_strcpy(char* dest, const char* src);
char*   ft_strdup(const char* s);
ssize_t ft_write(int fd, const void* buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

//bonus
typedef struct  s_list
{
    void*           data;
    struct s_list*  next;
}               t_list;

int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
int     ft_list_sort(t_list **begin_list, int (*cmp)());

#endif