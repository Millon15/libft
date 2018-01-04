/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/04 16:44:48 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		handle_minln(char *s, char *ml, int i, t_flags *fl)
{
	int		j;

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
	j = (int)write(1, s, i);
	free(s);
	return (j);
}

int		put_d(int n, t_flags *fl)
{
	int		i;
	int		j;
	char	*s;
	char	*ml;

	s = ft_itoa_base(n, 10);
	i = ft_strlen(s);
	if (fl->precs_spec && i < fl->precision)
	{
		ml = (char *)malloc(sizeof(char) * (fl->precision + 1));
		j = 0;
		while (j < fl->precision)
			ml[j++] = '0';
		ml[j] = '\0';
		while (i > 0)
			ml[--j] = s[--i];
		free(s);
		s = ml;
		i = ft_strlen(s);
	}
	return (handle_minln(s, ml, i, fl));
}
