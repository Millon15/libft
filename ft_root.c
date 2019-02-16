/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:57:05 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/18 17:32:46 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_root(int n, int rt)
{
	int					i;
	unsigned long int	j;

	if (n == 1 && rt > 1)
		return (1);
	if (n <= 3 || rt <= 1)
		return (0);
	i = 1;
	while (++i)
	{
		j = ft_pow(i, rt);
		if (j > (unsigned long int)n)
			return (-1);
		if (j == (unsigned long int)n)
			return (i);
	}
	return (0);
}
