/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/08 18:50:05 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*norm_it(char *buf, t_flags *fl)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)ft_memalloc(sizeof(char) * 65);
	if (buf[0] != '0' || (fl->hesh && !(fl->base % 8)))
		res[i++] = buf[j++];
	if (buf[1] != '0')
		res[i++] = buf[j++];
	while (buf[j] == '0')
		j++;
	if (!buf[j])
		res[i] = '0';
	while (buf[j])
		res[i++] = buf[j++];
	free(buf);
	return (res);
}

static	char	*eutoa_base(unsigned long long value, short base, t_flags *fl)
{
	unsigned long long	v;
	char				*buf;
	int					i;

	i = 65;
	v = value;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	buf[i] = '\0';
	while (i != 0)
	{
		fl->is_small_x ? (buf[--i] = "0123456789abcdef"[v % base]) :\
		(buf[--i] = "0123456789ABCDEF"[v % base]);
		v /= base;
	}
	if (fl->hesh && base == 16)
		buf[1] = fl->is_small_x ? 'x' : 'X';
	return (norm_it(buf, fl));
}

static	int		handle_minln(char *s, char *ml, int i, t_flags *fl)
{
	int		j;

	if (i < fl->min_lenth)
	{
		ml = (char *)ft_memalloc(sizeof(char) * (fl->min_lenth + 3));
		j = fl->minus ? i : 0;
		while (j < fl->min_lenth && !fl->minus)
			ml[j++] = (fl->zero && !fl->precs_spec) ? '0' : ' ';
		if (fl->zero && !fl->precs_spec && fl->hesh\
		 && !fl->minus && fl->base == 16 && (ml[0] = '0'))
			ml[1] = fl->is_small_x ? 'x' : 'X';
		while (i > ((fl->hesh && fl->zero && !fl->precs_spec && !fl->minus) ?\
		(fl->base / 8) : 0))
			ml[--j] = s[--i];
		j = fl->minus ? ft_strlen(s) : 0;
		while (j < fl->min_lenth && fl->minus)
			ml[j++] = ' ';
		free(s);
		j = ft_putstr(ml);
		free(ml);
		return (j);
	}
	j = (int)write(1, s, i);
	free(s);
	return (j);
}

int				put_oux(unsigned long long n, short base, t_flags *fl)
{
	int		i;
	int		j;
	char	*precision;
	char	*s;

	s = eutoa_base(n, base, fl);
	i = ft_strlen(s);
	if (fl->precs_spec && i <= fl->precision)
	{
		precision = (char *)ft_memalloc(sizeof(char) * (fl->precision + 3));
		j = 0;
		while (j < (fl->precision + ((fl->hesh && base == 16) ? 2 : 0)))
			precision[j++] = '0';
		if (fl->hesh && base == 16)
			precision[1] = fl->is_small_x ? 'x' : 'X';
		while (i > (fl->hesh ? !(base % 8) ? (base / 8) : 0 : 0))
			precision[--j] = s[--i];
		free(s);
		s = precision;
		i = ft_strlen(s);
	}
	return (handle_minln(s, precision, i, fl));
}
