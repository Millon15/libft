/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:21:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/11 18:49:30 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		put_long_s(int *s)
{
	int				k;
	unsigned int	i;

	k = 0;
	i = 0;
	while (s[i])
		k += put_c(s[i++]);
	free(s);
	return (k);
}

static	int		len_of_int_arr(const int *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	int		len_of_int_wchar_arr(const int *s)
{
	unsigned int	i;
	unsigned int	size;
	int				k;
	int				buf;

	i = 0;
	k = 0;
	while (s[i])
	{
		buf = s[i];
		size = 0;
		while (buf >> size)
			size++;
		if (size <= 7)
			k += 1;
		else if (size <= 11)
			k += 2;
		else if (size <= 16)
			k += 3;
		else
			k += 4;
		i++;
	}
	return (k);
}

static	int		handle_minln(int *s, unsigned int i, unsigned int j, t_flags *fl)
{
	int				*ml;

	i = len_of_int_arr(s);
	if (i < fl->min_lenth)
	{
		ml = (int *)ft_memalloc(sizeof(int) * (fl->min_lenth + 1));
		j = fl->minus ? i : 0;
		while (j < fl->min_lenth && !fl->minus)
			ml[j++] = ' ';
		while (i > 0)
			ml[--j] = s[--i];
		j = fl->minus ? len_of_int_arr(s) : 0;
		while (j < fl->min_lenth && fl->minus)
			ml[j++] = ' ';
		s = ml;
	}
	return (put_long_s(s));
}

int				put_ls(const int *s, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	int				*precision;

	i = 0;
	j = 0;
	precision = NULL;
	if (fl->precs_spec)
	{
		while (s[i] && i < fl->precision)
			i++;
		precision = (int *)ft_memalloc(sizeof(int) * (fl->precision + 1));
		j = i;
		while (i > 0)
			precision[--j] = s[--i];
	}
	return (handle_minln(precision, i, j, fl));
}
