/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/11 00:44:53 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			add_char_to_buf(const char c, t_printf *p)
{
	if ((p->i + 1) == BUFFER_SIZE)
	{
		p->totout += write(1, p->buf, p->i);
		p->i = 0;
	}
	p->buf[p->i++] = c;
}

int				ft_printf(const char *convstr, ...)
{
	size_t			i;
	t_printf		prtf;
	static char		buf[BUFFER_SIZE];

	ft_bzero(&prtf, sizeof(prtf));
	prtf.buf = buf;
	va_start(prtf.ap, convstr);
	i = 0;
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '%')
			i = obtainconvstr(convstr, i, &prtf);
		else
			add_char_to_buf(convstr[i++], &prtf);
	}
	va_end(prtf.ap);
	if (prtf.i > 0)
		prtf.totout += write(1, prtf.buf, prtf.i);
	return (prtf.totout);
}
