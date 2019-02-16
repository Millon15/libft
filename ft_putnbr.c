/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 09:28:43 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/12 18:23:54 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	buf[12];
	long	i;
	long	nn;
	short	j;

	i = 10;
	j = 2;
	nn = n;
	if (n < 0)
	{
		nn = -nn;
		j++;
	}
	while (nn / i > 0 && ++j)
		i *= 10;
	j = 0;
	if (n < 0)
		buf[j++] = '-';
	while ((i /= 10) > 0)
		buf[j++] = (nn / i) % 10 + '0';
	buf[j] = '\0';
	ft_putstr(buf);
}
