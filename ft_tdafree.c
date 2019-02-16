/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdafree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:57:05 by vbrazas           #+#    #+#             */
/*   Updated: 2019/02/16 18:57:15 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool		ft_tdafree(char ***arr)
{
	int		i;

	if (!arr || !*arr)
		return (true);
	i = -1;
	while (arr[0][++i])
		free(arr[0][i]);
	free(arr[0]);
	*arr = NULL;
	return (true);
}
