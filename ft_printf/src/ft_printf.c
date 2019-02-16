/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/16 21:58:43 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			add_char_to_buf(const int c, t_printf *p)
{
	if ((p->i + 1) == BUFFER_SIZE)
	{
		p->to_out += write(p->outfd, p->buf, p->i);
		p->i = 0;
	}
	p->buf[p->i++] = c;
}

int				ft_printf(const char *convstr, ...)
{
	size_t				i;
	static t_printf		p;
	static char			buf[BUFFER_SIZE];

	ft_bzero(&p, sizeof(p));
	p.outfd = 1;
	p.buf = buf;
	va_start(p.ap, convstr);
	i = 0;
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '%')
			i = parseconvstr(convstr, i, &p);
		else
			add_char_to_buf(convstr[i++], &p);
	}
	va_end(p.ap);
	if (p.i > 0)
		p.to_out += write(p.outfd, p.buf, p.i);
	return (p.to_out);
}

int				ft_dprintf(int fd, const char *convstr, ...)
{
	size_t				i;
	static t_printf		p;
	static char			buf[BUFFER_SIZE];

	ft_bzero(&p, sizeof(p));
	p.outfd = fd;
	p.buf = buf;
	va_start(p.ap, convstr);
	i = 0;
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '%')
			i = parseconvstr(convstr, i, &p);
		else
			add_char_to_buf(convstr[i++], &p);
	}
	va_end(p.ap);
	if (p.i > 0)
		p.to_out += write(p.outfd, p.buf, p.i);
	return (p.to_out);
}

/*
** void		print_the_bit(unsigned char num)
** {
** 	unsigned char		tmp = 0;
** 	int					bit;
**
** 	for(bit = 0; bit < (sizeof(unsigned char) * 8); bit++)
** 	{
** 		tmp <<= 1;
** 		tmp |= num & 0x01;
** 		num >>= 1;
** 	}
** 	for(bit = 0; bit < (sizeof(unsigned char) * 8); bit++)
** 	{
** 		ft_printf("%i ", tmp & 0x01);
** 		tmp >>= 1;
** 	}
** 	ft_putchar('\n');
** }
*/
