
// #include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char	*estoa_base(long value, short base)//, t_flags *fl)
{
	unsigned long	v;
	char			*buf;
	int				i;

	if (base > 16 || base < 2)
		return (0);
	i = 65;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	v = value;
	if (value < 0)
		v = -value;
	buf[i] = '\0';
	while (i != 0)
	{
		// fl->small_x ? (buf[--i] = "0123456789abcdef"[v % base]) :
		buf[--i] = "0123456789ABCDEF"[v % base];
		v /= base;
	}
	// buf[0] = (value < 0 && base == 10) ? '-' :\
	// (value > 0 && fl->plus && base == 10) ? '+' :\
	// (value > 0 && fl->space && base == 10) ? ' ' : '0';
	return (buf);
}

int			main(void)
{
	int		k1;
	int		k2;
	// int		value = 1;
	// int		plus = 0;
	// int		space = 0;
	// char	buf[2];

	k1 = 0;
	k2 = 0;
	// k1 = ft_printf("%i\n", 131132);
	// k2 = printf("%i\n", 131132);
	// printf("k1 = %d and k2 = %d\n", k1, k2);
	// k1 = ft_printf("%100.20i\n", 131132);
	// k2 = printf("%100.20i\n", 131132);
	// printf("k1 = %d and k2 = %d\n", k1, k2);
	// k1 = ft_printf("%0.20i\n", 131132);
	// k2 = printf("%0.20i\n", 131132);
	// printf("k1 = %d and k2 = %d\n", k1, k2);
	// k1 = ft_printf("%100i\n", 131132);
	// k2 = printf("%100i\n", 131132);
	// printf("k1 = %d and k2 = %d\n", k1, k2);
	// k1 = ft_printf("%0100i\n", 131132);
	// k2 = printf("%0100i\n", 131132);
	// printf("k1 = %d and k2 = %d\n", k1, k2);
	// k1 = ft_printf("%0i\n", 131132);
	// k2 = printf("%0i\n", 131132);
	// printf("k1 = %d and k2 = %d\n", k1, k2);
	// k1 = ft_printf("%ld\n", 92233720368547758);
	// k2 = printf("%ld\n", 92233720368547758);
	// printf("k1 = %d and k2 = %d\n", k1, k2);

	// buf[0] = (value < 0) ? '-' : (value > 0 && plus) ? '+' :\
	// (value > 0 && space) ? ' ' : '0';
	// buf[1] = 0;
	// printf("%s\n", buf);

	printf("%s\n", estoa_base(9223372036854775807, 2));
	printf("%lX\n", 9223372036854775807);
	return (0);
}
