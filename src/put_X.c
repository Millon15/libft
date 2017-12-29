
#include "../ft_printf.h"

char	*ft_itoa_base_big(unsigned int value, int base)
{
	int		j;
	long	b;
	char	*res;

	if (base > 16 || base < 2)
		return (0);
	j = 1;
	b = base;
	while (value / b && ++j)
		b *= base;
	b = value;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value == 0)
		res[0] = '0';
	while (b)
	{
		res[j--] = "0123456789ABCDEF"[b % base];
		b /= base;
	}
	return (res);
}

int		put_X(unsigned int n)
{
	char	*h;
	int		k;

	h = ft_itoa_base_big(n, 16);
	k = ft_putstr(h);
	free(h);
	return (k);
}
