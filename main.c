// gcc main.c libft/*.c && ./a.out
// gcc -Wall -Werror -Wextra main.c libft/*.c && ./a.out

#include <stdio.h>
#include "./libft/libft.h"
#include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

int main(){
	// char a[] = "Hola que tal,jb ,jhvmhgvmg";
	// char b[] = ";ajbsdj";
	// char a[] = "	 \n \t  -2147483649";
	// printf("%d\n", atoi(a));
	// char *a = (char *)ft_calloc(0, sizeof(char));
	// char *b = ft_strdup(a);
	// char *s1 = "lorem \n ipsum \t dolor \n sit \t amet";
 	// printf("%s\n", ft_strtrim(s1, " "));
	// ft_putnbr_fd(-21473648, 1);
	// ft_putendl_fd("hola que tal", 1);
	// ft_putendl_fd("hola que tal", 1);
	char b[] = "que tal tal ";
	char **a = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
		// printf("%s\n", a[1]);
	int i = 0;
	while (a[i] != NULL)
	{
		printf("%s\n", a[i]);
		i++;
	}
	
}