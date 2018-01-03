/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/03 19:43:01 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void		print_fl(t_flags **fl)
// {
// 	printf("\nSTART ::\n\n");
// 	printf("plus = %d\n", (*fl)->plus);
// 	printf("minus = %d\n", (*fl)->minus);
// 	printf("space = %d\n", (*fl)->space);
// 	printf("hesh = %d\n", (*fl)->hesh);
// 	printf("zero = %d\n", (*fl)->zero);
// 	printf("hh = %d\n", (*fl)->hh);
// 	printf("h = %d\n", (*fl)->h);
// 	printf("l = %d\n", (*fl)->l);
// 	printf("ll = %d\n", (*fl)->ll);
// 	printf("j = %d\n", (*fl)->j);
// 	printf("z = %d\n", (*fl)->z);
// 	printf("t = %d\n", (*fl)->t);
// 	printf("L = %d\n", (*fl)->L);
// 	printf("min_lenth = %d\n", (*fl)->min_lenth);
// 	printf("precision = %d\n", (*fl)->precision);
// }

void		fill_zr(t_flags **fl)
{
	(*fl)->plus = 0;
	(*fl)->minus = 0;
	(*fl)->space = 0;
	(*fl)->hesh = 0;
	(*fl)->zero = 0;
	(*fl)->hh = 0;
	(*fl)->h = 0;
	(*fl)->l = 0;
	(*fl)->ll = 0;
	(*fl)->j = 0;
	(*fl)->z = 0;
	(*fl)->t = 0;
	(*fl)->L = 0;
	(*fl)->min_lenth = 0;
	(*fl)->precision = 0;
}

void	fill_mlpr_and_ln(const char *s, size_t *i, t_flags *fl)
{
	while (s[*i] && (s[*i] >= '1' && s[*i] <= '9'))
		fl->min_lenth = fl->min_lenth * 10 + s[(*i)++] - '0';
	if (s[*i] && s[*i] == '.' && (*i)++)
		while (s[*i] && (s[*i] >= '1' && s[*i] <= '9'))
			fl->precision = fl->precision * 10 + s[(*i)++] - '0';
	while (s[*i] && (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'L' ||
	s[*i] == 't' || s[*i] == 'j' || s[*i] == 'z' ||
	(s[*i] == 'h' && s[*i + 1] == 'h') || (s[*i] == 'l' && s[*i + 1] == 'l')))
	{
		if (s[*i] == 'l')
			fl->l = 1;
		if (s[*i] == 'h')
			fl->h = 1;
		if (s[*i] == 't')
			fl->t = 1;
		if (s[*i] == 'j')
			fl->j = 1;
		if (s[*i] == 'z')
			fl->z = 1;
		if (s[*i] == 'L')
			fl->L = 1;
		if (s[*i] == 'h' && s[*i + 1] == 'h')
			fl->hh = 1;
		if (s[*i] == 'l' && s[*i + 1] == 'l')
			fl->ll = 1;
		(*i)++;
	}
}

t_flags		*findconvchr(const char *s, size_t *i)
{
	t_flags		*fl;

	fl = (t_flags *)malloc(sizeof(t_flags));
	fill_zr(&fl);
	while (s[*i] && (s[*i] == ' ' || s[*i] == '0' ||
	s[*i] == '#' || s[*i] == '+' || s[*i] == '-'))
	{
		if (s[*i] == '+')
			fl->plus = 1;
		if (s[*i] == '-')
			fl->minus = 1;
		if (s[*i] == '0')
			fl->zero = 1;
		if (s[*i] == '#')
			fl->hesh = 1;
		if (s[*i] == ' ')
			fl->space = 1;
		(*i)++;
	}
	fill_mlpr_and_ln(s, i, fl);
	return (fl);
}

int			findsubstr(const char *s, size_t *i, va_list ap)
{
	t_flags		*fl;

	++(*i);
	if (s[*i] == '%' || s[*i] == 'c')
		return (ft_putchar(s[*i]));
	fl = findconvchr(s, i);
	if (s[*i] == 's')
		return (ft_putstr(va_arg(ap, const char *)));
	if (s[*i] == 'S')
		return (ft_putstr("%S"));
	if (s[*i] == 'i')
		return (put_d(va_arg(ap, int)));
	if (s[*i] == 'd')
		return (put_d(va_arg(ap, int)));
	if (s[*i] == 'D')
		return (ft_putstr("%D"));
	if (s[*i] == 'o')
		return (put_o(va_arg(ap, unsigned int)));
	if (s[*i] == 'u')
		return (put_u(va_arg(ap, unsigned int)));
	if (s[*i] == 'x')
		return (put_x(va_arg(ap, unsigned int)));
	if (s[*i] == 'X')
		return (put_big_x(va_arg(ap, unsigned int)));
	return (0);
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

	k1 = ft_printf("%+ -012.3ls\n", "kndlkbnfgbklngbknfgkn");
	k2 = ft_printf("%+-s\n", "kndlkbnfgbklngbknfgkn");
	printf("k1 = %d and k2 = %d\n", k1, k2);
	return (0);
}
