/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/06 15:51:04 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_zr(t_flags **fl)
{
	(*fl)->small_x = 0;
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
	(*fl)->precs_spec = 0;
	(*fl)->precision = 0;
	(*fl)->min_lenth = 0;
}

void		fill_lenthmod(const char *s, size_t *i, t_flags *fl)
{
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

t_flags		*fill_flags(const char *s, size_t *i, t_flags *fl)
{
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
	while (s[*i] && (s[*i] >= '0' && s[*i] <= '9'))
		fl->min_lenth = fl->min_lenth * 10 + s[(*i)++] - '0';
	if (s[*i] && s[*i] == '.' && (*i)++ && (fl->precs_spec = 1))
		while (s[*i] && (s[*i] >= '0' && s[*i] <= '9'))
			fl->precision = fl->precision * 10 + s[(*i)++] - '0';
	fill_lenthmod(s, i, fl);
	return (fl);
}

int			findsubstr(const char *s, size_t *i, va_list ap)
{
	t_flags		*fl;

	if (s[*i] == '%')
		return (ft_putchar('%'));
	fl = fill_flags(s, i, NULL);
	if (s[*i] == 's' && (*i)++)
		return (put_s(va_arg(ap, const char *), fl));
	if (s[*i] == 'S' && (*i)++)
		return (ft_putstr("%S"));
	if (s[*i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if ((s[*i] == 'd' || s[*i] == 'i') && (*i)++)
		return (put_di(va_arg(ap, int), 10, fl));
	if ((s[*i] == 'o' || s[*i] == 'u' || s[*i] == 'x' ||\
	s[*i] == 'X') && (*i)++)
	{
		if (s[*i - 1] == 'x')
			fl->small_x = 1;
		return (put_di(va_arg(ap, unsigned int), 10, fl));
	}
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
			++i;
			k += findsubstr(s, &i, ap);
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
