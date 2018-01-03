/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:49:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/03 19:22:36 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

typedef struct		s_flags
{
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
	unsigned int	L : 1;
	unsigned int	min_lenth;
	unsigned int	precision;
}					t_flags;

int					ft_putchar(int c);
int					ft_strlen(const char *s);
int					ft_putstr(const char *s);
char				*ft_itoa_base(int value, int base);

int					put_s(const char *s);
int					put_d(int n);
int					put_u(unsigned int n);
int					put_o(unsigned int n);
int					put_x(unsigned int n);
int					put_big_x(unsigned int n);

#endif