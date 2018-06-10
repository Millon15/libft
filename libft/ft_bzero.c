/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:40:48 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 23:41:57 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = n % sizeof(unsigned long long);
	while (i)
	{
		--i;
		((unsigned char *)s)[i] = 0;
	}
	n /= sizeof(unsigned long long);
	while (n)
	{
		--n;
		((unsigned long long *)s)[n] = 0;
	}
}
