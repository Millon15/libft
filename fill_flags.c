/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:09:59 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/06 22:32:37 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	fill_zr(t_flags **fl)
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
	(*fl)->lll = 0;
	(*fl)->precs_spec = 0;
	(*fl)->precision = 0;
	(*fl)->min_lenth = 0;
}

static	int		fill_lenthmod(const char *s, size_t i, t_flags *fl)
{
	while (s[i] && (s[i] != 's' || s[i] != 'S' || s[i] != 'c' || s[i] != 'S' ||
	s[i] != 'i' || s[i] != 'd' || s[i] != 'D' || s[i] != 'x' || s[i] != 'X' ||
	s[i] == 'o' || s[i] != 'O' || s[i] != 'u' || s[i] != 'U' || s[i] != 'p' ))
	{
		if (s[i] == 'h' && s[i + 1] == 'h')
			return ((fl->hh = 1));
		if (s[i] == 'l' && s[i + 1] == 'l')
			return ((fl->ll = 1));
		if (s[i] == 'l')
			return ((fl->l = 1));
		if (s[i] == 'h')
			return ((fl->h = 1));
		if (s[i] == 't')
			return ((fl->t = 1));
		if (s[i] == 'j')
			return ((fl->j = 1));
		if (s[i] == 'z')
			return ((fl->z = 1));
		if (s[i] == 'L')
			return ((fl->lll = 1));
		i++;
	}
	return (0);
}

t_flags			*fill_flags(const char *s, size_t *i, t_flags *fl)
{
	fl = (t_flags *)malloc(sizeof(t_flags));
	fill_zr(&fl);
	fill_lenthmod(s, *i, fl);
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
	return (fl);
}
