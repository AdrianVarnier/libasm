#include "libasm.h"
#include <stdio.h>

int main()
{
    char s1[] = "Hello World!";
    char s2[] = "I love ASM";
    printf("ft_strlen:\n%ld\n", _ft_strlen(s1));
    printf("strlen:\n%ld\n", strlen(s1));
    printf("ft_strcmp:\n%d\n", _ft_strcmp(s1, s1));
    printf("strcmp:\n%d\n", strcmp(s1, s1));
    printf("ft_strcmp:\n%d\n", _ft_strcmp(s1, s2));
    printf("strcmp:\n%d\n", strcmp(s1, s2));
    return (0);   
}