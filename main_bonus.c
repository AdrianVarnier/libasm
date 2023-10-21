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
    char *s = NULL;
    char s1[] = "101";
    char s2[] = "+101";
    char s3[] = "--101";
    char s4[] = "-101";
    char s5[] = "-+101";
    char s6[] = "+-101";
    char s7[] = "101z";
    char s8[] = "z101";

    char *b = NULL;
    char b1[] = "0123456789";
    char b2[] = "01";
    char b3[] = "0123456789abcdef";
    char b4[] = "1 2";
    char b5[] = "1+2";
    char b6[] = "1-2";
    char b7[] = "1";
    char b8[] = "112";

    printf("ft_atoi_base (error):\n");
    printf("s = null:   %d\n", ft_atoi_base(s, b1));
    printf("b = null:   %d\n", ft_atoi_base(s1, b));
    printf("b = \"1 2\":  %d\n", ft_atoi_base(s1, b4));
    printf("b = '+':    %d\n", ft_atoi_base(s1, b5));
    printf("b = '-':    %d\n", ft_atoi_base(s1, b6));
    printf("len(b) = 1: %d\n", ft_atoi_base(s1, b7));
    printf("b = dup:    %d\n", ft_atoi_base(s1, b8));
    printf("\n");
    //101
    printf("ft_atoi_base (\"0123456789\"):\n");
    printf("s = \"101\":   %d\n", ft_atoi_base(s1, b1));
    printf("s = \"+101\":  %d\n", ft_atoi_base(s2, b1));
    printf("s = \"--101\": %d\n", ft_atoi_base(s3, b1));
    printf("s = \"-101\":  %d\n", ft_atoi_base(s4, b1));
    printf("s = \"-+101\": %d\n", ft_atoi_base(s5, b1));
    printf("s = \"+-101\": %d\n", ft_atoi_base(s6, b1));
    printf("s = \"101z\":  %d\n", ft_atoi_base(s7, b1));
    printf("s = \"z101\":  %d\n", ft_atoi_base(s8, b1));
    printf("\n");
    //5
    printf("ft_atoi_base (\"01\"):\n");
    printf("s = \"101\":   %d\n", ft_atoi_base(s1, b2));
    printf("s = \"+101\":  %d\n", ft_atoi_base(s2, b2));
    printf("s = \"--101\": %d\n", ft_atoi_base(s3, b2));
    printf("s = \"-101\":  %d\n", ft_atoi_base(s4, b2));
    printf("s = \"-+101\": %d\n", ft_atoi_base(s5, b2));
    printf("s = \"+-101\": %d\n", ft_atoi_base(s6, b2));
    printf("s = \"101z\":  %d\n", ft_atoi_base(s7, b2));
    printf("s = \"z101\":  %d\n", ft_atoi_base(s8, b2));
    printf("\n");
    //257
    printf("ft_atoi_base (\"0123456789abcdef\"):\n");
    printf("s = \"101\":   %d\n", ft_atoi_base(s1, b3));
    printf("s = \"+101\":  %d\n", ft_atoi_base(s2, b3));
    printf("s = \"--101\": %d\n", ft_atoi_base(s3, b3));
    printf("s = \"-101\":  %d\n", ft_atoi_base(s4, b3));
    printf("s = \"-+101\": %d\n", ft_atoi_base(s5, b3));
    printf("s = \"+-101\": %d\n", ft_atoi_base(s6, b3));
    printf("s = \"101z\":  %d\n", ft_atoi_base(s7, b3));
    printf("s = \"z101\":  %d\n", ft_atoi_base(s8, b3));
    printf("\n");

    return (0);
}