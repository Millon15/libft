/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_print_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:59:22 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/09 21:31:33 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_utoa_base_st(
	const size_t value, const int base, char r[], t_printf *p)
{
	int			j;
	size_t		b;

	j = 1;
	b = value;
	while (b /= base)
		j++;
	b = value;
	if (value == 0)
		r[0] = '0';
	while (b)
	{
		r[--j] = ft_itoc(b % base, p->fl.is_bigx);
		b /= base;
	}
}

static int		count_flag(
	const char r[], const size_t obj_len, const t_printf *p)
{
	if ((p->cc == 'd' || p->cc == 'i') && p->fl.is_neg)
		return (1);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.plus && !p->fl.is_neg)
		return (1);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.space)
		return (1);
	else if (p->cc == 'o' && p->fl.hesh && r[0] != '0' && p->fl.prec <= obj_len)
		return (1);
	if ((p->cc == 'x' && p->fl.hesh && r[0] != '0') || p->cc == 'p')
		return (2);
	return (0);
}

static bool		put_flag(const char r[], const size_t obj_len, t_printf *p)
{
	if ((p->cc == 'd' || p->cc == 'i') && p->fl.is_neg)
		add_char_to_buf('-', p);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.plus && !p->fl.is_neg)
		add_char_to_buf('+', p);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.space)
		add_char_to_buf(' ', p);
	else if (p->cc == 'o' && p->fl.hesh && \
	*r && *r != '0' && p->fl.prec <= obj_len)
		add_char_to_buf('0', p);
	else if ((p->cc == 'x' && p->fl.hesh && *r && *r != '0') || p->cc == 'p')
	{
		add_char_to_buf('0', p);
		add_char_to_buf(p->fl.is_bigx ? 'X' : 'x', p);
	}
	return (false);
}

static void		put_all_together(
	char r[], const size_t obj_len, const size_t lenm, t_printf *p)
{
	size_t			i;
	const char		minlchr = ((p->fl.zero && !p->fl.is_prec) ? '0' : ' ');
	const bool		to_print_flags =

	((p->fl.minl > lenm && p->fl.zero) ? put_flag(r, obj_len, p) : true);
	while (!p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
		add_char_to_buf(minlchr, p);
	to_print_flags ? put_flag(r, obj_len, p) : false;
	while (p->fl.prec && p->fl.prec-- > obj_len)
		add_char_to_buf('0', p);
	i = 0;
	while (r[i])
		add_char_to_buf(r[i++], p);
	while (p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
		add_char_to_buf(' ', p);
}

void			indent_and_print_integer(const size_t d, t_printf *p)
{
	static char	r[70];
	size_t		obj_len;
	size_t		lenm;

	ft_bzero(&r, sizeof(char) * 70);
	if (p->cc == 'x' || p->cc == 'p')
		ft_utoa_base_st(d, 16, r, p);
	else if (p->cc == 'o')
		ft_utoa_base_st(d, 8, r, p);
	else if (p->cc == 'u' || p->cc == 'd' || p->cc == 'i')
		ft_utoa_base_st(d, 10, r, p);
	if (d == 0 && p->cc == 'o' && p->fl.hesh)
		r[0] = '0';
	else if (d == 0 && p->fl.is_prec && p->fl.prec == 0)
		r[0] = '\0';
	obj_len = ft_strlen(r);
	lenm = ((p->fl.prec > obj_len) ?
	p->fl.prec : obj_len) + count_flag(r, obj_len, p);
	put_all_together(r, obj_len, lenm, p);
}
