/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:21:20 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/06 05:40:59 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			check_buffer(const size_t len, t_printf *p)
{
	int			slen;

	slen = ft_strlen(p->buf);
	if ((slen + len) > BUFFER_SIZE)
	{
		p->totout += write(1, p->buf, slen);
		ft_bzero(p->buf, slen * sizeof(char));
		p->i = 0;
	}
}

void			add_char_tobuf(const char c, t_printf *p)
{
	check_buffer(1, p);
	p->buf[p->i++] = c;
}

void			add_str_tobuf(char *str, t_printf *p)
{
	size_t			slen;
	ssize_t			i;

	slen = ft_strlen(str);
	if (slen >= BUFFER_SIZE)
	{
		p->totout += write(1, str, slen);
		return ;
	}
	check_buffer(slen, p);
	i = -1;
	while (p->i < BUFFER_SIZE && str[++i] != '\0')
	{
		p->buf[p->i++] = str[i];
	}
}

int				ft_printf(const char *cstr, ...)
{
	size_t		i;
	va_list		ap;
	t_printf	prtf;

	ft_bzero(&prtf, sizeof(prtf));
	prtf.buf = ft_memalloc(sizeof(char) * BUFFER_SIZE);
	va_start(ap, cstr);
	i = 0;
	while (cstr[i] != '\0')
	{
		if (cstr[i] == '%')
			i = obtainsubstr(cstr, i, &prtf);
		else
			add_char_tobuf(cstr[i], &prtf);
		i++;
	}
	va_end(ap);
	prtf.totout += write(1, prtf.buf, ft_strlen(prtf.buf));

	printf("\n\n%lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU, %lU\n\n", 
	prtf.fl.apostrophe, \
	prtf.fl.zero, \
	prtf.fl.space, \
	prtf.fl.hesh, \
	prtf.fl.plus, \
	prtf.fl.minus, \
	prtf.fl.l, \
	prtf.fl.ll, \
	prtf.fl.h, \
	prtf.fl.hh, \
	prtf.fl.j, \
	prtf.fl.z, \
	prtf.fl.t, \
	prtf.fl.ldouble, \
	prtf.fl.precs_spec, \
	prtf.fl.is_prec, \
	prtf.fl.is_minlenth, \
	prtf.fl.precision, \
	prtf.fl.minlenth);

	return (prtf.totout);
}
