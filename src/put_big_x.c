/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_big_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:55:15 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/03 15:55:17 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		put_x(unsigned int n)
{
	char	*h;
	int		k;

	h = ft_itoa_base(n, 16);
	k = ft_putstr(h);
	free(h);
	return (k);
}
