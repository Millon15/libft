
#include "../ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char	*buf;
	long	i;
	short	j;

	i = 10;
	j = 1;
	while (n / i > 0 && ++j)
		i *= 10;
	buf = (char *)malloc(sizeof(char) * j);
	if (buf == NULL)
		return (NULL);
	j = 0;
	while ((i /= 10) > 0)
		buf[j++] = (n / i) % 10 + '0';
	buf[j] = '\0';
	return (buf);
}

int put_u(unsigned int n)
{
	char *h;
	int k;

	h = ft_utoa(n);
	k = ft_putstr(h);
	free(h);
	return (k);
}
