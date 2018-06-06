/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 05:08:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/06 05:43:19 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			main( void )
{

	// printf("\n\n%U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U, %U\n\n", 
	// apostrophe, \
	// zero, \
	// space, \
	// hesh, \
	// plus, \
	// minus, \
	// l, \
	// ll, \
	// h, \
	// hh, \
	// j, \
	// z, \
	// t, \
	// ldouble, \
	// precs_spec, \
	// is_prec, \
	// is_minlenth, \
	// precision, \
	// minlenth);

	ft_printf("%012132.032 .05 18d", 12);

	return 0;

}