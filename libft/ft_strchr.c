/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:00:36 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/14 17:59:31 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ss;
	char	cc;
	size_t	i;

	ss = (char *)s;
	cc = (char)c;
	i = 0;
	if (cc == '\0')
	{
		while (ss[i])
			i++;
		return (&ss[i]);
	}
	while (ss[i])
		if (ss[i++] == cc)
			return (&ss[i - 1]);
	return (NULL);
}
