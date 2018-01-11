/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:52:16 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/11 20:32:48 by vbrazas          ###   ########.fr       */
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
	c[4] = mask[4];
	c[5] = 0;
	c[6] = 0;
	c[7] = 0;
	if (k > 7 && k <= 11)
	{
		c[1] = (mask[4] << 26) >> 26;
		c[0] = ((mask[4] >> 6) << 27) >> 27;
		c[4] = (mask[1] >> 8) | c[0];
		c[5] = ((mask[1] << 24) >> 24) | c[1];
	}
	if (k > 11 && k <= 16)
	{
		c[2] = (mask[4] << 26) >> 26;
		c[1] = ((mask[4] >> 6) << 26) >> 26;
		c[0] = ((mask[4] >> 12) << 28) >> 28;
		c[4] = (mask[2] >> 16) | c[0];
		c[5] = ((mask[2] << 16) >> 24) | c[1];
		c[6] = ((mask[2] << 24) >> 24) | c[2];
	}
}

static	void	print_c(int k, unsigned int mask[], unsigned char c[])
{
	help1(k, mask, c);
	if (k > 16)
	{
		c[3] = (mask[4] << 26) >> 26;
		c[2] = ((mask[4] >> 6) << 26) >> 26;
		c[1] = ((mask[4] >> 12) << 26) >> 26;
		c[0] = ((mask[4] >> 18) << 29) >> 29;
		c[4] = (mask[3] >> 24) | c[0];
		c[5] = ((mask[3] << 8) >> 24) | c[1];
		c[6] = ((mask[3] << 16) >> 24) | c[2];
		c[7] = ((mask[3] << 24) >> 24) | c[3];
	}
	if (MB_CUR_MAX >= 1)
		mask[0] += write(1, &c[4], 1);
	if (MB_CUR_MAX >= 2)
		mask[0] += write(1, &c[4], 1);
	if (MB_CUR_MAX >= 3)
		mask[0] += write(1, &c[4], 1);
	if (MB_CUR_MAX >= 4)
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
	while (!fl->minus && ((k + l++) < fl->min_lenth))
		write(1, " ", 1);
	print_c(k_buf, mask, c);
	while (fl->minus && ((k + l++) < fl->min_lenth))
		write(1, " ", 1);
}

int				put_c(int chr, t_flags *fl)
{
	unsigned int	mask[7];
	unsigned char	c[8];
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
	handle_minln(k, mask, c, fl);
	return (mask[0]);
}
