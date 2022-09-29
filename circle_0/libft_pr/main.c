// gcc main.c libft/*.c && ./a.out
// gcc -Wall -Werror -Wextra main.c libft/*.c && ./a.out

#include <stdio.h>
#include "./libft/libft.h"
#include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

void	ft_del(void *content)
{
	free(content);
}
void	ft_print_result(t_list *elem)
{
	write(1, elem->content, strlen(elem->content));
}

int main(){
	t_list		*elem;
	t_list		*elem2;
	// t_list		*elem3;
	// t_list		*elem4;
	// char		*str =  ft_strdup("lorem");
	char		*str2 = ft_strdup("ipsum");
	// char		*str3 = ft_strdup("dolor");
	// char		*str4 = ft_strdup("sit");

	elem = ft_lstnew(NULL);
	elem2 = ft_lstnew(str2);
	// elem3 = ft_lstnew(str3);
	// elem4 = ft_lstnew(str4);
	if (!elem || !elem2)
		return (0);
	// elem->next = elem2;
	// elem2->next = elem3;
	// elem3->next = elem4;
	
	ft_lstadd_back(&elem, elem2);
	ft_print_result(elem);
	

}