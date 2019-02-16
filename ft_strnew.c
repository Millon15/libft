/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:12:33 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/18 19:24:27 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buf;
	size_t	i;

	buf = (char *)malloc(size + 1);
	i = 0;
	if (buf != NULL)
		while (i <= size)
			buf[i++] = '\0';
	return (buf);
}
