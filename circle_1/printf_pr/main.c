
// gcc main.c printf/*.c printf/libft/*.c && ./a.out

#include "printf/ft_printf.h"
#include <stdio.h>

int main()
{
	double a = 77;
		int i = ft_printf("a%      d, %da\n",221,2);
		int j =    printf("a%      d, %da\n",221,2);
		// int i = ft_printf("123\n");
		// int i = printf("123%      d\n", 13);
		printf("%d, %d", i, j);
		// ft_printf("\x01\x02\x07\v\x08\f\r\n");
		// ft_printf("%c", 'x');
	// printf("%d", ft_printf("%d", 7));
}
