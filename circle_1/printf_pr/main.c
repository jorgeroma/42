
// gcc main.c printf/*.c printf/libft/*.c && ./a.out

#include "printf/ft_printf.h"
#include <stdio.h>

int main()
{
	double a = 77;
		// int i = ft_printf("a%      i\n",221);
		int i = ft_printf(">% c, >% s, >% p, >% d, >% i, >% u, >% x, >% X, >% %\n",65, "asd", &"dss", 23, 11, 123, 0x213, 0x213);
		int j =    printf(">% c, >% s, >% p, >% d, >% i, >% u, >% x, >% X, >% %\n",65, "asd", &"dss", 23, 11, 123, 0x213, 0x213);
		//cspdiuxX%
		// int i = ft_printf(">%%asd\n",123);
		// int j =    printf(">%%asd\n",123);
		// int i = ft_printf("123\n");
		// int i = printf("123%      d\n", 13);
		printf("%d, %d", i, j);
		// ft_printf("\x01\x02\x07\v\x08\f\r\n");
		// ft_printf("%c", 'x');
	// printf("%d", ft_printf("%d", 7));
}
