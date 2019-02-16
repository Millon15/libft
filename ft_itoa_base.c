/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 05:22:18 by vbrazas           #+#    #+#             */
/*   Updated: 2018/02/20 21:04:32 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	int				j;
	unsigned long	a;
	unsigned int	b;
	char			*res;

	if (base > 16 || base < 2)
		return (0);
	j = (value < 0 && base == 10) ? 2 : 1;
	b = (value < 0) ? -value : value;
	a = base;
	while (b / a && ++j)
		a *= base;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value < 0 && base == 10)
		res[0] = '-';
	else if (value == 0)
		res[0] = '0';
	while (b)
	{
		res[j--] = "0123456789ABCDEF"[b % base];
		b /= base;
	}
	return (res);
}
