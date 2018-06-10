/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtainconvstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:09:59 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 09:15:01 by vbrazas          ###   ########.fr       */
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

static	size_t		fill_flags(const char *s, size_t i, t_printf *p)
{
	s[i] == ' ' ? p->fl.space = true : false;
	s[i] == '#' ? p->fl.hesh = true : false;
	s[i] == '+' ? p->fl.plus = true : false;
	s[i] == '-' ? p->fl.minus = true : false;
	s[i] == 'j' ? p->fl.j = true : false;
	s[i] == 'z' ? p->fl.z = true : false;
	s[i] == 'l' ? p->fl.l = true : false;
	s[i] == 'h' ? p->fl.h = true : false;
	if (s[i] == 'l' && (s[i + 1] == 'l' || s[i - 1] == 'l'))
		p->fl.ll = true;
	if (s[i] == 'h' && (s[i + 1] == 'h' || s[i - 1] == 'h'))
		p->fl.hh = true;
	if (s[i] == '0' && !ft_isdigit(s[i - 1]))
		p->fl.zero = true;
	else if (ft_isdigit(s[i]) || s[i] == '.')
		return (s[i] == '.' ? fill_prec(s, i, p) : fill_minl(s, i, p));
	return (1);
}

size_t				obtainsubstr(const char *s, size_t i, t_printf *p)
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




// static	size_t		fill_prec(const char *s, const size_t i, t_printf *p)
// {
// 	int			l;

// 	l = i;
// 	p->fl.precs_spec = false;
// 	p->fl.prec = 0;
// 	while (ft_isdigit(s[l]))
// 	{
// 		p->fl.prec = p->fl.prec * 10 + (s[l] - '0');
// 		l++;
// 	}
// 	return (l - i);
// }

// static	size_t		fill_minl(const char *s, const size_t i, t_printf *p)
// {
// 	int			l;

// 	p->fl.is_minl = true;
// 	p->fl.minl = 0;
// 	l = i;
// 	while (ft_isdigit(s[l]))
// 	{
// 		p->fl.minl = p->fl.minl * 10 + (s[l] - '0');
// 		l++;
// 	}
// 	return (l - i);
// }

// static	size_t		fill_flags(const char *s, size_t i, t_printf *p)
// {
// 	s[i] == ' ' ? p->fl.space = true : false;
// 	s[i] == '#' ? p->fl.hesh = true : false;
// 	s[i] == '+' ? p->fl.plus = true : false;
// 	s[i] == '-' ? p->fl.minus = true : false;
// 	s[i] == 'j' ? p->fl.j = true : false;
// 	s[i] == 'z' ? p->fl.z = true : false;
// 	s[i] == 'l' ? p->fl.l = true : false;
// 	s[i] == 'h' ? p->fl.h = true : false;
// 	if (s[i] == '.' && (p->fl.precs_spec = true))
// 		p->fl.is_prec = true;
// 	if (s[i] == 'l' && (s[i + 1] == 'l' || s[i - 1] == 'l'))
// 		p->fl.ll = true;
// 	if (s[i] == 'h' && (s[i + 1] == 'h' || s[i - 1] == 'h'))
// 		p->fl.hh = true;
// 	if (s[i] == '0' && !ft_isdigit(s[i - 1]))
// 		p->fl.zero = true;
// 	else if (ft_isdigit(s[i]))
// 		return (p->fl.precs_spec ? fill_prec(s, i, p) : fill_minl(s, i, p));
// 	return (1);
// }
