/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/11 20:27:31 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		help_oux(const char *s, size_t *i, va_list ap, t_flags *fl)
{
	if ((s[*i] == 'o' ||  s[*i] == 'O' || s[*i] == 'u' || s[*i] == 'U'\
	|| s[*i] == 'X' || (s[*i] == 'x' && (fl->is_small_x = 1))) && (*i)++)
	{
		fl->base = ((s[*i - 1] == 'o' || s[*i - 1] == 'O') ? 8 :\
		(s[*i - 1] == 'u' || s[*i - 1] == 'U') ? 10 : 16);
		if (fl->ll)
			return (put_oux(va_arg(ap, unsigned long long), fl));
		if (fl->l || s[*i - 1] == 'U' || s[*i - 1] == 'O')
			return (put_oux(va_arg(ap, unsigned long), fl));
		if (fl->hh)
			return (put_oux((unsigned char)va_arg(ap, int), fl));
		if (fl->h)
			return (put_oux((unsigned short)va_arg(ap, int), fl));
		if (fl->j)
			return (put_oux(va_arg(ap, uintmax_t), fl));
		if (fl->z)
			return (put_oux(va_arg(ap, size_t), fl));
		return (put_oux(va_arg(ap, unsigned int), fl));
	}
	return ((*i)++ * 0);
}

static	int		help_did(const char *s, size_t *i, va_list ap, t_flags *fl)
{
	if ((s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'D') && (*i)++)
	{
		fl->base = 10;
		if (fl->ll)
			return (put_di(va_arg(ap, long long), fl));
		if (fl->l || s[*i - 1] == 'D')
			return (put_di(va_arg(ap, long), fl));
		if (fl->hh)
			return (put_di((char)va_arg(ap, int), fl));
		if (fl->h)
			return (put_di((short)va_arg(ap, int), fl));
		if (fl->j)
			return (put_di(va_arg(ap, intmax_t), fl));
		if (fl->z)
			return (put_di(va_arg(ap, ssize_t), fl));
		return (put_di(va_arg(ap, int), fl));
	}
	return (help_oux(s, i, ap, fl));
}

static	int		findsubstr(const char *s, size_t *i, va_list ap, t_flags *fl)
{
	fl = fill_flags(s, i, NULL);
	if (s[*i] == 'p' && (*i)++)
	{
		fl->hesh = 1;
		fl->base = 16;
		fl->is_small_x = 1;
		return (put_oux(va_arg(ap, uintmax_t), fl));
	}
	if ((s[*i] == 's' || (s[*i] == 'S' && (fl->l = 1))) && (*i)++)
	{
		// if (fl->l)
			// return (put_ls(va_arg(ap, const int *), fl));
		// else 
		if (!fl->l)
			return (put_s(va_arg(ap, const char *), fl));
	}
	if ((s[*i] == 'c' || (s[*i] == 'C' && (fl->l = 1))) && (*i)++)
	{
		if (fl->l)
			return (put_c(va_arg(ap, int), fl));
		else
			return (put_c((char)va_arg(ap, int), fl));
	}
	if (s[*i] == '%' && (*i)++)
		return (put_c('%', fl));
	return (help_did(s, i, ap, fl));
}

int				ft_printf(const char *s, ...)
{
	int			k;
	size_t		i;
	va_list		ap;

	i = 0;
	k = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			k += findsubstr(s, &i, ap, NULL);
		}
		else
			k += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (k);
}
