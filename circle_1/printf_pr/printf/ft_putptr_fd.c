

#include "ft_printf.h"
#include <stdio.h>

static void	ft_base_change(long int i, int fd, int capital)
{
	char	*base;
	int		len;

	if (capital)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 16;
	if (i > len)
		ft_base_change(i / len, fd, capital);
	write(1, &base[i % len], 1);
	
}

void    ft_putptr_fd(void *ptr, int fd, int capital, int prefix)
{
	long int	p;
	p = (long int) ptr;
	if (prefix)
		write(fd, "0x", 2);
	ft_base_change(p, fd, capital);
}