/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/04 13:12:22 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		put_d(int n, t_flags *fl)
{
	int		i;
	int		j;
	char	*s;
	char	*ml;

	i = 0;
	s = ft_itoa_base(n, 10);
	while (s[i])
		i++;
	if (i < fl->min_lenth)
	{
		ml = (char *)malloc(sizeof(char) * (fl->min_lenth + 1));
		j = 0;
		while (j < fl->min_lenth)
			ml[j++] = (fl->zero && !fl->precs_spec) ? '0' : ' ';
		ml[j] = '\0';
		while (i > 0)
			ml[--j] = s[--i];
		free(s);
		j = ft_putstr(ml);
		free(ml);
		return (j);
	}
	else
	{
		j = (int)write(1, s, i);
		free(s);
		return (j);
	}
}
