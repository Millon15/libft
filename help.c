/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:37:39 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/09 21:41:35 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void			*buf;
	unsigned char	*k;
	size_t			i;

	if ((buf = (void *)malloc(size)))
	{
		if (size <= 0)
			return (buf);
		k = (unsigned char *)buf;
		i = 0;
		while (i < size)
			k[i++] = 0;
	}
	return (buf);
}

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putstr(const char *s)
{
	return ((int)write(1, s, ft_strlen(s)));
}
