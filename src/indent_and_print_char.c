/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_and_print_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 06:11:29 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/14 22:09:00 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Unicode mask
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

static void		add_4bit_char_to_buf(const unsigned int c, t_printf *p)
{
	const unsigned char		o4 = (c << 26) >> 26;
	const unsigned char		o3 = ((c >> 6) << 26) >> 26;
	const unsigned char		o2 = ((c >> 12) << 26) >> 26;
	const unsigned char		o1 = ((c >> 18) << 29) >> 29;
	const unsigned int		m4 = 4034953344;

	add_char_to_buf((m4 >> 24) | o1, p);
	add_char_to_buf(((m4 << 8) >> 24) | o2, p);
	add_char_to_buf(((m4 << 16) >> 24) | o3, p);
	add_char_to_buf(((m4 << 24) >> 24) | o4, p);
}

static void		add_3bit_char_to_buf(const unsigned int c, t_printf *p)
{
	const unsigned char		o3 = (c << 26) >> 26;
	const unsigned char		o2 = ((c >> 6) << 26) >> 26;
	const unsigned char		o1 = ((c >> 12) << 28) >> 28;
	const unsigned int		m3 = 14712960;

	add_char_to_buf((m3 >> 16) | o1, p);
	add_char_to_buf(((m3 << 16) >> 24) | o2, p);
	add_char_to_buf(((m3 << 24) >> 24) | o3, p);
}

static void		add_2bit_char_to_buf(const unsigned int c, t_printf *p)
{
	const unsigned char		o2 = (c << 26) >> 26;
	const unsigned char		o1 = ((c >> 6) << 27) >> 27;
	const unsigned int		m2 = 49280;

	add_char_to_buf(((m2 >> 8) | o1), p);
	add_char_to_buf((((m2 << 24) >> 24) | o2), p);
}

char			count_active_bits(const int c)
{
	unsigned char		i;

	i = 1;
	while (c >> i && i < MAXINTSIZE)
		i++;
	return (i == MAXINTSIZE ? 0 : i);
}

void			indent_and_print_char(const int c, t_printf *p)
{
	char				minlchr;
	const unsigned char	active_bytes = count_active_bytes(c);
	const char			charlen = count_active_bits(c);

	if (p->cc != 's')
	{
		minlchr = ((p->fl.zero) ? '0' : ' ');
		while (!p->fl.minus && p->fl.minl && p->fl.minl-- > active_bytes)
			add_char_to_buf(minlchr, p);
	}
	if (charlen <= 7 && MB_CUR_MAX >= 1)
		add_char_to_buf(c, p);
	else if (charlen <= 11 && MB_CUR_MAX >= 2)
		add_2bit_char_to_buf(c, p);
	else if (charlen <= 16 && MB_CUR_MAX >= 3)
		add_3bit_char_to_buf(c, p);
	else if (charlen <= 32 && MB_CUR_MAX >= 4)
		add_4bit_char_to_buf(c, p);
	if (p->cc != 's')
		while (p->fl.minus && p->fl.minl && p->fl.minl-- > active_bytes)
			add_char_to_buf(' ', p);
}
