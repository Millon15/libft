/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/08 18:31:49 by vbrazas          ###   ########.fr       */
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
	if (buf[0] != '0')
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

static	char	*estoa_base(long long value, short base, t_flags *fl)
{
	unsigned long long	v;
	char				*buf;
	int					i;

	i = 65;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	v = value;
	if (value < 0)
		v = -value;
	buf[i] = '\0';
	while (i != 0)
	{
		buf[--i] = "0123456789ABCDEF"[v % base];
		v /= base;
	}
	if (value < 0)
		buf[0] = '-';
	else if (value > 0 && fl->plus)
		buf[0] =  '+';
	else if (value > 0 && fl->space)
		buf[0] = ' ';
	return (norm_it(buf, fl));
}

static	int		handle_minln(char *s, char *ml, int i, t_flags *fl)
{
	int		j;

	if (i < fl->min_lenth)
	{
		ml = (char *)ft_memalloc(sizeof(char) * (fl->min_lenth + 2));
		j = fl->minus ? i : 0;
		while (j < fl->min_lenth && !fl->minus)
			ml[j++] = (fl->zero && !fl->precs_spec) ? '0' : ' ';
		while (i > 0)
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

int				put_di(long long n, short base, t_flags *fl)
{
	int		i;
	int		j;
	char	*precision;
	char	*s;

	s = estoa_base(n, base, fl);
	i = ft_strlen(s);
	if (fl->precs_spec && i <= fl->precision)
	{
		precision = (char *)ft_memalloc(sizeof(char) * (fl->precision + 2));
		j = 0;
		while (j < (fl->precision + ((n < 0 || fl->plus || fl->space) ? 1 : 0)))
			precision[j++] = '0';
		if (n < 0)
			precision[0] = '-';
		else if (n > 0 && fl->plus)
			precision[0] =  '+';
		else if (n > 0 && fl->space)
			precision[0] = ' ';
		while (i > ((n < 0 || fl->plus || fl->space) ? 1 : 0))
			precision[--j] = s[--i];
		free(s);
		s = precision;
		i = ft_strlen(s);
	}
	return (handle_minln(s, precision, i, fl));
}
