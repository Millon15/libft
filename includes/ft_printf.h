/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:49:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 02:08:01 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# define BUFFER_SIZE 4096

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
	size_t							is_neg : 1;
	size_t							precs_spec : 1;
	size_t							is_prec : 1;
	size_t							is_minl : 1;
	size_t							prec;
	size_t							minl;

}				t_flags;

typedef struct	s_printf
{
	va_list							ap;
	t_flags							fl;
	char							cc;
	size_t							i;
	char							*buf;
	ssize_t							totout;

}				t_printf;


int				ft_printf(const char *cstr, ...);

void			add_char_to_buf(const char c, t_printf *p);
size_t			obtainsubstr(const char *s, size_t i, t_printf *p);
void			get_argument(char conv, t_printf *p);
void			indent_char(int c, t_printf *p);
void			indent_string(const void *s, t_printf *p);

void			indent_and_put_number(const size_t d, t_printf *p);

#endif
