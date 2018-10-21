/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseconvstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:09:59 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/18 16:53:42 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	bool		is_convstr_member(const char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '-')
		return (true);
	else if (ft_isdigit(c) || c == '.')
		return (true);
	else if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (true);
	return (false);
}

size_t				parseconvstr(const char *s, size_t i, t_printf *p)
{
	i += 1;
	while (s[i] != '\0' && is_convstr_member(s[i]) > 0)
	{
		i += fill_fl_struct(s, i, p);
	}
	if (s[i] == '\0')
		return (i);
	if (s[i] == 'D' || s[i] == 'O' || s[i] == 'U' || \
		s[i] == 'S' || s[i] == 'C')
		p->fl.l = true;
	else if (s[i] == 'X')
		p->fl.is_bigx = true;
	else if (s[i] == 'p')
		p->fl.hesh = true;
	p->cc = ft_tolower(s[i]);
	get_argument(s[i], p);
	ft_bzero(&p->fl, sizeof(p->fl));
	return (++i);
}
