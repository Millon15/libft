/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:09:59 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/08 19:14:43 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	fill_zr(t_flags **fl)
{
	(*fl)->is_small_x = 0;
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
	(*fl)->base = 0;
	(*fl)->precision = 0;
	(*fl)->min_lenth = 0;
}

static	int		fill_lenthmod(const char *s, size_t *i, size_t l, t_flags *fl)
{
	while (s[l] && (s[l] != 's' || s[l] != 'S' || s[l] != 'c' || s[l] != 'S' ||
	s[l] != 'l' || s[l] != 'd' || s[l] != 'D' || s[l] != 'x' || s[l] != 'X' ||
	s[l] == 'o' || s[l] != 'O' || s[l] != 'u' || s[l] != 'U' || s[l] != 'p' ))
	{
		if (s[l] == 'h' && s[l + 1] == 'h' && ((*i) += 2))
			return ((fl->hh = 1));
		if (s[l] == 'l' && s[l + 1] == 'l' && ((*i) += 2))
			return ((fl->ll = 1));
		if (s[l] == 'l' && ((*i)++))
			return ((fl->l = 1));
		if (s[l] == 'h' && ((*i)++))
			return ((fl->h = 1));
		if (s[l] == 't' && ((*i)++))
			return ((fl->t = 1));
		if (s[l] == 'j' && ((*i)++))
			return ((fl->j = 1));
		if (s[l] == 'z' && ((*i)++))
			return ((fl->z = 1));
		if (s[l] == 'L' && ((*i)++))
			return ((fl->lll = 1));
		l++;
	}
	return (0);
}

t_flags			*fill_flags(const char *s, size_t *i, size_t l, t_flags *fl)
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
	fill_lenthmod(s, i, l, fl);
	return (fl);
}
