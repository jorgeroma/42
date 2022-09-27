// gcc main.c libft/*.c && ./a.out
// gcc -Wall -Werror -Wextra main.c libft/*.c && ./a.out

#include <stdio.h>
#include "./libft/libft.h"
#include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

void ft_algop(unsigned int i, char *c)
{
	*c = *c + i;
}

int main(){
	char a[] = "";
	// char b[] = ";ajbsdj";
	// char a[] = "	 \n \t  -2147483649";
	// printf("%d\n", atoi(a));
	// char *a = (char *)ft_calloc(0, sizeof(char));
	// char *b = ft_strdup(a);
	ft_striteri(a, ft_algop);
	
	// printf("%s\n", ft_itoa(-21483647));
	// printf("%s.\n", ft_strtrim("", ""));
	// ft_putnbr_fd(-21473648, 1);
	// ft_putendl_fd("hola que tal", 1);
	// ft_putendl_fd("hola que tal", 1);
		// printf("%s\n", a[1]);
	
}