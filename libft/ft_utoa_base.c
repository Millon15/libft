/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:11:44 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/07 07:36:59 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned long value, int base)
{
	int				j;
	unsigned long	b;
	char			*res;

	if (base > 16 || base < 2)
		return (0);
	j = 1;
	b = value;
	while (b /= base)
		j++;
	b = value;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value == 0)
		res[0] = '0';
	while (b)
	{
		res[j--] = "0123456789ABCDEF"[b % base];
		b /= base;
	}
	return (res);
}
