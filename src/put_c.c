/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:52:16 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/13 20:39:27 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Unicode mask:
**
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

static	void	help1(int k, unsigned int mask[], unsigned char c[])
{
	if (k > 7 && k <= 11 && MB_CUR_MAX >= 2)
	{
		c[1] = (mask[4] << 26) >> 26;
		c[0] = ((mask[4] >> 6) << 27) >> 27;
		c[4] = (mask[1] >> 8) | c[0];
		mask[0] += write(1, &c[4], 1);
		c[4] = ((mask[1] << 24) >> 24) | c[1];
	}
	if (k > 11 && k <= 16 && MB_CUR_MAX >= 3)
	{
		c[2] = (mask[4] << 26) >> 26;
		c[1] = ((mask[4] >> 6) << 26) >> 26;
		c[0] = ((mask[4] >> 12) << 28) >> 28;
		c[4] = (mask[2] >> 16) | c[0];
		mask[0] += write(1, &c[4], 1);
		c[4] = ((mask[2] << 16) >> 24) | c[1];
		mask[0] += write(1, &c[4], 1);
		c[4] = ((mask[2] << 24) >> 24) | c[2];
	}
}

static	void	print_c(int k, unsigned int mask[], unsigned char c[])
{
	help1(k, mask, c);
	if (k > 16 && MB_CUR_MAX >= 4)
	{
		c[3] = (mask[4] << 26) >> 26;
		c[2] = ((mask[4] >> 6) << 26) >> 26;
		c[1] = ((mask[4] >> 12) << 26) >> 26;
		c[0] = ((mask[4] >> 18) << 29) >> 29;
		c[4] = (mask[3] >> 24) | c[0];
		mask[0] += write(1, &c[4], 1);
		c[4] = ((mask[3] << 8) >> 24) | c[1];
		mask[0] += write(1, &c[4], 1);
		c[4] = ((mask[3] << 16) >> 24) | c[2];
		mask[0] += write(1, &c[4], 1);
		c[4] = ((mask[3] << 24) >> 24) | c[3];
	}
	mask[0] += write(1, &c[4], 1);
}

static	void	handle_minln(unsigned int k, unsigned int mask[],\
unsigned char c[], t_flags *fl)
{
	unsigned int	l;
	unsigned int	k_buf;

	k_buf = k;
	if (k <= 7)
		k = 1;
	else if (k <= 11)
		k = 2;
	else if (k <= 16)
		k = 3;
	else
		k = 4;
	l = 0;
	while (fl && !fl->minus && ((k + l++) < fl->min_lenth))
		mask[0] += write(1, (fl->zero ? "0" : " "), 1);
	print_c(k_buf, mask, c);
	l = 0;
	while (fl && fl->minus && ((k + l++) < fl->min_lenth))
		mask[0] += write(1, (fl->zero ? "0" : " "), 1);
}

int				put_c(int chr, t_flags *fl)
{
	unsigned int	mask[5];
	unsigned char	c[5];
	unsigned int	k;

	mask[0] = 0;
	mask[1] = 49280;
	mask[2] = 14712960;
	mask[3] = 4034953344;
	mask[4] = chr;
	if (chr < 0)
		mask[4] = -chr - 1;
	k = 1;
	while (mask[4] >> k)
		k++;
	c[4] = chr;
	handle_minln(k, mask, c, fl);
	if (fl)
		free(fl);
	return (mask[0]);
}
