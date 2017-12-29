
#include "../ft_printf.h"

int		put_d(int n)
{
	char	*h;
	int		k;

	h = ft_itoa(n);
	k = ft_putstr(h);
	free(h);
	return (k);
}
