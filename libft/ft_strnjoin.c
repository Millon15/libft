/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:01:16 by vbrazas           #+#    #+#             */
/*   Updated: 2018/03/02 20:07:30 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t l1, size_t l2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (l1 + l2 + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < l1)
		buf[i++] = s1[j++];
	j = 0;
	while (j < l2)
		buf[i++] = s2[j++];
	buf[i] = '\0';
	return (buf);
}
