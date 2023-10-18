#include "libasm_bonus.h"

int main()
{
    t_list  *l1 = NULL;
    t_list  *l2 = NULL;
    char    data1[] = "content 1";
    char    data2[] = "content 2";
    char    data3[] = "content 3";
    char    data4[] = "content 2";
    char    data5[] = "content 4";
    ft_list_push_front(&l1, data1);
    ft_list_push_front(&l1, data2);
    ft_list_push_front(&l1, data3);
    ft_list_push_front(&l1, data4);
    ft_list_push_front(&l1, data5);

    //ft_list_size
    printf("ft_list_size list = 5 elements: %d\n", ft_list_size(l1));
    printf("ft_list_size list = null: %d\n", ft_list_size(l2));
    printf("\n");

    //ft_list_push_front
    printf("ft_list_push_front 1, 2, 3, 2, 4:\n");
    printf("%s\n", (char *)l1->data);
    printf("%s\n", (char *)l1->next->data);
    printf("%s\n", (char *)l1->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->next->data);
    printf("\n");

    //ft_list_sort
    ft_list_sort(&l2, (*ft_strcmp));
    ft_list_sort(&l1, NULL);
    printf("ft_list_sort cmp = null:\n");
    printf("%s\n", (char *)l1->data);
    printf("%s\n", (char *)l1->next->data);
    printf("%s\n", (char *)l1->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->next->data);
    printf("\n");
    ft_list_sort(&l1, (*ft_strcmp));
    printf("ft_list_sort unordered list:\n");
    printf("%s\n", (char *)l1->data);
    printf("%s\n", (char *)l1->next->data);
    printf("%s\n", (char *)l1->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->next->data);
    printf("\n");
    ft_list_sort(&l1, (*ft_strcmp));
    printf("ft_list_sort ordered list:\n");
    printf("%s\n", (char *)l1->data);
    printf("%s\n", (char *)l1->next->data);
    printf("%s\n", (char *)l1->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->data);
    printf("%s\n", (char *)l1->next->next->next->next->data);
    printf("\n");

    return (0);
}