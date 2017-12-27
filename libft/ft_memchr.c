/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:10:30 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/12 18:22:54 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*k;
	size_t			i;

	k = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (k[i] == (unsigned char)c)
			return (k + i);
		i++;
	}
	return (NULL);
}
