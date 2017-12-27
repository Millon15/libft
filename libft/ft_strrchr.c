/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:58:14 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/12 18:25:49 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	char	cc;
	int		i;

	ss = (char *)s;
	cc = (char)c;
	i = ft_strlen(ss);
	if (ss[i] == cc)
		return (ss + i);
	while (i >= 0)
	{
		if (ss[i] == cc)
			return (ss + i);
		i--;
	}
	return (NULL);
}
