/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:52:16 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/09 22:24:57 by vbrazas          ###   ########.fr       */
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

static	void	help2(int *k, unsigned int mask[], unsigned char c[])
{
	c[3] = (mask[4] << 26) >> 26;
	c[2] = ((mask[4] >> 6) << 26) >> 26;
	c[1] = ((mask[4] >> 12) << 26) >> 26;
	c[0] = ((mask[4] >> 18) << 29) >> 29;
	c[4] = (mask[3] >> 24) | c[0];
	*k += write(1, &c[4], 1);
	c[4] = ((mask[3] << 8) >> 24) | c[1];
	*k += write(1, &c[4], 1);
	c[4] = ((mask[3] << 16) >> 24) | c[2];
	*k += write(1, &c[4], 1);
	c[4] = ((mask[3] << 24) >> 24) | c[3];
	*k += write(1, &c[4], 1);
}

static	void	help1(int *k, unsigned int mask[], unsigned char c[])
{
	if (*k <= 11)
	{
		c[1] = (mask[4] << 26) >> 26;
		c[0] = ((mask[4] >> 6) << 27) >> 27;
		c[4] = (mask[1] >> 8) | c[0];
		*k += write(1, &c[4], 1);
		c[4] = ((mask[1] << 24) >> 24) | c[1];
		*k += write(1, &c[4], 1);
	}
	else if (*k <= 16)
	{
		c[2] = (mask[4] << 26) >> 26;
		c[1] = ((mask[4] >> 6) << 26) >> 26;
		c[0] = ((mask[4] >> 12) << 28) >> 28;
		c[4] = (mask[2] >> 16) | c[0];
		*k += write(1, &c[4], 1);
		c[4] = ((mask[2] << 16) >> 24) | c[1];
		*k += write(1, &c[4], 1);
		c[4] = ((mask[2] << 24) >> 24) | c[2];
		*k += write(1, &c[4], 1);
	}
	else
		help2(k, mask, c);
}

int				ft_putchar(unsigned int chr)
{
	unsigned int	mask[5];
	unsigned char	c[5];
	int				k;

	mask[1] = 49280;
	mask[2] = 14712960;
	mask[3] = 4034953344;
	mask[4] = chr;
	c[4] = chr;
	k = 1;
	while (mask[4] >> k && k <= 23)
		k++;
	mask[4] = chr;
	if (k <= 7)
		k += write(1, &(c[4]), 1);
	else
		help1(&k, mask, c);
	return (k);
}
