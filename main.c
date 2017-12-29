
#include "ft_printf.h"

int		findsubstr(const char *s, size_t i, va_list ap)
{
	if (s[i] == '%' || s[i] == 'c')
		return (putchar(s[i]));
	if (s[i] == 's')
		return (put_s(va_arg(ap, const char *)));
	if (s[i] == 'S')
		return (ft_putstr("%S"));
	if (s[i] == 'i')
		return (put_d(va_arg(ap, int)));
	if (s[i] == 'd')
		return (put_d(va_arg(ap, int)));
	if (s[i] == 'D')
		return (ft_putstr("%D"));
	if (s[i] == 'o')
		return (put_o(va_arg(ap, unsigned int)));
	if (s[i] == 'u')
		return (put_u(va_arg(ap, unsigned int)));
	if (s[i] == 'x')
		return (put_x(va_arg(ap, unsigned int)));
	if (s[i] == 'X')
		return (put_X(va_arg(ap, unsigned int)));
}

int			ft_printf(const char *s, ...)
{
	int			k;
	size_t		i;
	va_list		ap;

	i = 0;
	k = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			k += findsubstr(s, ++i, ap);
			i++;
		}
		else
		{
			write(1, &s[i++], 1);
			k++;
		}
	}
	va_end(ap);
	return (k);
}

int			main(void)
{
	int		k1;
	int		k2;

	k1 = ft_printf("yyguy %i\n%d\n%u\n%x\n%X\n%o\nijiji\n\n", 123, 999, 999, 999, 999, 999);
	k2 = printf("yyguy %i\n%d\n%u\n%x\n%X\n%o\nijiji\n\n", 123, 999, 999, 999, 999, 999);
	printf("%lugbfg\n\n", 12789858723);
	printf("k1 = %d\nk2 = %d\n", k1, k2);
	return (0);
}
