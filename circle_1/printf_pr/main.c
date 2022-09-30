
// gcc main.c printf/*.c printf/libft/*.c && ./a.out

#include "printf/libftprintf.h"
#include <stdio.h>

int main()
{
	double a = 77;
	ft_printf("%p %d, %d\n", &a, 0x123, 0123);
	printf("\n%p %i %%\n", &a, 0123);
	// printf("%d", ft_printf("%d", 7));
}
