/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/06 22:18:17 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static	int			findsubstr(const char *s, size_t *i, va_list ap)
// {
// 	t_flags		*fl;
// 	short		o;

// 	if (s[*i] == '%')
// 		return (ft_putchar('%'));
// 	fl = fill_flags(s, i, NULL);
// 	if (s[*i] == 's' && (*i)++)
// 		return (put_s(va_arg(ap, const char *), fl));
// 	if (s[*i] == 'S' && (*i)++)
// 		return (ft_putstr("%S"));
// 	if (s[*i] == 'c')
// 		return (ft_putchar(va_arg(ap, int)));
// 	if ((s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'D') && (*i)++)
// 	{
// 		if (fl->ll)
// 			return (put_di(va_arg(ap, long long), 10, fl));
// 		if (fl->l || s[*i - 1] == 'D')
// 			return (put_di(va_arg(ap, long), 10, fl));
// 		if (fl->hh)
// 			return (put_di(va_arg(ap, char), 10, fl));
// 		if (fl->h)
// 			return (put_di(va_arg(ap, short), 10, fl));
// 		if (fl->j)
// 			return (put_di(va_arg(ap, long long), 10, fl));
// 		if (fl->t)
// 			return (put_di(va_arg(ap, long), 10, fl));
// 		// if (fl->z)
// 		// 	return (put_di(va_arg(ap, ssize_t), 10, fl));
// 		return (put_di(va_arg(ap, int), 10, fl));
// 	}
// 	if ((s[*i] == 'o' || s[*i] == 'u' || s[*i] == 'X' || s[*i] == 'U'\
// 	|| s[*i] == 'O' || (s[*i] == 'x' && (fl->small_x = 1))) && (*i)++)
// 	{
// 		o = 16;
// 		if (s[*i - 1] == 'o' || s[*i - 1] == 'O')
// 			o = 8;
// 		if (s[*i - 1] == 'u' || s[*i - 1] == 'U')
// 			o = 10;
// 		if (fl->ll)
// 			return (put_oux(va_arg(ap, unsigned long long), o, fl));
// 		if (fl->l || s[*i - 1] == 'U' || s[*i - 1] == 'O')
// 			return (put_oux(va_arg(ap, unsigned long), o, fl));
// 		if (fl->hh)
// 			return (put_oux(va_arg(ap, unsigned char), o, fl));
// 		if (fl->h)
// 			return (put_oux(va_arg(ap, unsigned short), o, fl));
// 		if (fl->j)
// 			return (put_oux(va_arg(ap, unsigned long long), o, fl));
// 		if (fl->t)
// 			return (put_oux(va_arg(ap, long), o, fl));
// 		return (put_oux(va_arg(ap, unsigned int), o, fl));
// 	}
// 	return (0);
// }

static	int		help_oouuxx(const char *s, size_t *i, va_list ap, t_flags fl)
{
	short		o;

	if ((s[*i] == 'o' || s[*i] == 'u' || s[*i] == 'X' || s[*i] == 'U'\
	|| s[*i] == 'O' || (s[*i] == 'x' && (fl->small_x = 1))) && (*i)++)
	{
		o = 16;
		if (s[*i - 1] == 'o' || s[*i - 1] == 'O')
			o = 8;
		if (s[*i - 1] == 'u' || s[*i - 1] == 'U')
			o = 10;
		if (fl->ll)
			return (put_oux(va_arg(ap, unsigned long long), o, fl));
		if (fl->l || s[*i - 1] == 'U' || s[*i - 1] == 'O')
			return (put_oux(va_arg(ap, unsigned long), o, fl));
		if (fl->hh)
			return (put_oux(va_arg(ap, unsigned char), o, fl));
		if (fl->h)
			return (put_oux(va_arg(ap, unsigned short), o, fl));
		if (fl->j)
			return (put_oux(va_arg(ap, unsigned long long), o, fl));
		if (fl->t)
			return (put_oux(va_arg(ap, long), o, fl));
		return (put_oux(va_arg(ap, unsigned int), o, fl));
	}
	return (0);
}

static	int		help_did(const char *s, size_t *i, va_list ap, t_flags fl)
{
	if ((s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'D') && (*i)++)
	{
		if (fl->ll)
			return (put_di(va_arg(ap, long long), 10, fl));
		if (fl->l || s[*i - 1] == 'D')
			return (put_di(va_arg(ap, long), 10, fl));
		if (fl->hh)
			return (put_di(va_arg(ap, char), 10, fl));
		if (fl->h)
			return (put_di(va_arg(ap, short), 10, fl));
		if (fl->j)
			return (put_di(va_arg(ap, long long), 10, fl));
		if (fl->t)
			return (put_di(va_arg(ap, long), 10, fl));
		// if (fl->z)
		// 	return (put_di(va_arg(ap, ssize_t), 10, fl));
		return (put_di(va_arg(ap, int), 10, fl));
	}
	return (help_oouuxx(s, i, ap, fl));
}

int				findsubstr(const char *s, size_t *i, va_list ap, t_flags fl)
{
	if (s[*i] == '%')
		return (ft_putchar('%'));
	fl = fill_flags(s, i, NULL);
	if (s[*i] == 's' && (*i)++)
		return (put_s(va_arg(ap, const char *), fl));
	if (s[*i] == 'S' && (*i)++)
		return (ft_putstr("%S"));
	if (s[*i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
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
		{
			write(1, &s[i++], 1);
			k++;
		}
	}
	va_end(ap);
	return (k);
}
