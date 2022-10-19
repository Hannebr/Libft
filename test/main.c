#include "libft.h"
#include <stdio.h>

int main(void)
{
    int n = 42;
    t_list *node = ft_lstnew(&n);
    node->next = ft_lstnew("23");
    t_list *last = ft_lstlast(node);
    printf("last node = %s\n", last->content);
}