/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 23:41:13 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/12 18:26:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	f;

	if (ft_strcmp(needle, "") == 0 || ft_strcmp(haystack, needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		f = 0;
		while (haystack[i + f] == needle[f])
		{
			f++;
			if (!needle[f])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
