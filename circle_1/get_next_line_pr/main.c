#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line/*.c && ./a.out
// gcc -D BUFFER_SIZE=42 main.c get_next_line/*.c && ./a.out

// void check_leaks();

int main(){

	int	fd;
	// char *s;
	
	// char *buff;
	// buff = malloc(BUFFER_SIZE * sizeof(char));
	fd = open("./prueba.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


	// check_leaks();
}