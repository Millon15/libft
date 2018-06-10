/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_put_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 05:26:26 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 08:49:57 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	print_string(const char *s, const size_t len, t_printf *p)
{
	size_t				i;
	const char			nullstr[] = "(null)";

	i = 0;
	s == NULL ? s = nullstr : false;
	if (p->fl.is_prec && p->fl.prec <= len)
	{
		while (i < p->fl.prec)
			add_char_to_buf(s[i++], p);
	}
	else
	{
		while (s[i])
			add_char_to_buf(s[i++], p);
	}
}

void			indent_and_put_string(const char *s, t_printf *p)
{
	const size_t		len = ((s != NULL) ? ft_strlen(s) : 0);
	size_t				lenm;
	const char			minl_char = ((p->fl.zero) ? '0' : ' ');

	lenm = (p->fl.is_prec && p->fl.prec <= len) ? p->fl.prec : len;
	if (p->fl.l)
		return ;
	while (!p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
		add_char_to_buf(minl_char, p);
	print_string(s, len, p);
	while (p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
		add_char_to_buf(' ', p);
}
