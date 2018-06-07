/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:49:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/07 07:02:42 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# define BUFFER_SIZE 16384

typedef struct	s_flags
{
	size_t							apostrophe : 1;
	size_t							zero : 1;
	size_t							space : 1;
	size_t							hesh : 1;
	size_t							plus : 1;
	size_t							minus : 1;
	size_t							l : 1;
	size_t							ll : 1;
	size_t							h : 1;
	size_t							hh : 1;
	size_t							j : 1;
	size_t							z : 1;
	size_t							bigx : 1;
	size_t							is_negative : 1;
	size_t							precs_spec : 1;
	size_t							is_prec : 1;
	size_t							is_minlenth : 1;
	size_t							precision;
	size_t							minlenth;

}				t_flags;

typedef struct	s_printf
{
	va_list							ap;
	t_flags							fl;
	char							convchr;
	size_t							i;
	char							*buf;
	ssize_t							totout;

}				t_printf;


int				ft_printf(const char *cstr, ...);

/*
** General functions
*/
size_t			obtainsubstr(const char *s, size_t i, t_printf *p);
void			get_argument(char conv, t_printf *p);
void			indent_digit(unsigned long long d, t_printf *p);
void			indent_char(int c, t_printf *p);
void			indent_string(const void *s, t_printf *p);

/*
** Buffer functions
*/
void			add_str_tobuf(char *str, t_printf *p);
void			add_char_tobuf(const char c, t_printf *p);
void			check_buffer(const size_t len, t_printf *p);

#endif
