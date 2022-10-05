
// gcc main.c printf/*.c printf/libft/*.c && ./a.out

#include "printf/ft_printf.h"
#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	long int LONG_MIN = -9223372036854775807;
	long int LONG_MAX = 9223372036854775807;
	double a = 77;
		// int i = ft_printf("a%      i\n",221);
		// int i = ft_printf(">% c, >% s, >% p, >% d, >% i, >% u, >% x, >% X, >% %\n",65, "asd", &"dss", 23, 11, 123, 0x213, 0x213);
		// int j =    printf(">% c, >% s, >% p, >% d, >% i, >% u, >% x, >% X, >% %\n",65, "asd", &"dss", 23, 11, 123, 0x213, 0x213);
		//cspdiuxX%
		//  unsigned int l = -1;
		// long int k = l;
		i = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
		// i = LONG_MAX;
		j =    printf(" %p %p ", LONG_MIN, LONG_MAX);
		// i = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
		// j =    printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
		printf("%d, %d", i, j);
		// ft_printf("\x01\x02\x07\v\x08\f\r\n");
		// ft_printf("%c", 'x');
	// printf("%d", ft_printf("%d", 7));
}
