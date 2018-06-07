/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 06:05:00 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/07 04:56:08 by vbrazas          ###   ########.fr       */
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

static	long long			return_signed(t_printf *p)
{
	if (p->fl.ll)
		return (va_arg(p->ap, long long));
	else if (p->fl.l)
		return (va_arg(p->ap, long));
	else if (p->fl.h)
		return ((short)va_arg(p->ap, int));
	else if (p->fl.hh)
		return ((char)va_arg(p->ap, int));
	else if (p->fl.j)
		return (va_arg(p->ap, intmax_t));
	else if (p->fl.z)
		return (va_arg(p->ap, ssize_t));
	else
		return (va_arg(p->ap, int));
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
	if (conv == 'd' || conv == 'i')
		printf("%llu\n", return_signed(p));
	else if (conv == 'o' || conv == 'u' || conv == 'x' || conv == 'p')
		printf("%llu\n", return_unsigned(p));
	else if (conv == 'c')
	{
		p->fl.l ? (char)va_arg(p->ap, int) : va_arg(p->ap, int);
	}
	else if (conv == 's')
	{
		p->fl.l ? (char)va_arg(p->ap, int) : va_arg(p->ap, wchar_t *);
	}
}
