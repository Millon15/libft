/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/16 16:52:54 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			add_char_to_buf(const int c, t_printf *p)
{
	if ((p->i + 1) == BUFFER_SIZE)
	{
		p->to_out += write(1, p->buf, p->i);
		p->i = 0;
	}
	p->buf[p->i++] = c;
}

int				ft_printf(const char *convstr, ...)
{
	size_t				i;
	static t_printf		prtf;
	static char			buf[BUFFER_SIZE];

	ft_bzero(&prtf, sizeof(prtf));
	prtf.buf = buf;
	va_start(prtf.ap, convstr);
	i = 0;
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '%')
			i = parseconvstr(convstr, i, &prtf);
		else
			add_char_to_buf(convstr[i++], &prtf);
	}
	va_end(prtf.ap);
	if (prtf.i > 0)
		prtf.to_out += write(1, prtf.buf, prtf.i);
	return (prtf.to_out);
}
