/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 02:23:33 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/09 02:23:46 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_itoc(const unsigned char value, const bool is_upperсase)
{
	if (value < 10)
		return (value + '0');
	return (value - 10 + (is_upperсase ? 'A' : 'a'));
}
