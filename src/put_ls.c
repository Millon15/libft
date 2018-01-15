/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:21:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/15 22:23:08 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		put_long_s(const int *s, int **tmp, t_flags *fl)
{
	int				k;
	unsigned int	i;

	k = 0;
	i = 0;
	while (s[i])
		k += put_c(s[i++], NULL);
	if (*tmp)
		free(*tmp);
	free(fl);
	return (k);
}

static	void	len_of_int_arr(const int *s, int **bb, int k)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	while (s[i])
		i++;
	*bb = (int *)malloc(sizeof(int) * (i + 1));
	(*bb)[i] = 0;
	i = 0;
	while (s[i])
	{
		size = 0;
		while (s[i] >> size)
			size++;
		if (size <= 7)
			(*bb)[k++] = 1;
		else if (size <= 11)
			(*bb)[k++] = 2;
		else if (size <= 16)
			(*bb)[k++] = 3;
		else
			(*bb)[k++] = 4;
		i++;
	}
}

static	int		help(const int *s, unsigned int *buf_j, int **bb, t_flags *fl)
{
	unsigned int	i;

	i = 0;
	*buf_j = 0;
	free(*bb);
	len_of_int_arr(s, bb, 0);
	while ((*bb)[i] && *buf_j <= fl->min_lenth)
		*buf_j += (*bb)[i++];
	fl->precision = i;
	return (i);
}

static	int		handle_minln(const int *s, int **tmp, int **bb, t_flags *fl)
{
	unsigned int	i;
	unsigned int	buf_j;
	unsigned int	j;
	int				*ml;

	i = help(s, &buf_j, bb, fl);
	if (buf_j < fl->min_lenth)
	{
		ml = (int *)ft_memalloc(sizeof(int) * (fl->min_lenth + 1));
		j = 0;
		while ((j + buf_j) < fl->min_lenth && !fl->minus)
			ml[j++] = fl->zero ? '0' : ' ';
		!fl->minus ? (j += i) : (j = i);
		while (i > 0)
			ml[--j] = s[--i];
		j = fl->minus ? fl->precision : 0;
		while ((j - fl->precision) < (fl->min_lenth - buf_j) && fl->minus)
			ml[j++] = ' ';
		if (*tmp)
			free(*tmp);
		*tmp = ml;
		s = ml;
	}
	free(*bb);
	return (put_long_s(s, tmp, fl));
}

int				put_ls(const int *s, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	int				*tmp;
	int				*bb;
	int				*precision;

	if (!s)
		return (put_s(NULL, fl));
	len_of_int_arr(s, &bb, 0);
	i = 0;
	j = 0;
	tmp = NULL;
	if (fl->precs_spec)
	{
		precision = (int *)ft_memalloc(sizeof(int) * (fl->precision + 1));
		while (bb[i] && j <= fl->precision)
			j += bb[i++];
		(!bb[i] && j <= fl->precision) ? (j = i) :\
		(j = --i);
		while (i > 0)
			precision[--j] = s[--i];
		s = precision;
		tmp = precision;
	}
	return (handle_minln(s, &tmp, &bb, fl));
}
