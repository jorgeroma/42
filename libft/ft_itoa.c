

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		l++;
		n *= -1;
	}
	while (n > 9)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static void	ft_itoa_rec(int n, char *out, int pos)
{
	if (n > 9)
		ft_itoa_rec(n / 10, out, pos - 1);
	out[pos] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	int		pos;
	int		len;
	char	*out;

	pos = 0;
	len = ft_itoa_len(n);
	if (n == -2147483648)
		return ("-2147483648");
	out = calloc(1 + len, sizeof(int));
	if (!out)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		pos++;
		n *= -1; 
	}

	ft_itoa_rec(n, out, len - 1);

	return (out);
}