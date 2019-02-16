/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:56:26 by vbrazas           #+#    #+#             */
/*   Updated: 2019/02/16 18:56:55 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool		ft_freestrjoin(char **dst, const char *source)
{
	char		*tmp;

	if (!dst || !*dst || !source)
		return (false);
	tmp = *dst;
	*dst = ft_strjoin(*dst, source);
	free(tmp);
	return (true);
}
