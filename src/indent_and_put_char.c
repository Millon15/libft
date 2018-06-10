/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_put_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 06:11:29 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 08:42:56 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			indent_and_put_char(const int c, t_printf *p)
{
	const	char		minl_char = ((p->fl.zero) ? '0' : ' ');

	if (p->fl.l)
		return ;
	while (!p->fl.minus && p->fl.minl && p->fl.minl-- > 1)
		add_char_to_buf(minl_char, p);
	add_char_to_buf(c, p);
	while (p->fl.minus && p->fl.minl && p->fl.minl-- > 1)
		add_char_to_buf(' ', p);
}
