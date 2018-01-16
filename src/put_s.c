/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:38:15 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/16 14:52:20 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		handle_minln(const char *s, char **tmp,\
unsigned int j, t_flags *fl)
{
	unsigned int	i;
	char			*ml;

	i = (int)ft_strlen(s);
	if (i < fl->min_lenth)
	{
		ml = (char *)ft_memalloc(sizeof(char) * (fl->min_lenth + 1));
		j = fl->minus ? i : 0;
		while (j < fl->min_lenth && !fl->minus)
			ml[j++] = fl->zero ? '0' : ' ';
		while (i > 0)
			ml[--j] = s[--i];
		j = fl->minus ? (unsigned int)ft_strlen(s) : 0;
		while (j < fl->min_lenth && fl->minus)
			ml[j++] = ' ';
		if (*tmp)
			free(*tmp);
		*tmp = ml;
		s = ml;
	}
	j = (unsigned int)ft_putstr(s);
	if (*tmp)
		free(*tmp);
	free(fl);
	return (j);
}

static	void	help(const char **s, char **tmp,\
unsigned int *i, unsigned int *j)
{
	*i = 0;
	*j = 0;
	*tmp = NULL;
	if (!(*s))
	{
		*tmp = (char *)ft_memalloc(sizeof(char) * 7);
		*s = *tmp;
		*s = "(null)";
	}
}

int				put_s(const char *s, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	char			*precision;
	char			*tmp;

	help(&s, &tmp, &i, &j);
	if (fl->precs_spec)
	{
		while (s[i] && i < fl->precision)
			i++;
		precision = (char *)ft_memalloc(sizeof(char) * (fl->precision + 1));
		j = i;
		while (i > 0)
			precision[--j] = s[--i];
		if (tmp)
			free(tmp);
		tmp = precision;
		s = precision;
	}
	return (handle_minln(s, &tmp, j, fl));
}
