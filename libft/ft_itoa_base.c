/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 05:22:18 by vbrazas           #+#    #+#             */
/*   Updated: 2017/12/15 06:33:49 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
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
	if (value < 0 && (b = -b) && base == 10)
		j++;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value == 0)
		res[0] = '0';
	if (value < 0 && base == 10)
		res[0] = '-';
	while (b)
	{
		res[j--] = "0123456789ABCDEF"[b % base];
		b /= base;
	}
	return (res);
}
