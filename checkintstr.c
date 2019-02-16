/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkintstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 20:53:07 by vbrazas           #+#    #+#             */
/*   Updated: 2018/05/27 15:04:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*checkintstr(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (str[i] == '\0' ? NULL : (char*)(str + i));
}
