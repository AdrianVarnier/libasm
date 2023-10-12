#include "libasm.h"
#include <stdio.h>

int main()
{
    char s1[] = "Hello World!";
    char s2[] = "I love ASM";
    //strlen
    printf("_ft_strlen:\n%ld\n", _ft_strlen(s1));
    printf("strlen:\n%ld\n", strlen(s1));
    printf("\n");

    //strcmp
    printf("_ft_strcmp s1 = s2:\n%d\n", _ft_strcmp(s1, s1));
    printf("strcmp s1 = s2:\n%d\n", strcmp(s1, s1));
    printf("\n");

    printf("_ft_strcmp s1 > s2:\n%d\n", _ft_strcmp(s1, s2));
    printf("strcmp s1 > s2:\n%d\n", strcmp(s1, s2));
    printf("\n");

    printf("_ft_strcmp s1 < s2:\n%d\n", _ft_strcmp(s2, s1));
    printf("strcmp s1 < s2:\n%d\n", strcmp(s2, s1));
    printf("\n");

    //strcpy
    char dst1[] = "insert a name";
    char dst2[] = "insert a name";
    char src[] = "ADRIAN";
    printf("_ft_strcpy:\n%s\n", _ft_strcpy(dst1, src));
    printf("strcpy:\n%s\n", strcpy(dst2, src));

    char* dup1 = _ft_strdup(s1);
    char* dup2 = strdup(s1);

    printf("ft_strdup:\n%s\n", dup1);
    printf("strdup:\n%s\n", dup2);
    free(dup1);
    free(dup2);

    return (0);
}