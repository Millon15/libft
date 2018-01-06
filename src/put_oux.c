/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/06 15:54:31 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*norm_it(char *buf, short base, t_flags *fl)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = (char *)ft_memalloc(sizeof(char) * 65);
	if (buf[0] != '0' && base == 10 && (j = 1))
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

static	char	*eutoa_base(unsigned long value, short base, t_flags *fl)
{
	unsigned long	v;
	char			*buf;
	int				i;

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
	return (norm_it(buf, base, fl));
}

int		put_oux(unsigned long n, short base, t_flags *fl)
{
	char	*s;
	int		i;

	s = ft_eutoa_base(n, base, fl);
	i = ft_putstr(s);
	free(s);
	return (i);
}
