#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line/*.c
// gcc -D BUFFER_SIZE=42 main.c get_next_line/*.c

int main(){

	int	fd;
	char *s;
	// char *buff;

	// buff = malloc(BUFFER_SIZE * sizeof(char));
	fd = open("./prueba.txt", O_RDONLY);
	// read(fd, buff, BUFFER_SIZE);
	// printf("%s\n", buff);
	// read(fd, buff, BUFFER_SIZE);
	// printf("%c", *(buff + 5));
	// read(fd, buff, BUFFER_SIZE);
	// s = get_next_line(fd);

	// while (s)
	// {
	// 	printf("%s", s);
	// 	s = get_next_line(fd);
	// }
	// printf("%s", s);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// ft_strjoin(NULL, "algo");
	// printf("%s", get_next_line(fd));



}