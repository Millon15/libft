/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 05:08:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/21 21:30:56 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <locale.h>
#include <string.h>

int			main(void)
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
	minlenth);

// 		printf("%100.20d|\n", 124141);
// 		ft_printf("%100.20d|\n", 124141);
// 		printf("%-100.20d|\n", 124141);
// 		ft_printf("%-100.20d|\n", 124141);
// 		printf("% -100.20d|\n", 124141);
// 		ft_printf("% -100.20d|\n", 124141);
// 		printf("%+-100.20d|\n", 124141);
// 		ft_printf("%+-100.20d|\n", 124141);
// 		printf("%+-100.20d|\n", -124141);
// 		ft_printf("%+-100.20d|\n", -124141);
// printf("\n");

// 		printf("%#.20x|\n", 37732);
// 		ft_printf("%#.20x|\n", 37732);
// 		printf("%#20x|\n", 37732);
// 		ft_printf("%#20x|\n", 37732);
// 		printf("%#100.20x|\n", 37732);
// 		ft_printf("%#100.20x|\n", 37732);
// 		printf("%#0100x|\n", 37732);
// 		ft_printf("%#0100x|\n", 37732);
// 		printf("%#-100.20x|\n", 124141);
// 		ft_printf("%#-100.20x|\n", 124141);
// printf("\n");

// 		printf("%#.20o|\n", 37732);
// 		ft_printf("%#.20o|\n", 37732);
// 		printf("%#20o|\n", 37732);
// 		ft_printf("%#20o|\n", 37732);
// 		printf("%#100.20o|\n", 37732);
// 		ft_printf("%#100.20o|\n", 37732);
// 		printf("%#0100o|\n", 37732);
// 		ft_printf("%#0100o|\n", 37732);
// printf("\n");

// 		printf("%.20u|\n", 37732);
// 		ft_printf("%.20u|\n", 37732);
// 		printf("%20u|\n", 37732);
// 		ft_printf("%20u|\n", 37732);
// 		printf("%100.20u|\n", 37732);
// 		ft_printf("%100.20u|\n", 37732);
// 		printf("%0100u|\n", 37732);
// 		ft_printf("%0100u|\n", 37732);
// printf("\n");

// 		printf("%.20d|\n", 37732);
// 		ft_printf("%.20d|\n", 37732);
// 		printf("%20d|\n", 37732);
// 		ft_printf("%20d|\n", 37732);
// 		printf("%100.20d|\n", 37732);
// 		ft_printf("%100.20d|\n", 37732);
// 		printf("%0100d|\n", 37732);
// 		ft_printf("%0100d|\n", 37732);
// printf("\n");

// 		printf("%5d|\n", -42);
// 		ft_printf("%5d|\n", -42);
// 		printf("%-5d|\n", -42);
// 		ft_printf("%-5d|\n", -42);
// 		printf("%05d|\n", -42);
// 		ft_printf("%05d|\n", -42);
// 		printf("%25.5d|\n", -42);
// 		ft_printf("%25.5d|\n", -42);
// 		printf("%-25.5d|\n", -42);
// 		ft_printf("%-25.5d|\n", -42);
// printf("\n");

// 		printf("%.20d|\n", 0);
// 		ft_printf("%.20d|\n", 0);
// 		printf("%20d|\n", 0);
// 		ft_printf("%20d|\n", 0);
// 		printf("%100.20d|\n", 0);
// 		ft_printf("%100.20d|\n", 0);
// 		printf("%0100d|\n", 0);
// 		ft_printf("%0100d|\n", 0);
// printf("\n");

// 		printf("%#.20x|\n", 0);
// 		ft_printf("%#.20x|\n", 0);
// 		printf("%#20x|\n", 0);
// 		ft_printf("%#20x|\n", 0);
// 		printf("%#100.20x|\n", 0);
// 		ft_printf("%#100.20x|\n", 0);
// 		printf("%#0100x|\n", 0);
// 		ft_printf("%#0100x|\n", 0);
// printf("\n");

// 		printf("%#.20o|\n", 0);
// 		ft_printf("%#.20o|\n", 0);
// 		printf("%#20o|\n", 0);
// 		ft_printf("%#20o|\n", 0);
// 		printf("%#100.20o|\n", 0);
// 		ft_printf("%#100.20o|\n", 0);
// 		printf("%#0100o|\n", 0);
// 		ft_printf("%#0100o|\n", 0);
// printf("\n");

// 		printf("@moulitest: %#.o|\n", 0);
// 		ft_printf("@moulitest: %#.o|\n", 0);

// 		printf("@moulitest: %#.o|\n", 1);
// 		ft_printf("@moulitest: %#.o|\n", 1);

// 		printf("%5d|\n", 0);
// 		ft_printf("%5d|\n", 0);
// 		printf("%-5d|\n", 0);
// 		ft_printf("%-5d|\n", 0);
// 		printf("%05d|\n", 0);
// 		ft_printf("%05d|\n", 0);
// 		printf("%25.5d|\n", 0);
// 		ft_printf("%25.5d|\n", 0);
// 		printf("%-25.5d|\n", 0);
// 		ft_printf("%-25.5d|\n", 0);
// 		printf("%5.5d|\n", 0);
// 		ft_printf("%5.5d|\n", 0);

// 		printf("%x|\n", 0);
// 		ft_printf("%x|\n", 0);
// 		printf("%o|\n", 0);
// 		ft_printf("%o|\n", 0);
// 		printf("%u|\n", 0);
// 		ft_printf("%u|\n", 0);
// 		printf("%d|\n", 0);
// 		ft_printf("%d|\n", 0);
// printf("\n");

// 		printf("%#.x|\n", 0);
// 		ft_printf("%#.x|\n", 0);
// 		printf("%#.o|\n", 0);
// 		ft_printf("%#.o|\n", 0);
// 		printf("%#.u|\n", 0);
// 		ft_printf("%#.u|\n", 0);
// 		printf("%#.d|\n", 0);
// 		ft_printf("%#.d|\n", 0);
// printf("\n");

// 		printf("%.x|\n", 0);
// 		ft_printf("%.x|\n", 0);
// 		printf("%.o|\n", 0);
// 		ft_printf("%.o|\n", 0);
// 		printf("%.u|\n", 0);
// 		ft_printf("%.u|\n", 0);
// 		printf("%.d|\n", 0);
// 		ft_printf("%.d|\n", 0);
// printf("\n");


// 		printf("%p\n", NULL);
// 		ft_printf("%p\n", NULL);
// 		printf("%.p\n", NULL);
// 		ft_printf("%.p\n", NULL);
// 		printf("%#.p\n", NULL);
// 		ft_printf("%#.p\n", NULL);
// printf("\n");

// 	char	c[] = "sdfds";
// 		printf("%p\n", c);
// 		ft_printf("%p\n", c);
// 		printf("%p\n", "sddfgsd");
// 		ft_printf("%p\n", "sddfgsd");
// 		printf("\n\n");

// 		printf("%d\n", 42);
// 		ft_printf("%d\n", 42);
// 		printf("%d%d\n", 42, 41);
// 		ft_printf("%d%d\n", 42, 41);
// 		printf("%d%d%d\n", 42, 43, 44);
// 		ft_printf("%d%d%d\n", 42, 43, 44);
// 		printf("%ld\n", 2147483647);
// 		ft_printf("%ld\n", 2147483647);
// 		printf("%lld\n", 9223372036854775807);
// 		ft_printf("%lld\n", 9223372036854775807);
// 		printf("%x\n", 505);
// 		ft_printf("%x\n", 505);
// 		printf("%X\n", 505);
// 		ft_printf("%X\n", 505);
// 		printf("%p\n", &ft_printf);
// 		ft_printf("%p\n", &ft_printf);
// 		printf("%20.15d\n", 54321);
// 		ft_printf("%20.15d\n", 54321);
// 		printf("%-10d\n", 3);
// 		ft_printf("%-10d\n", 3);
// 		printf("% d\n", 3);
// 		ft_printf("% d\n", 3);
// 		printf("%+d\n", 3);
// 		ft_printf("%+d\n", 3);
// 		printf("%010d\n", 1);
// 		ft_printf("%010d\n", 1);
// 		printf("%hhd\n", 0);
// 		ft_printf("%hhd\n", 0);
// 		printf("%jd\n", 9223372036854775807);
// 		ft_printf("%jd\n", 9223372036854775807);
// 		printf("%zd\n", 4294967295);
// 		ft_printf("%zd\n", 4294967295);
// 		printf("%\n");
// 		ft_printf("%\n");
// 		printf("%U\n", 4294967295);
// 		ft_printf("%U\n", 4294967295);
// 		printf("%u\n", 4294967295);
// 		ft_printf("%u\n", 4294967295);
// 		printf("%o\n", 40);
// 		ft_printf("%o\n", 40);
// 		printf("%x\n", 1000);
// 		ft_printf("%x\n", 1000);
// 		printf("%#X\n", 1000);
// 		ft_printf("%#X\n", 1000);
// printf("\n");

// 		printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
// 		ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
// 		printf("%hhd\n", 127 + 42);
// 		ft_printf("%hhd\n", 127 + 42);
// 		printf("{%03.2d}\n", 0);
// 		ft_printf("{%03.2d}\n", 0);
// 		printf("%o, %ho, %hho\n", -42, -42, -42);
// 		ft_printf("%o, %ho, %hho\n", -42, -42, -42);
// 		printf("%hhu, %hhu\n", 0, 127 + 42);
// 		ft_printf("%hhu, %hhu\n", 0, 127 + 42);
// 		printf("@moulitest: %5.o %5.0o|\n", 0, 0);
// 		ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);
// 		printf("%5.0o|\n", 0);
// 		ft_printf("%5.0o|\n", 0);
// 		printf("@moulitest: %5.d %5.0d|\n", 0, 0);
// 		ft_printf("@moulitest: %5.d %5.0d|\n", 0, 0);
// printf("\n");



// 		printf("%s|\n", "aaabbbcccddd");
// 		ft_printf("%s|\n", "aaabbbcccddd");
// 		printf("%s|%s|%s|\n", "aaabbbcccddd", "aaabbbcccddd", "aaabbbcccddd");
// 		ft_printf("%s|%s|%s|\n", "aaabbbcccddd", "aaabbbcccddd", "aaabbbcccddd");
// printf("\n");

// 		printf("%#.2s|\n", "aaabbbcccddd");
// 		ft_printf("%#.2s|\n", "aaabbbcccddd");
// 		printf("%#1s|\n", "aaabbbcccddd");
// 		ft_printf("%#1s|\n", "aaabbbcccddd");
// 		printf("%#100.20s|\n", "aaabbbcccddd");
// 		ft_printf("%#100.20s|\n", "aaabbbcccddd");
// 		printf("%#0100s|\n", "aaabbbcccddd");
// 		ft_printf("%#0100s|\n", "aaabbbcccddd");
// 		printf("%#-100.20s|\n", "aaabbbcccddd");
// 		ft_printf("%#-100.20s|\n", "aaabbbcccddd");
// printf("\n");

// 		printf("%100.20s|\n", "aaabbbcccddd");
// 		ft_printf("%100.20s|\n", "aaabbbcccddd");
// 		printf("%-100.20s|\n", "aaabbbcccddd");
// 		ft_printf("%-100.20s|\n", "aaabbbcccddd");
// 		printf("% -100.20s|\n", "aaabbbcccddd");
// 		ft_printf("% -100.20s|\n", "aaabbbcccddd");
// 		printf("%+-100.20s|\n", "aaabbbcccddd");
// 		ft_printf("%+-100.20s|\n", "aaabbbcccddd");
// 		printf("%+-100.20s|\n", "aaabbbcccddd");
// 		ft_printf("%+-100.20s|\n", "aaabbbcccddd");
// printf("\n");


// 		printf("{%-15Z}%d|\n", 123);
// 		ft_printf("{%-15Z}%d|\n", 123);
// printf("\n");


// 		printf("%c|\n", 'c');
// 		ft_printf("%c|\n", 'c');
// 		printf("%c|%c|%c|\n", 'c', 'c', 'c');
// 		ft_printf("%c|%c|%c|\n", 'c', 'c', 'c');
// printf("\n");

// printf("\n");
// 		printf("%#.2c|\n", 'c');
// 		ft_printf("%#.2c|\n", 'c');
// 		printf("%#1c|\n", 'c');
// 		ft_printf("%#1c|\n", 'c');
// 		printf("%#100.20c|\n", 'c');
// 		ft_printf("%#100.20c|\n", 'c');
// 		printf("%#0100c|\n", 'c');
// 		ft_printf("%#0100c|\n", 'c');
// 		printf("%#-100.20c|\n", 'c');
// 		ft_printf("%#-100.20c|\n", 'c');
// printf("\n");

// printf("\n");
// 		printf("%100.20c|\n", 'c');
// 		ft_printf("%100.20c|\n", 'c');
// 		printf("%-100.20c|\n", 'c');
// 		ft_printf("%-100.20c|\n", 'c');
// 		printf("% -100.20c|\n", 'c');
// 		ft_printf("% -100.20c|\n", 'c');
// 		printf("%+-100.20c|\n", 'c');
// 		ft_printf("%+-100.20c|\n", 'c');
// 		printf("%+-100.20c|\n", 'c');
// 		ft_printf("%+-100.20c|\n", 'c');
// 		printf("%.2c", NULL);
// 		ft_printf("%.2c", NULL);
// printf("\n");

// 		printf("{%05.c}\n", 0);
// 		ft_printf("{%05.c}\n", 0);
// 		printf("{%05.s}\n", 0);
// 		ft_printf("{%05.s}\n", 0);
// 		printf("{%05.s}\n", "this");
// 		ft_printf("{%05.s}\n", "this");
// 		printf("{%05.d}\n", 0);
// 		ft_printf("{%05.d}\n", 0);
// printf("\n");


// int	r1;
// int	r2;
// 		r1 = printf("%");
// 		r2 = ft_printf("%");
// 		printf("%d == %d\n", r1, r2);
// 		r1 = printf("%%|\n");
// 		r2 = ft_printf("%%|\n");
// 		printf("%d == %d\n", r1, r2);
// 		r1 = printf("%-5.2%|\n");
// 		r2 = ft_printf("%-5.2%|\n");
// 		printf("%d == %d\n", r1, r2);
// printf("\n");

// 		printf("%5.2s is a string|\n", "this");
// 		ft_printf("%5.2s is a string|\n", "this");
// 		printf("%-5.2s is a string|\n", "this");
// 		ft_printf("%-5.2s is a string|\n", "this");
// 		printf("%5s is a string|\n", "this");
// 		ft_printf("%5s is a string|\n", "this");
// 		printf("%-5s is a string|\n", "this");
// 		ft_printf("%-5s is a string|\n", "this");
// printf("\n");

// 		printf("%-10s is a string|\n", "");
// 		ft_printf("%-10s is a string|\n", "");
// 		printf("%-.2s is a string|\n", "");
// 		ft_printf("%-.2s is a string|\n", "");
// 		printf("%-5.2s is a string|\n", "");
// 		ft_printf("%-5.2s is a string|\n", "");
// 		printf("@moulitest: %s|\n", NULL);
// 		ft_printf("@moulitest: %s|\n", NULL);
// 	char *string;
// 		printf("%s %s|\n", NULL, string);
// 		ft_printf("%s %s|\n", NULL, string);
// printf("\n");


// 		printf("@main_ftprintf: |%####0000 33..1..#00d\\n|\n", 256);
// 		ft_printf("@main_ftprintf: |%####0000 33..1..#00d\\n|\n", 256);
// printf("\n");

// 	const char		*l = setlocale(LC_ALL, "");
// 		if (l == NULL) 
// 			printf("Locale not set\n");
// 		else
// 			printf("Locale set to %s\n", l);
// printf("\n");

// 		printf("%lc\n", L'ы');
// 		ft_printf("%lc\n", L'ы');
// 		printf("%lc\n", L'в');
// 		ft_printf("%lc\n", L'в');
// 	printf("\n");

// 		printf("{%13S}\n", L"фывфыв");
// 		ft_printf("{%13S}\n", L"фывфыв");
// 		printf("{%60.10S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("{%60.10S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("{%-15.2S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("{%-15.2S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%4.15S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%4.15S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// printf("\n");
// 		printf("%18.15S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%18.15S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%.1S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%.1S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%-64.15S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%-64.15S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%4.49S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%4.49S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%4.50S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%4.50S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%14.250S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%14.250S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// printf("\n");
// 		printf("%hhS, %hhS|\n", 0, L"米米");
// 		ft_printf("%hhS, %hhS|\n", 0, L"米米");
// 		printf("%S|\n", L"ݗݜशব");
// 		ft_printf("%S|\n", L"ݗݜशব");
// 		printf("%15.4S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		ft_printf("%15.4S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
// 		printf("%.2S, %s, %hhS|\n", NULL, NULL, 0);
// 		ft_printf("%.2S, %s, %hhS|\n", NULL, NULL, 0);

// 		printf("%u|\n", -42);
// 		ft_printf("%u|\n", -42);
// 		printf("%u|\n", UINT_MAX + 1);
// 		ft_printf("%u|\n", UINT_MAX + 1);
// 		printf("%U|\n", ULONG_MAX + 1);
// 		ft_printf("%U|\n", ULONG_MAX + 1);
// 		printf("%12lc|\n", L'Ы');
// 		ft_printf("%12lc|\n", L'Ы');
// 		printf("%11c|\n", 200);
// 		ft_printf("%11c|\n", 200);
// 		printf("%12lc|\n", 202);
// 		ft_printf("%12lc|\n", 202);
// 		printf("% u|%+u|\n", 42, 42);
// 		ft_printf("% u|%+u|\n", 42, 42);
// 		printf("%hhu / %hhu|\n", SHRT_MAX - 42,  SHRT_MAX - 4200);
// 		ft_printf("%hhu / %hhu|\n", SHRT_MAX - 42,  SHRT_MAX - 4200);
// printf("\n");

		// printf("dfjvdfjhjfdhj%.034s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		// ft_printf("dfjvdfjhjfdhj%.034s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	return (0);

}
