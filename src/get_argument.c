/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 06:05:00 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/09 04:30:44 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	unsigned long long	return_unsigned(t_printf *p)
{
	if (p->fl.ll)
		return (va_arg(p->ap, unsigned long long));
	else if (p->fl.l)
		return (va_arg(p->ap, unsigned long));
	else if (p->fl.h)
		return ((unsigned short)va_arg(p->ap, unsigned int));
	else if (p->fl.hh)
		return ((unsigned char)va_arg(p->ap, unsigned int));
	else if (p->fl.j)
		return (va_arg(p->ap, intmax_t));
	else if (p->fl.z)
		return (va_arg(p->ap, ssize_t));
	else
		return (va_arg(p->ap, unsigned int));
}

static	unsigned long long	return_signed(t_printf *p)
{
	long long				tmp;
	unsigned long long		utmp;

	if (p->fl.ll)
		tmp = va_arg(p->ap, long long);
	else if (p->fl.l)
		tmp = va_arg(p->ap, long);
	else if (p->fl.h)
		tmp = (short)va_arg(p->ap, int);
	else if (p->fl.hh)
		tmp = (char)va_arg(p->ap, int);
	else if (p->fl.j)
		tmp = va_arg(p->ap, intmax_t);
	else if (p->fl.z)
		tmp = va_arg(p->ap, ssize_t);
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

void						get_argument(char conv, t_printf *p)
{
	if (conv == 'D' || conv == 'O' || conv == 'U' || \
		conv == 'S' || conv == 'C')
		p->fl.l = true;
	else if (conv == 'X')
		p->fl.bigx = true;
	else if (conv == 'p')
	{
		p->fl.hesh = true;
		conv = 'x';
	}
	conv = ft_tolower(conv);
	p->cc = conv;
	if (conv == 'd' || conv == 'i')
		indent_and_put_number(return_signed(p), p);
	else if (conv == 'o' || conv == 'u' || conv == 'x' || conv == 'p')
		indent_and_put_number(return_unsigned(p), p);
	else if (conv == 'c')
		indent_char(\
		(p->fl.l ? (char)va_arg(p->ap, int) : va_arg(p->ap, int)), p);
	else if (conv == 's')
		indent_string(\
		(p->fl.l ? (void *)va_arg(p->ap, char*) : \
		(void *)va_arg(p->ap, wchar_t*)), p);
}
