#include "libasm_bonus.h"

void    print_list(t_list* l)
{
    if (l == NULL)
        printf("list is empty\n");
    while (l != NULL)
    {
        printf("%s\n", (char *)l->data);
        l = l->next;
    }
    return;
}

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
    print_list(l1);
    printf("\n");

    //ft_list_sort
    ft_list_sort(&l2, (*ft_strcmp));
    ft_list_sort(&l1, NULL);
    printf("ft_list_sort cmp = null:\n");
    print_list(l1);
    printf("\n");
    ft_list_sort(&l1, (*ft_strcmp));
    printf("ft_list_sort unordered list:\n");
    print_list(l1);
    printf("\n");
    ft_list_sort(&l1, (*ft_strcmp));
    printf("ft_list_sort ordered list:\n");
    print_list(l1);
    printf("\n");

    //ft_list_remove_if
    printf("ft_list_remove_if double element:\n");
    ft_list_remove_if(&l1, "content 2", (*strcmp), (*free));
    print_list(l1);
    printf("\n");
    printf("ft_list_remove_if first element:\n");
    ft_list_remove_if(&l1, "content 1", (*strcmp), (*free));
    print_list(l1);
    printf("\n");
    printf("ft_list_remove_if last element:\n");
    ft_list_remove_if(&l1, "content 4", (*strcmp), (*free));
    ft_list_remove_if(&l1, "content 3", (*strcmp), (*free));
    print_list(l1);
    printf("\n");

    //ft_atoi_base
    // char s1[] = "+2";
    // char *s2 = NULL;
    // char s3[] = "-2";
    // char b1[] = "01";
    // char *b2 = NULL;
    // char b3[] = "1";
    // char b4[] = "11";
    // printf("%d\n", ft_atoi_base(s2, b1));
    // printf("%d\n", ft_atoi_base(s1, b2));
    // printf("%d\n", ft_atoi_base(s1, b3));
    char s1[] = "abcd";
    char s2[] = "abccd";
    char s3[] = "abcdd";
    char s4[] = "aabcd";
    printf("%d\n", ft_str_check_dup(s1));
    printf("%d\n", ft_str_check_dup(s2));
    printf("%d\n", ft_str_check_dup(s3));
    printf("%d\n", ft_str_check_dup(s4));
    return (0);
}