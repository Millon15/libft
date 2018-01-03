
#include "ft_printf.h"

char	*ft_itoa_base(int value, int base)
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
	if (value < 0 && (b = -b) && base == 10)
		j++;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value == 0)
		res[0] = '0';
	if (value < 0 && base == 10)
		res[0] = '-';
	while (b)
	{
		res[j--] = "0123456789ABCDEF"[b % base];
		b /= base;
	}
	return (res);
}

int		ft_putchar(int c)
{
	return ((int)write(1, &c, 1));
}

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putstr(const char *s)
{
	return ((int)write(1, s, ft_strlen(s)));
}
