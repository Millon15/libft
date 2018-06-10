/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_put_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:59:22 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 05:09:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_utoa_base_st(
	const size_t value, const int base, char r[], t_printf *p
)
{
	int			j;
	size_t		b;

	if (base > 16 || base < 2)
		return ;
	j = 1;
	b = value;
	while (b /= base)
		j++;
	b = value;
	if (value == 0)
		r[0] = '0';
	while (b)
	{
		r[--j] = ft_itoc(b % base, p->fl.bigx);
		b /= base;
	}
}

static int		count_flag(
	const char r[], const size_t lenp, const t_printf *p
)
{
	if ((p->cc == 'd' || p->cc == 'i') && p->fl.is_neg)
		return (1);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.plus && !p->fl.is_neg)
		return (1);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.space)
		return (1);
	else if (p->cc == 'o' && p->fl.hesh && r[0] != '0' && p->fl.prec <= lenp)
		return (1);
	if ((p->cc == 'x' && p->fl.hesh && r[0] != '0') || p->cc == 'p')
		return (2);
	return (0);
}

static bool		put_flag(const char r[], const size_t lenp, t_printf *p)
{
	if ((p->cc == 'd' || p->cc == 'i') && p->fl.is_neg)
		add_char_to_buf('-', p);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.plus && !p->fl.is_neg)
		add_char_to_buf('+', p);
	else if ((p->cc == 'd' || p->cc == 'i') && p->fl.space)
		add_char_to_buf(' ', p);
	else if (p->cc == 'o' && p->fl.hesh && \
	*r && *r != '0' && p->fl.prec <= lenp)
		add_char_to_buf('0', p);
	else if ((p->cc == 'x' && p->fl.hesh && *r && *r != '0') || p->cc == 'p')
	{
		add_char_to_buf('0', p);
		add_char_to_buf(p->fl.bigx ? 'X' : 'x', p);
	}
	return (false);
}

static void		put_all_together(
	char r[], const size_t lenp, const size_t lenm, t_printf *p
)
{
	size_t			i;
	bool			to_print_flags;
	const	char	minl_char =

	(p->fl.zero && !p->fl.is_prec) ? '0' : ' ';
	to_print_flags = \
	(p->fl.minl > lenm && p->fl.zero) ? put_flag(r, lenp, p) : true;
	while (p->fl.minl && p->fl.minl-- > lenm && !p->fl.minus)
		add_char_to_buf(minl_char, p);
	to_print_flags ? put_flag(r, lenp, p) : false;
	while (p->fl.prec && p->fl.prec-- > lenp)
		add_char_to_buf('0', p);
	i = 0;
	while (r[i])
		add_char_to_buf(r[i++], p);
	while (p->fl.minl && p->fl.minl-- >= lenm && p->fl.minus)
		add_char_to_buf(' ', p);
}

void			indent_and_put_number(const size_t d, t_printf *p)
{
	char		r[42];
	size_t		lenp;
	size_t		lenm;

	ft_bzero(&r, sizeof(char) * 42);
	if (p->cc == 'x' || p->cc == 'p')
		ft_utoa_base_st(d, 16, r, p);
	else if (p->cc == 'o')
		ft_utoa_base_st(d, 8, r, p);
	else if (p->cc == 'u' || p->cc == 'd' || p->cc == 'i')
		ft_utoa_base_st(d, 10, r, p);
	if (r[0] == '0' && p->fl.is_prec && p->fl.prec == 0)
		r[0] = 0;
	if (r[0] == 0 && p->cc == 'o' && p->fl.hesh)
		r[0] = '0';
	lenp = ft_strlen(r);
	lenm = (p->fl.prec > lenp ? p->fl.prec : lenp) + count_flag(r, lenp, p);
	put_all_together(r, lenp, lenm, p);
	ft_bzero(&p->fl, sizeof(p->fl));
}
