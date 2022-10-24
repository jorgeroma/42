#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line/*.c && ./a.out
// gcc -D BUFFER_SIZE=42 main.c get_next_line/*.c && ./a.out
// valgrind --tool=memcheck --leak-check=yes ./a.out 
// valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./a.out

// void check_leaks();

void prueba()
{
	system("leaks a.out");
}

int main(){

	int	fd;
	// char *s;
	
	// fd = open("./prueba.txt", O_RDONLY);
	// char *buff;
	// buff = malloc(BUFFER_SIZE * sizeof(char));
	// read(fd, buff, BUFFER_SIZE);
	// printf(">%s", buff);
	// read(fd, buff, BUFFER_SIZE);
	// printf("?%s", buff);
	
	// buff = ft_strjoin(buff, "Algo");
	// free(buff);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);

	// char *p;
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);
	// p = get_next_line(fd);
	// printf("%s", p);
	// free(p);

	// printf("%d\n", fd);
	fd = open("./prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	fd = open("./prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));


	// atexit(prueba);
}