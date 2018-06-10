/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtainconvstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:09:59 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 23:10:57 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char		is_conversion_char(const char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '-' || c == '.')
		return (1);
	if (ft_isdigit(c))
		return (1);
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		return (-1);
	if (c == 'd' || c == 'D' || c == 'i')
		return (-1);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return (-1);
	if (c == 'x' || c == 'X' || c == 'p')
		return (-1);
	return (0);
}

size_t				obtainconvstr(const char *s, size_t i, t_printf *p)
{
	i += 1;
	while (s[i] != '\0' && is_conversion_char(s[i]) > 0)
	{
		i += fill_flags(s, i, p);
	}
	if (s[i] == '\0')
		return (i);
	get_argument(s[i], p);
	ft_bzero(&p->fl, sizeof(p->fl));
	return (++i);
}
