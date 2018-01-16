/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/16 14:52:56 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*norm_it(char *buf, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

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

static	char	*eutoa_base(uintmax_t value, short base, t_flags *fl)
{
	uintmax_t		v;
	char			*buf;
	unsigned int	i;

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

static	int		handle_minln(char *s, char *ml, unsigned int i, t_flags *fl)
{
	unsigned int	j;

	if (i < fl->min_lenth)
	{
		ml = (char *)ft_memalloc(sizeof(char) * (fl->min_lenth + 3));
		j = fl->minus ? i : 0;
		while (j < fl->min_lenth && !fl->minus)
			ml[j++] = (fl->zero && !fl->precs_spec) ? '0' : ' ';
		if (fl->zero && !fl->precs_spec && fl->hesh\
		&& !fl->minus && fl->base == 16 && (s[1] == 'x' || s[1] == 'X'))
			ml[1] = fl->is_small_x ? 'x' : 'X';
		while (i > ((fl->hesh && fl->zero && !fl->precs_spec && !fl->minus) ?\
		(fl->base / 8) : 0))
			ml[--j] = s[--i];
		j = fl->minus ? (unsigned int)ft_strlen(s) : 0;
		while (j < fl->min_lenth && fl->minus)
			ml[j++] = ' ';
		free(s);
		s = ml;
	}
	j = (unsigned int)ft_putstr(s);
	free(s);
	free(fl);
	return (j);
}

static	void	help(uintmax_t n, char *s, unsigned int *i, t_flags *fl)
{
	if (!n && !fl->p && fl->hesh)
		s[1] = 0;
	if (!n && fl->precs_spec && !fl->precision && !fl->p &&\
	(!fl->hesh || ((fl->base == 16 || fl->base == 10) && fl->hesh)))
		s[0] = 0;
	if (!n && fl->p)
		s[0] = '0';
	if (!n && fl->precs_spec && !fl->precision && fl->p)
		s[2] = 0;
	*i = (unsigned int)ft_strlen(s);
}

int				put_oux(uintmax_t n, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	rem;
	char			*precision;
	char			*s;

	s = eutoa_base(n, fl->base, fl);
	help(n, s, &i, fl);
	if (fl->precs_spec && i <= fl->precision)
	{
		precision = (char *)ft_memalloc(sizeof(char) * (fl->precision + 3));
		j = 0;
		while (j < (fl->precision + ((fl->hesh && (n || fl->p)\
		&& fl->base == 16) ? 2 : 0)))
			precision[j++] = '0';
		if (fl->hesh && fl->base == 16 && (n || fl->p))
			precision[1] = fl->is_small_x ? 'x' : 'X';
		rem = !(fl->base % 8) ? (fl->base / 8) : 0;
		while (i > ((fl->hesh && (n || fl->p)) ? rem : 0))
			precision[--j] = s[--i];
		free(s);
		s = precision;
		i = (unsigned int)ft_strlen(s);
	}
	return (handle_minln(s, NULL, i, fl));
}
