/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/05 13:46:42 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa_base_small(unsigned int value, int base)
{
	int		j;
	long	b;
	char	*res;

	if (base > 16 || base < 2)
		return (0);
	j = 1;
	b = base;
	while (value / b && ++j)
		b *= base;
	b = value;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value == 0)
		res[0] = '0';
	while (b)
	{
		res[j--] = "0123456789abcdef"[b % base];
		b /= base;
	}
	return (res);
}


int		put_x(unsigned int n)
{
	char	*h;
	int		k;

	h = ft_itoa_base_small(n, 16);
	k = ft_putstr(h);
	free(h);
	return (k);
}
