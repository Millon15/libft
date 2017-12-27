/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:17:21 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/19 14:54:55 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	if (len != 0)
	{
		d = dst;
		s = src;
		if ((*d++ = *s++) == '\0')
		{
			while (--len != 0)
				*d++ = '\0';
			return (dst);
		}
		while (--len != 0)
		{
			if ((*d++ = *s++) == '\0')
			{
				while (--len != 0)
					*d++ = '\0';
				break ;
			}
		}
	}
	return (dst);
}
