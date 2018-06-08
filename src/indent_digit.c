/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 05:08:38 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/07 23:16:11 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*fill_precision(char *r, char *prec, t_printf *p)
{
	size_t		rlen;
	size_t		i;
	size_t		j;

	rlen = ft_strlen(r);
	if (p->fl.is_prec && rlen < p->fl.prec)
	{
		prec = ft_memalloc(p->fl.prec + 1);
		ft_memset(prec, '0', p->fl.prec);
		i = p->fl.prec - rlen;
		j = 0;
		while (i < p->fl.prec || j < rlen)
			prec[i++] = r[j++];
		free(r);
		r = prec;
	}
	return (r);
}

static	int		fill_minlenth(char *minl, int rlen, t_printf *p)
{
	int			i;
	int			adding;

	i = 0;
	i = p->fl.minus ? 0 : p->fl.minl - rlen;
	// adding = (p->fl.space || p->fl.plus || p->fl.is_negative || \
	(p->hesh && p->convchr = 'o')) ? 1 : 0;
	if (p->fl.hesh && p->convchr == 'x')
	{
		minl[i++] = '0';
		minl[i++] = 'x';
	}
	i += adding;
	(p->fl.space || p->fl.plus || p->fl.is_negative) ? i += 1 : 0;
	p->fl.space ? minl[i - 1] = ' ' : 0;	
	if (p->fl.plus || p->fl.is_negative)
		minl[i - 1] = p->fl.is_negative ? '-' : '+';
	return (i);
}

static	char	*fill_minlenth(char *r, char *minl, t_printf *p)
{
	size_t		rlen;
	size_t		i;
	size_t		j;
	char		padding_char;

	rlen = ft_strlen(r);
	if (p->fl.is_minl && rlen < p->fl.minl)
	{
		minl = ft_memalloc(p->fl.minl + 1);
		padding_char = (p->fl.zero && !p->fl.is_prec && !p->fl.minus) ? \
		'0' : ' ';
		ft_memset(minl, padding_char, p->fl.minl);
		i = fill_flags(minl, rlen, p);
		j = 0;
		while (i < p->fl.minl || j < rlen)
			minl[i++] = r[j++];
		free(r);
		r = minl;
	}
	return (r);
}

void			indent_digit(unsigned long long d, t_printf *p)
{
	char		*r;
	char		*minl;
	char		*prec;
	size_t		i;

	if (p->convchr == 'x' || p->convchr == 'p')
		r = ft_utoa_base(d, 16);
	else if (p->convchr == 'o')
		r = ft_utoa_base(d, 8);
	else if (p->convchr == 'u' || p->convchr == 'd' || p->convchr == 'i')
		r = ft_utoa_base(d, 10);
	r = fill_precision(r, prec, p);
	r = fill_minlenth(r, minl, p);
	i = 0;
	if (p->fl.bigx)
		while (r[i])
		{
			r[i] = ft_toupper(r[i]);
			i++;
		}
	add_str_tobuf(r, 1, p);
}
