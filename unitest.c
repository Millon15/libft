/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 05:08:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/07 07:02:45 by vbrazas          ###   ########.fr       */
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

	printf("sdfsdfsfsd %12y sfsfd|\n", 123);
	ft_printf("sdfsdfsfsd %12y sfsfd|\n", 123);

	printf("%+12.2d|\n", 123);
	printf("%+12.2o|\n", 123);

	printf("%012.2d|\n", 123);
	printf("%012.2o|\n", 123);

	printf("%012d|\n", 123);
	printf("%012o|\n", 123);



	printf("%-12.2d|\n", 1);
	printf("%-12.2o|\n", 1);

	return 0;

}
