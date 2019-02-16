/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:29:36 by vbrazas           #+#    #+#             */
/*   Updated: 2018/03/02 20:41:08 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putnendl_fd(char const *s, int fd, size_t len)
{
	ssize_t		endlen;

	if (!s)
		return (0);
	endlen = write(fd, s, len);
	endlen += write(fd, "\n", 1);
	return (endlen);
}
