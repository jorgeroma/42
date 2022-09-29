
// gcc main.c printf/*.c printf/libft/*.c && ./a.out

#include "printf/libftprintf.h"
#include <stdio.h>

int main()
{
	ft_printf("Hola esto es: %    d, y esto una letra: %c\nEsto una cadena: %s\n", 7, 'j', "abc");
	printf("%d %i\n", 1.23, 1.2);
	// printf("%d", ft_printf("%d", 7));
}
