

#include "libftprintf.h"
#include <stdio.h>

void    ft_putptr_fd(void *ptr, int fd)
{
	long int p;

    p = (long int) ptr;
    printf("\n%d\n", p);
    // ft_putnbr_fd(p, fd);
}