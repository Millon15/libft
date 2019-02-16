/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:38:54 by vbrazas           #+#    #+#             */
/*   Updated: 2018/05/24 20:40:09 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	char	*buf;
	size_t	i;

	if (s == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}
