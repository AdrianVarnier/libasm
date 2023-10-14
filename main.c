#include "libasm.h"

int main()
{
    //strlen
    char s1[] = "Hello World!";
    char s2[] = "I love ASM";

    printf("ft_strlen:\n%ld\n", ft_strlen(s1));
    printf("strlen:   \n%ld\n", strlen(s1));
    printf("\n");

    //strcmp
    printf("ft_strcmp s1 = s2: %d\n", ft_strcmp(s1, s1));
    printf("strcmp    s1 = s2: %d\n", strcmp(s1, s1));
    printf("\n");
    printf("ft_strcmp s1 > s2: %d\n", ft_strcmp(s1, s2));
    printf("strcmp    s1 > s2: %d\n", strcmp(s1, s2));
    printf("\n");
    printf("ft_strcmp s1 < s2: %d\n", ft_strcmp(s2, s1));
    printf("strcmp    s1 < s2: %d\n", strcmp(s2, s1));
    printf("\n");

    //strcpy
    char dst1[] = "insert a name";
    char dst2[] = "insert a name";
    char src[] = "ADRIAN";

    printf("ft_strcpy: %s\n", ft_strcpy(dst1, src));
    printf("strcpy:    %s\n", strcpy(dst2, src));
    printf("\n");

    //strdup
    char* dup1 = ft_strdup(s1);
    char* dup2 = strdup(s1);

    printf("ft_strdup: %s\n", dup1);
    printf("strdup:    %s\n", dup2);
    free(dup1);
    free(dup2);
    printf("\n");

    //read
    char buff[14];
    buff[13] = '\0';

    int fd = open("ft_strlen.s", O_RDONLY);
    printf("ft_read: %zd, %s\n", ft_read(fd, buff, 13), buff);
    close(fd);
    fd = open("ft_strlen.s", O_RDONLY);
    printf("read:    %zd, %s\n", read(fd, buff, 13), buff);
    close(fd);
    printf("\n");
    fd = -1;
    printf("ft_read: %zd", ft_read(fd, buff, 13));
    printf(", %d\n", errno);
    printf("read:    %zd", read(fd, buff, 13));
    printf(", %d\n", errno);
    printf("\n");

    //write
    ssize_t ret;
    write(1, &"ft_write: ", strlen("ft_write: "));
    ret = ft_write(1, &s1, strlen(s1));
    printf(", %zd\n", ret);
    write(1, &"ft_write: ", strlen("ft_write: "));
    ret = write(1, &s1, strlen(s1));
    printf(", %zd\n", ret);
    printf("\n");
    write(1, &"ft_write: ", strlen("ft_write: "));
    ret = ft_write(1, &"c", 1);
    printf(", %zd\n", ret);
    write(1, &"write:    ", strlen("ft_write: "));
    ret = write(1, &"c", 1);
    printf(", %zd\n", ret);
    printf("\n");
    fd = -1;
    ret = ft_write(fd, &"c", 1);
    printf("ft_write: %zd, %d\n", ret, errno);
    ret = write(fd, &"c", 1);
    printf("write:    %zd, %d\n", ret, errno);
    printf("\n");

    return (0);
}