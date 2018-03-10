/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:00:14 by vbrazas           #+#    #+#             */
/*   Updated: 2018/03/02 17:55:57 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_atoi_base function inputs (char *)s - array of chars, which only
**	include numbers and '-' sign, numbers may be at any base from 2nd to 36th,
**	and outputs decimal integer value, which represent input number.
**
**	i[0] -- len of (char *)s iterator(i);
**	i[1] -- len of (char *)s buffer(i_buf);
**	i[2] -- "0123456789ABCDEF" iterator(j);
**	i[3] -- buf[0] == '-' ? -1 : 1;
*/

int		ft_atoi_base(const char *s, int base)
{
	int				i[4];
	int				res;
	char			*buf;
	const	char	st[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	buf = ft_strtrim(s);
	i[3] = buf[0] == '-' ? -1 : 1;
	buf = (buf[0] == '-' || buf[0] == '+') ? (buf + 1) : buf;
	i[1] = -1;
	while (buf[++i[1]])
		buf[i[1]] = ft_toupper(buf[i[1]]);
	i[0] = i[1]--;
	res = 0;
	while (--(i[0]) + 1)
	{
		i[2] = 0;
		while ((st[i[2]] != buf[i[0]]) && i[2] < base)
			i[2]++;
		res += i[2] * (!(i[1] - i[0]) ? 1 : (ft_pow(base, i[1] - i[0])));
	}
	free(buf);
	return ((res * i[3]));
}
