/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dioux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/05 20:41:13 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// int		handle_minln(char *s, char *ml, int i, t_flags *fl)
// {
// 	int		j;

// 	if (i < fl->min_lenth)
// 	{
// 		ml = (char *)malloc(sizeof(char) * (fl->min_lenth + 1));
// 		j = 0;
// 		while (j < fl->min_lenth)
// 			ml[j++] = (fl->zero && !fl->precs_spec) ? '0' : ' ';
// 		ml[j] = '\0';
// 		while (i > 0)
// 			ml[--j] = s[--i];
// 		free(s);
// 		j = ft_putstr(ml);
// 		free(ml);
// 		return (j);
// 	}
// 	j = (int)write(1, s, i);
// 	free(s);
// 	return (j);
// }

char	*norm_it(char *buf, short base, t_flags fl)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)ft_memalloc(sizeof(char) * 65);
	if (buf[0] != '0' && base == 10 & (j = 1))
		res[i++] = buf[0];
	else
		j = 0;
	while (buf[j] == '0')
		j++;
	if (!buf[j])
		return (res = "0");
	while (buf[j])
		res[i++] = buf[j++];
	return (res);
}

char	*eutoa_base(unsigned long value, short base, t_flags *fl)
{
	unsigned long	v;
	char			*buf;
	int				i;

	if (base > 16 || base < 2)
		return (0);
	i = 65;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	v = value;
	buf[i] = '\0';
	while (i != 0)
	{
		fl->small_x ? (buf[--i] = "0123456789abcdef"[v % base]) :\
		(buf[--i] = "0123456789ABCDEF"[v % base]);
		v /= base;
	}
	return (norm_it(buf, fl));
}

char	*estoa_base(long value, short base, t_flags *fl)
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
		fl->small_x ? (buf[--i] = "0123456789abcdef"[v % base]) :\
		(buf[--i] = "0123456789ABCDEF"[v % base]);
		v /= base;
	}
	buf[0] = (value < 0 && base == 10) ? '-' :\
	(value > 0 && fl->plus && base == 10) ? '+' :\
	(value > 0 && fl->space && base == 10) ? ' ' : '0';
	return (norm_it(buf, fl));
}

int		put_dioux(long n, short base, t_flags *fl)
{
	// int		i;
	// 	char	*ml;
	// int		j;
	char	*s;

	if (base == 16 || base == 8)
		s = ft_eutoa_base(n, base, fl);
	else
		s = ft_estoa_base(n, base, fl);
	// i = ft_strlen(s);
	// if (fl->precs_spec && i < fl->precision)
	// {
	// 	ml = (char *)malloc(sizeof(char) * (fl->precision + 1));
	// 	j = 0;
	// 	while (j < fl->precision)
	// 		ml[j++] = '0';
	// 	ml[j] = '\0';
	// 	while (i > 0)
	// 		ml[--j] = s[--i];
	// 	free(s);
	// 	s = ml;
	// 	i = ft_strlen(s);
	// }
	return (handle_minln(s, ml, i, fl));
}
