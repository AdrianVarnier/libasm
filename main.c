#include "libasm.h"
#include <stdio.h>

int main()
{
    char s1[] = "Hello World!";
    char s2[] = "I love ASM";
    //strlen
    printf("ft_strlen:\n%ld\n", ft_strlen(s1));
    printf("strlen:\n%ld\n", strlen(s1));
    printf("\n");

    //strcmp
    printf("ft_strcmp s1 = s2:\n%d\n", ft_strcmp(s1, s1));
    printf("strcmp s1 = s2:\n%d\n", strcmp(s1, s1));
    printf("\n");

    printf("ft_strcmp s1 > s2:\n%d\n", ft_strcmp(s1, s2));
    printf("strcmp s1 > s2:\n%d\n", strcmp(s1, s2));
    printf("\n");

    printf("ft_strcmp s1 < s2:\n%d\n", ft_strcmp(s2, s1));
    printf("strcmp s1 < s2:\n%d\n", strcmp(s2, s1));
    printf("\n");

    //strcpy
    char dst1[] = "je vais bientot disparaitre";
    char dst2[] = "je vais bientot disparaitre";
    char src[] = "ADRIAN";
    printf("ft_strcpy:\n%s\n", ft_strcpy(dst1, src));
    printf("strcpy:\n%s\n", strcpy(dst2, src));
    return (0);
}