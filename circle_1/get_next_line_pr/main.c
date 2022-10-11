#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line/*.c
// gcc -D BUFFER_SIZE=42 main.c get_next_line/*.c

int main(){

	int	fd;
	
	fd = open("./prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%d", ft_search("asf\n", '\n'));



}