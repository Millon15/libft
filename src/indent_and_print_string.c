/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_print_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 05:26:26 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/14 21:53:09 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	print_string(const char *s, const size_t len, t_printf *p)
{
	size_t				i;

	i = 0;
	if (p->fl.is_prec && p->fl.prec <= len)
	{
		while (i < p->fl.prec)
			add_char_to_buf(s[i++], p);
	}
	else
		while (s[i])
			add_char_to_buf(s[i++], p);
}

void			indent_and_print_string(const char *s, t_printf *p)
{
	const size_t		len = ((s != NULL) ? ft_strlen(s) : 6);
	const char			minl_char = ((p->fl.zero) ? '0' : ' ');
	const char			nullstr[] = "(null)";
	size_t				lenm;

	if (s == NULL)
		s = nullstr;
	lenm = (p->fl.is_prec && p->fl.prec <= len) ? p->fl.prec : len;
	while (!p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
	{
		add_char_to_buf(minl_char, p);
	}
	print_string(s, len, p);
	while (p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
	{
		add_char_to_buf(' ', p);
	}
}
