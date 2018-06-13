/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_the_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:55:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/13 12:55:13 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			print_the_bit(size_t b)
{
	char	arr[sizeof(size_t)];
	char	i;

	i = 0;
	while (b != 0)
	{
		arr[i++] = b & 1 ? '1' : '0';
		b >>= 1;
	}
	while (i)
		ft_putchar(arr[--i]);
}
