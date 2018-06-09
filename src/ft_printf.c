/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/09 03:58:03 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			add_char_to_buf(const char c, t_printf *p)
{
	if ((p->i + 1) == BUFFER_SIZE)
	{
		p->totout += write(1, p->buf, p->i);
		ft_bzero(p->buf, p->i * sizeof(char));
		p->i = 0;
	}
	p->buf[p->i++] = c;
}

int				ft_printf(const char *cstr, ...)
{
	size_t		i;
	t_printf	prtf;

	ft_bzero(&prtf, sizeof(prtf));
	prtf.buf = ft_memalloc(sizeof(char) * BUFFER_SIZE);
	va_start(prtf.ap, cstr);
	i = 0;
	while (cstr[i] != '\0')
	{
		if (cstr[i] == '%')
			i = obtainsubstr(cstr, i, &prtf);
		else
			add_char_to_buf(cstr[i], &prtf);
		i++;
	}
	va_end(prtf.ap);
	if (prtf.i > 0)
		prtf.totout += write(1, prtf.buf, prtf.i);
	return (prtf.totout);
}
