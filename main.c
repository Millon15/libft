/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/03 15:57:00 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*findconvchr(const char *s, size_t *l)
{
	size_t		i;
	size_t		j;
	char		*fl;

	i = *l;
	while (s[i] && (s[i] != 's' || s[i] != 'd' || s[i] != 'i' ||
	s[i] != 's' || s[i] != 'u' || s[i] != 's' || s[i] != 'x' || s[i] != 'X'))
		i++;
	if (!s[i])
		return (NULL);
	fl = (char *)malloc(sizeof(char) * (i - *l + 2));
	j = 0;
	while (j < i)
		fl[j++] = s[*l++];
	fl[j] = '\0';
	return (fl);
}

int			findsubstr(const char *s, size_t *l, va_list ap)
{
	size_t		i;
	char		*fl;

	i = ++(*l);
	if (s[i] == '%' || s[i] == 'c')
		return (ft_putchar(s[i]));
	if (!(fl = findconvchr(s, l)))
		return (0);
	i = *l;
	if (s[i] == 's')
		return (put_s(va_arg(ap, const char *), fl));
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
			k += findsubstr(s, &i, ap);
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
	return (0);
}
