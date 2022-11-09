#include "./push_swap/push_swap.h"
#include <fcntl.h>

int main(){

    // int fd = open("./prueba.txt", O_RDONLY);

    int nums[6] = {0, 1, 2, 3, 4, 5};
    int i = 0;
    t_list  *stack;
    

    while (i < 6)
    {
        ft_lstadd_back(&stack, ft_lstnew(nums + i));
        i++;
    }
    ft_print_stk(stack);
    ft_printf("\n");

    swap(&stack);
    ft_print_stk(stack);

}