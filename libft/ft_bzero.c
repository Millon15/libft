/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:40:48 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/12 11:48:32 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = n % sizeof(size_t);
	while (i)
	{
		--i;
		((unsigned char *)s)[i] = 0;
	}
	n /= sizeof(size_t);
	while (n)
	{
		--n;
		((size_t *)s)[n] = 0;
	}
}
