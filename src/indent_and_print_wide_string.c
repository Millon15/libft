/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_print_wide_string.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 05:26:26 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/14 21:53:42 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

unsigned char	count_active_bytes(const int c)
{
	const char	charlen = count_active_bits(c);

	if (charlen <= 7)
		return (1);
	else if (charlen <= 11)
		return (2);
	else if (charlen <= 16)
		return (3);
	else if (charlen <= 32)
		return (4);
	return (0);
}

static	size_t	ft_wstrlen(const wchar_t *s)
{
	size_t		i;
	size_t		active_bytes_passed;

	if (s == NULL)
		return (6);
	i = 0;
	active_bytes_passed = 0;
	while (s[i] != 0)
	{
		active_bytes_passed += count_active_bytes(s[i++]);
	}
	return (active_bytes_passed);
}

static	size_t	get_delimeter(const wchar_t *s, t_printf *p)
{
	size_t		i;
	size_t		active_bytes_passed;

	i = 0;
	active_bytes_passed = 0;
	while (active_bytes_passed <= p->fl.prec)
	{
		active_bytes_passed += count_active_bytes(s[i++]);
	}
	active_bytes_passed -= count_active_bytes(s[i - 1]);
	return (active_bytes_passed);
}

static	void	print_string(const wchar_t *s, size_t len, t_printf *p)
{
	size_t				i;
	size_t				delimeter;
	size_t				active_bytes_passed;

	i = 0;
	active_bytes_passed = 0;
	if (p->fl.is_prec && p->fl.prec < len)
	{
		delimeter = get_delimeter(s, p);
		while (active_bytes_passed < delimeter)
		{
			indent_and_print_char(s[i], p);
			active_bytes_passed += count_active_bytes(s[i++]);
		}
	}
	else
		while (s[i] != 0)
			indent_and_print_char(s[i++], p);
}

void			indent_and_print_wide_string(const wchar_t *s, t_printf *p)
{
	const size_t		len = ft_wstrlen(s);
	const char			minlchr = ((p->fl.zero) ? '0' : ' ');
	const wchar_t		nullstr[] = L"(null)";
	size_t				lenm;

	if (s == NULL)
		s = nullstr;
	lenm = (p->fl.is_prec && p->fl.prec < len) ? get_delimeter(s, p) : len;
	while (!p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
	{
		add_char_to_buf(minlchr, p);
	}
	print_string(s, len, p);
	while (p->fl.minus && p->fl.minl && p->fl.minl-- > lenm)
	{
		add_char_to_buf(' ', p);
	}
}
