/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtainsubstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:09:59 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/06 05:17:11 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	int		is_conversion_char(const char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '-' || c == '.')
		return (1);
	if (ft_isdigit(c))
		return (1);
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		return (0);
	if (c == 'd' || c == 'D' || c == 'i')
		return (0);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return (0);
	if (c == 'x' || c == 'X' || c == 'p')
		return (0);
	return (0);
}

static	size_t		fill_precision(const char *s, const size_t i, t_printf *p)
{
	int			l;

	l = i;
	p->fl.precs_spec = 0;
	p->fl.is_prec = 1;
	p->fl.precision = 0;
	while (ft_isdigit(s[l]))
	{
		p->fl.precision = p->fl.precision * 10 + (s[l] - '0');
		l++;
	}
	return (l - i);
}

static	size_t		fill_minlenth(const char *s, const size_t i, t_printf *p)
{
	int			l;

	l = i;
	p->fl.minlenth = 0;
	p->fl.is_minlenth = 1;
	while (ft_isdigit(s[l]))
	{
		p->fl.minlenth = p->fl.minlenth * 10 + (s[l] - '0');
		l++;
	}
	return (l - i);
}

static	size_t		fill_struct(const char *s, size_t i, t_printf *p)
{
	const	char	c = s[i];

	c == '\'' ? p->fl.apostrophe = 1 : 0;
	c == ' ' ? p->fl.space = 1 : 0;
	c == '#' ? p->fl.hesh = 1 : 0;
	c == '+' ? p->fl.plus = 1 : 0;
	c == '-' ? p->fl.minus = 1 : 0;
	c == 'h' ? p->fl.h = 1 : 0;
	c == 'l' ? p->fl.l = 1 : 0;
	c == 'j' ? p->fl.j = 1 : 0;
	c == 'z' ? p->fl.z = 1 : 0;
	c == 't' ? p->fl.t = 1 : 0;
	c == 'L' ? p->fl.ldouble = 1 : 0;
	c == '.' ? p->fl.precs_spec = 1 : 0;
	if (c == '0' && !ft_isdigit(s[i - 1]))
	{
		p->fl.zero = 1;
	}
	else if (ft_isdigit(c))
	{
		return (p->fl.precs_spec ? \
		fill_precision(s, i, p) : fill_minlenth(s, i, p));
	}
	return (1);
}

size_t			obtainsubstr(const char *s, size_t i, t_printf *p)
{
	i += 1;
	while (s[i] != '\0' && is_conversion_char(s[i]))
	{
		i += fill_struct(s, i, p);
	}
	return(i);
}
