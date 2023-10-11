#include "libasm.h"
#include <stdio.h>

int main()
{
    char s1[] = "Hello World!";
    char s2[] = "I love ASM";
    //strlen
    printf("ft_strlen:\n%ld\n", _ft_strlen(s1));
    printf("strlen:\n%ld\n", strlen(s1));
    printf("\n");

    //strcmp
    printf("ft_strcmp s1 = s2:\n%d\n", _ft_strcmp(s1, s1));
    printf("strcmp s1 = s2:\n%d\n", strcmp(s1, s1));
    printf("\n");

    printf("ft_strcmp s1 > s2:\n%d\n", _ft_strcmp(s1, s2));
    printf("strcmp s1 > s2:\n%d\n", strcmp(s1, s2));
    printf("\n");

    printf("ft_strcmp s1 < s2:\n%d\n", _ft_strcmp(s2, s1));
    printf("strcmp s1 < s2:\n%d\n", strcmp(s2, s1));
    printf("\n");

    //strcpy
    char ft_dst[] = "insert a ete remplacer par un clone";
    char ft_src[] = "Adrian";
    char dst[] = "je vais bientot disparaitre";
    char src[] = "";
    printf("ft_strcpy:\n%s\n%s\n%s\n", _ft_strcpy(dst, src), ft_dst, ft_src);
    printf("strcpy:\n%s\n%s\n%s\n", strcpy(dst, src), dst, src);
    return (0);
}