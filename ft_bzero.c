/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:40:48 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/19 14:54:07 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*k;
	size_t			i;

	if (n <= 0)
		return ;
	k = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		k[i] = 0;
		i++;
	}
}
