/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 06:05:00 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/10 08:55:58 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	unsigned long long	return_unsigned(t_printf *p)
{
	if (p->fl.j)
		return (va_arg(p->ap, intmax_t));
	else if (p->fl.z)
		return (va_arg(p->ap, ssize_t));
	else if (p->fl.ll)
		return (va_arg(p->ap, unsigned long long));
	else if (p->fl.l)
		return (va_arg(p->ap, unsigned long));
	else if (p->fl.hh)
		return ((unsigned char)va_arg(p->ap, unsigned int));
	else if (p->fl.h)
		return ((unsigned short)va_arg(p->ap, unsigned int));
	else
		return (va_arg(p->ap, unsigned int));
}

static	unsigned long long	return_signed(t_printf *p)
{
	long long				tmp;
	unsigned long long		utmp;

	if (p->fl.j)
		tmp = va_arg(p->ap, intmax_t);
	else if (p->fl.z)
		tmp = va_arg(p->ap, ssize_t);
	else if (p->fl.ll)
		tmp = va_arg(p->ap, long long);
	else if (p->fl.l)
		tmp = va_arg(p->ap, long);
	else if (p->fl.hh)
		tmp = (char)va_arg(p->ap, int);
	else if (p->fl.h)
		tmp = (short)va_arg(p->ap, int);
	else
		tmp = va_arg(p->ap, int);
	if (tmp < 0)
	{
		p->fl.is_neg = true;
		utmp = -tmp;
	}
	else
		utmp = tmp;
	return (utmp);
}

void						get_argument(const char conv, t_printf *p)
{
	if (conv == 'D' || conv == 'O' || conv == 'U' || \
		conv == 'S' || conv == 'C')
		p->fl.l = true;
	else if (conv == 'X')
		p->fl.bigx = true;
	else if (conv == 'p')
		p->fl.hesh = true;
	p->cc = ft_tolower(conv);
	if (p->cc == 'd' || p->cc == 'i')
		indent_and_put_integer(return_signed(p), p);
	else if (p->cc == 'o' || p->cc == 'u' || p->cc == 'x')
		indent_and_put_integer(return_unsigned(p), p);
	else if (p->cc == 'p')
		indent_and_put_integer(va_arg(p->ap, size_t), p);
	else if (p->cc == 's')
		indent_and_put_string(va_arg(p->ap, char*), p);
	else if (p->cc == 'c')
		indent_and_put_char((char)va_arg(p->ap, int), p);
	else
		indent_and_put_char(conv, p);
}
