/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:28:07 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/12 18:21:52 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*buf;
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
	buf = (char *)malloc(sizeof(char) * j);
	if (buf == NULL)
		return (NULL);
	j = 0;
	if (n < 0)
		buf[j++] = '-';
	while ((i /= 10) > 0)
		buf[j++] = (nn / i) % 10 + '0';
	buf[j] = '\0';
	return (buf);
}
