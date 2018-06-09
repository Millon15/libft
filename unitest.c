/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 05:08:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/09 06:26:10 by vbrazas          ###   ########.fr       */
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

		// printf("\n");
		// printf("%100.20d|\n", 124141);
		// ft_printf("%100.20d|\n", 124142);
		// printf("%-100.20d|\n", 124141);
		// ft_printf("%-100.20d|\n", 124142);
		// printf("% -100.20d|\n", 124141);
		// ft_printf("% -100.20d|\n", 124142);
		// printf("%+-100.20d|\n", 124141);
		// ft_printf("%+-100.20d|\n", 124142);
		// printf("%+-100.20d|\n", -124141);
		// ft_printf("%+-100.20d|\n", -124142);
		// printf("\n");

		// printf("\n");
		// printf("%#.20x|\n", 37732);
		// ft_printf("%#.20x|\n", 37732);
		// printf("%#20x|\n", 37732);
		// ft_printf("%#20x|\n", 37732);
		// printf("%#100.20x|\n", 37732);
		// ft_printf("%#100.20x|\n", 37732);
		// printf("%#0100x|\n", 37732);
		// ft_printf("%#0100x|\n", 37732);
		// printf("%#-100.20x|\n", 124141);
		// ft_printf("%#-100.20x|\n", 124142);
		// printf("\n");

		// printf("\n");
		// printf("%#.20o|\n", 37732);
		// ft_printf("%#.20o|\n", 37732);
		// printf("%#20o|\n", 37732);
		// ft_printf("%#20o|\n", 37732);
		// printf("%#100.20o|\n", 37732);
		// ft_printf("%#100.20o|\n", 37732);
		// printf("%#0100o|\n", 37732);
		// ft_printf("%#0100o|\n", 37732);
		// printf("\n");

		// printf("\n");
		// printf("%.20u|\n", 37732);
		// ft_printf("%.20u|\n", 37732);
		// printf("%20u|\n", 37732);
		// ft_printf("%20u|\n", 37732);
		// printf("%100.20u|\n", 37732);
		// ft_printf("%100.20u|\n", 37732);
		// printf("%0100u|\n", 37732);
		// ft_printf("%0100u|\n", 37732);
		// printf("\n");

		// printf("\n");
		// printf("%.20d|\n", 37732);
		// ft_printf("%.20d|\n", 37732);
		// printf("%20d|\n", 37732);
		// ft_printf("%20d|\n", 37732);
		// printf("%100.20d|\n", 37732);
		// ft_printf("%100.20d|\n", 37732);
		// printf("%0100d|\n", 37732);
		// ft_printf("%0100d|\n", 37732);
		// printf("\n");

		// printf("%.20d|\n", 0);
		// ft_printf("%.20d|\n", 0);
		// printf("%20d|\n", 0);
		// ft_printf("%20d|\n", 0);
		// printf("%100.20d|\n", 0);
		// ft_printf("%100.20d|\n", 0);
		// printf("%0100d|\n", 0);
		// ft_printf("%0100d|\n", 0);
		// printf("\n");

		printf("%#.20x|\n", 0);
		ft_printf("%#.20x|\n", 0);
		printf("%#20x|\n", 0);
		ft_printf("%#20x|\n", 0);
		printf("%#100.20x|\n", 0);
		ft_printf("%#100.20x|\n", 0);
		printf("%#0100x|\n", 0);
		ft_printf("%#0100x|\n", 0);
		printf("\n");

		// printf("%#.20o|\n", 0);
		// ft_printf("%#.20o|\n", 0);
		// printf("%#20o|\n", 0);
		// ft_printf("%#20o|\n", 0);
		// printf("%#100.20o|\n", 0);
		// ft_printf("%#100.20o|\n", 0);
		// printf("%#0100o|\n", 0);
		// ft_printf("%#0100o|\n", 0);
		// printf("\n");

		// printf("%p\n", "sddfgsd");
		// ft_printf("%p\n", "sddfgsd");

		// printf("@moulitest: %#.o|\n", 0);
		// ft_printf("@moulitest: %#.o|\n", 0);

		// printf("@moulitest: %#.o|\n", 1);
		// ft_printf("@moulitest: %#.o|\n", 1);

		// printf("%5d$\n", -42);
		// ft_printf("%5d$\n", -42);

		// printf("%#x\n", 0);
		// ft_printf("%#x\n\n", 0);

		// printf("%#.x\n", 0);
		// ft_printf("%#.x\n\n", 0);

		// printf("%#o\n", 0);
		// ft_printf("%#o\n\n", 0);

		// printf("%#.o\n", 0);
		// ft_printf("%#.o\n\n", 0);

		// printf("%#u\n", 0);
		// ft_printf("%#u\n\n", 0);

		// printf("%#.u\n", 0);
		// ft_printf("%#.u\n\n", 0);

		// printf("%u\n", 0);
		// ft_printf("%x\n\n", 0);

		// printf("%.u\n", 0);
		// ft_printf("%.u\n\n", 0);

		// printf("%x\n", 0);
		// ft_printf("%x\n\n", 0);

		// printf("%.x\n", 0);
		// ft_printf("%.x\n\n", 0);

		// printf("%o\n", 0);
		// ft_printf("%o\n\n", 0);

		// printf("%.o\n", 0);
		// ft_printf("%.o\n\n", 0);

		// printf("%p\n", NULL);
		// ft_printf("%p\n\n", NULL);

		// printf("%.p\n", NULL);
		// ft_printf("%.p\n\n", NULL);

		// printf("%#.p\n", NULL);
		// ft_printf("%#.p\n\n", NULL);

		// char	c[] = "sdfds";
		// printf("%p\n", c);
		// ft_printf("%p\n\n", c);

		// printf("%.p\n", c);
		// ft_printf("%.p\n\n", c);

		// printf("%#.p\n", c);
		// ft_printf("%#.p\n\n", c);

		// ft_printf("\n");
		// printf("\n");
		// ft_printf("%%\n");
		// printf("%%\n");
		// ft_printf("%d\n", 42);
		// printf("%d\n", 42);
		// ft_printf("%d%d\n", 42, 41);
		// printf("%d%d\n", 42, 41);
		// ft_printf("%d%d%d\n", 42, 43, 44);
		// printf("%d%d%d\n", 42, 43, 44);
		// ft_printf("%ld\n", 2147483647);
		// printf("%ld\n", 2147483647);
		// ft_printf("%lld\n", 9223372036854775807);
		// printf("%lld\n", 9223372036854775807);
		// ft_printf("%x\n", 505);
		// printf("%x\n", 505);
		// ft_printf("%X\n", 505);
		// printf("%X\n", 505);
		// ft_printf("%p\n", &ft_printf);
		// printf("%p\n", &ft_printf);
		// ft_printf("%20.15d\n", 54321);
		// printf("%20.15d\n", 54321);
		// ft_printf("%-10d\n", 3);
		// printf("%-10d\n", 3);
		// ft_printf("% d\n", 3);
		// printf("% d\n", 3);
		// ft_printf("%+d\n", 3);
		// printf("%+d\n", 3);
		// ft_printf("%010d\n", 1);
		// printf("%010d\n", 1);
		// ft_printf("%hhd\n", 0);
		// printf("%hhd\n", 0);
		// ft_printf("%jd\n", 9223372036854775807);
		// printf("%jd\n", 9223372036854775807);
		// ft_printf("%zd\n", 4294967295);
		// printf("%zd\n", 4294967295);
		// ft_printf("%\n");
		// printf("%\n");
		// ft_printf("%U\n", 4294967295);
		// printf("%U\n", 4294967295);
		// ft_printf("%u\n", 4294967295);
		// printf("%u\n", 4294967295);
		// ft_printf("%o\n", 40);
		// printf("%o\n", 40);
		// ft_printf("%%#08x\n", 42);
		// printf("%%#08x\n", 42);
		// ft_printf("%x\n", 1000);
		// printf("%x\n", 1000);
		// ft_printf("%#X\n", 1000);
		// printf("%#X\n", 1000);

	return 0;

}
