/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:49:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/16 14:53:22 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flags
{
	unsigned int	is_small_x : 1;
	unsigned int	plus : 1;
	unsigned int	minus : 1;
	unsigned int	space : 1;
	unsigned int	hesh : 1;
	unsigned int	zero : 1;
	unsigned int	hh : 1;
	unsigned int	h : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;
	unsigned int	t : 1;
	unsigned int	lll : 1;
	unsigned int	p : 1;
	unsigned int	precs_spec : 1;
	unsigned int	base : 5;
	unsigned int	precision;
	unsigned int	min_lenth;
}					t_flags;

size_t				ft_strlen(const char *s);
ssize_t				ft_putstr(const char *s);
void				*ft_memalloc(size_t size);

int					ft_printf(const char *s, ...);
t_flags				*fill_flags(const char *s, size_t *i, t_flags *fl);

int					put_c(int c, t_flags *fl);
int					put_s(const char *s, t_flags *fl);
int					put_ls(const int *s, t_flags *fl);
int					put_di(intmax_t n, t_flags *fl);
int					put_oux(uintmax_t n, t_flags *fl);

#endif
