/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:21:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/14 20:45:29 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		put_long_s(const int *s, t_flags *fl)
{
	int				k;
	unsigned int	i;

	k = 0;
	i = 0;
	while (s[i])
		k += put_c(s[i++], NULL);
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

// static	int		handle_minln(const int *s, unsigned int i, unsigned int j, t_flags *fl)
// {
// 	int				*ml;

// 	i = len_of_int_arr(s);
// 	if (i < fl->min_lenth)
// 	{
// 		ml = (int *)ft_memalloc(sizeof(int) * (fl->min_lenth + 1));
// 		j = fl->minus ? i : 0;
// 		while (j < fl->min_lenth && !fl->minus)
// 			ml[j++] = ' ';
// 		while (i > 0)
// 			ml[--j] = s[--i];
// 		j = fl->minus ? len_of_int_arr(s) : 0;
// 		while (j < fl->min_lenth && fl->minus)
// 			ml[j++] = ' ';
// 		s = ml;
// 	}
// 	return (put_long_s(s, fl));
// }

int				put_ls(const int *s, t_flags *fl)
{
	unsigned int	i;
	unsigned int	j;
	int				*bb;
	int				*precision;

	if (!s)
		return (put_s(NULL, fl));
	len_of_int_arr(s, &bb, 0);
	i = 0;
	j = 0;
	precision = NULL;
	if (fl->precs_spec)
	{
		while (j <= fl->precision)
			j += bb[i++];
		i--;
		precision = (int *)ft_memalloc(sizeof(int) * (fl->precision + 1));
		j = i;
		while (i > 0)
			precision[--j] = s[--i];
	}
	return (put_long_s(precision ? precision : s, fl));
	// return (handle_minln(precision, i, j, fl));
}
