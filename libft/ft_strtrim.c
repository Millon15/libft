/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:43:02 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/17 19:09:44 by vbrazas          ###   ########.fr       */
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
	i = 0;
	j = ft_strlen((char *)s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j])
		j--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
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
