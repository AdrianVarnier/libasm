#include "libasm_bonus.h"

int main()
{
    t_list  *l1 = NULL;
    t_list  *l2 = NULL;
    char    data1[] = "content number three";
    char    data2[] = "content number two";
    char    data3[] = "content number one";
    ft_list_push_front(&l1, data1);
    ft_list_push_front(&l1, data2);
    ft_list_push_front(&l1, data3);

    //ft_list_size
    printf("ft_list_size: %d\n", ft_list_size(l1));
    printf("ft_list_size: %d\n", ft_list_size(l2));
    printf("\n");

    //ft_list_push_front
    printf("ft_list_push_front:\n");
    printf("%s\n", (char *)l1->data);
    printf("%s\n", (char *)l1->next->data);
    printf("%s\n", (char *)l1->next->next->data);
    printf("\n");

    return (0);
}