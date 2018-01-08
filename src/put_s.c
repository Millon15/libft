/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:15 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/08 21:33:49 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		put_s(const char *s, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	char			*ml;

	i = 0;
	while (s[i] && (!fl->precs_spec || i < fl->precision))
		i++;
	if (i < fl->min_lenth)
	{
		ml = (char *)malloc(sizeof(char) * (fl->min_lenth + 1));
		j = 0;
		while (j < fl->min_lenth)
			ml[j++] = ' ';
		ml[j] = '\0';
		while (i > 0)
			ml[--j] = s[--i];
		j = ft_putstr(ml);
		free(ml);
		return (j);
	}
	else
		return ((int)write(1, s, i));
}
