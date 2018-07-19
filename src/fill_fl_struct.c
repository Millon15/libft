/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fl_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 23:02:47 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/18 16:56:28 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	size_t		fill_prec(const char *s, size_t i, t_printf *p)
{
	const int	start = i;

	p->fl.is_prec = true;
	p->fl.prec = 0;
	if (ft_isdigit(s[i + 1]))
		i++;
	else
		return (1);
	while (ft_isdigit(s[i]))
	{
		p->fl.prec = p->fl.prec * 10 + (s[i] - '0');
		i++;
	}
	return (i - start);
}

static	size_t		fill_minl(const char *s, size_t i, t_printf *p)
{
	const int	start = i;

	p->fl.is_minl = true;
	p->fl.minl = 0;
	while (ft_isdigit(s[i]))
	{
		p->fl.minl = p->fl.minl * 10 + (s[i] - '0');
		i++;
	}
	return (i - start);
}

static size_t		obtain_minl_and_prec(const char *s, size_t i, t_printf *p)
{
	const size_t	start = i;

	if (s[i] == '0' && !ft_isdigit(s[i - 1]))
	{
		p->fl.zero = true;
		while (s[i] != '\0' && s[i] == '0')
			i++;
		return (i - start);
	}
	else if (s[i] == '.')
		return (fill_prec(s, i, p));
	else if (ft_isdigit(s[i]))
		return (fill_minl(s, i, p));
	return (1);
}

size_t				fill_fl_struct(const char *s, size_t i, t_printf *p)
{
	if (s[i] == 'l' && s[i + 1] == 'l')
		p->fl.ll = true;
	else if (s[i] == 'h' && s[i + 1] == 'h')
		p->fl.hh = true;
	else if (s[i] == ' ')
		p->fl.space = true;
	else if (s[i] == '#')
		p->fl.hesh = true;
	else if (s[i] == '+')
		p->fl.plus = true;
	else if (s[i] == '-')
		p->fl.minus = true;
	else if (s[i] == 'j')
		p->fl.j = true;
	else if (s[i] == 'z')
		p->fl.z = true;
	else if (s[i] == 'l')
		p->fl.l = true;
	else if (s[i] == 'h')
		p->fl.h = true;
	else
		return (obtain_minl_and_prec(s, i, p));
	return (1);
}
