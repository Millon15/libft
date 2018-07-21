/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:49:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/21 17:22:01 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define MAXINTSIZE (sizeof(size_t) * 8)
# define BUFFER_SIZE 4096

typedef struct	s_flags
{
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
	size_t							is_bigx : 1;
	size_t							is_neg : 1;
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
	int								i;
	char							*buf;
	int								to_out;

}				t_printf;

int				ft_printf(const char *convstr, ...);

void			add_char_to_buf(const int c, t_printf *p);
size_t			parseconvstr(const char *s, size_t i, t_printf *p);
size_t			fill_fl_struct(const char *s, size_t i, t_printf *p);
void			get_argument(const char conv, t_printf *p);
char			count_active_bits(const int c);
void			print_the_bit(size_t b);
unsigned char	count_active_bytes(const int c);

void			indent_and_print_integer(const size_t d, t_printf *p);
void			indent_and_print_char(const int c, t_printf *p);
void			indent_and_print_string(const char *s, t_printf *p);
void			indent_and_print_wide_string(const wchar_t *s, t_printf *p);

#endif
