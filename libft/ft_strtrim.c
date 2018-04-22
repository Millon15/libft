/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:43:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/03/30 18:56:40 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*buf;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	j = ft_strlen((char *)s) - 1;
	while (j != 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == 0)
		i = 1;
	buf = (char *)malloc(sizeof(char) * (++j - i + 1));
	if (buf == NULL)
		return (NULL);
	k = 0;
	while (i < j)
		buf[k++] = s[i++];
	buf[k] = '\0';
	return (buf);
}
