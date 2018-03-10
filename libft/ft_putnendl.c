/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:34:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/03/02 20:41:09 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putnendl(char const *s, size_t len)
{
	ssize_t		endlen;

	if (!s)
		return (0);
	endlen = write(1, s, len);
	endlen += write(1, "\n", 1);
	return (endlen);
}
