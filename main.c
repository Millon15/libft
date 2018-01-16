
#include "ft_printf.h"
#include <locale.h>

int			main(void)
{
	printf("\n");
	printf("%100.7d\n", 124141);
	ft_printf("%100.7d\n", 124142);
	printf("%-100.7d\n", 124141);
	ft_printf("%-100.7d\n", 124142);
	printf("% -100.7d\n", 124141);
	ft_printf("% -100.7d\n", 124142);
	printf("%+-100.7d\n", 124141);
	ft_printf("%+-100.7d\n", 124142);
	printf("%+-100.7d\n", -124141);
	ft_printf("%+-100.7d\n", -124142);
	printf("\n");

	printf("\n");
	printf("%#.20x\n", 37732);
	ft_printf("%#.20x\n", 37732);
	printf("%#20x\n", 37732);
	ft_printf("%#20x\n", 37732);
	printf("%#100.20x\n", 37732);
	ft_printf("%#100.20x\n", 37732);
	printf("%#0100x\n", 37732);
	ft_printf("%#0100x\n", 37732);
	printf("\n");

	printf("%#.20o\n", 37732);
	ft_printf("%#.20o\n", 37732);
	printf("%#20o\n", 37732);
	ft_printf("%#20o\n", 37732);
	printf("%#100.20o\n", 37732);
	ft_printf("%#100.20o\n", 37732);
	printf("%#0100o\n", 37732);
	ft_printf("%#0100o\n", 37732);
	printf("\n");

	printf("%.20u\n", 37732);
	ft_printf("%.20u\n", 37732);
	printf("%20u\n", 37732);
	ft_printf("%20u\n", 37732);
	printf("%100.20u\n", 37732);
	ft_printf("%100.20u\n", 37732);
	printf("%0100u\n", 37732);
	ft_printf("%0100u\n", 37732);
	printf("\n");

	printf("%.20d\n", 37732);
	ft_printf("%.20d\n", 37732);
	printf("%20d\n", 37732);
	ft_printf("%20d\n", 37732);
	printf("%100.20d\n", 37732);
	ft_printf("%100.20d\n", 37732);
	printf("%0100d\n", 37732);
	ft_printf("%0100d\n", 37732);
	printf("\n");

	printf("%.20d\n", 0);
	ft_printf("%.20d\n", 0);
	printf("%20d\n", 0);
	ft_printf("%20d\n", 0);
	printf("%100.20d\n", 0);
	ft_printf("%100.20d\n", 0);
	printf("%0100d\n", 0);
	ft_printf("%0100d\n", 0);
	printf("\n");

	printf("%p\n", "sddfgsd");
	ft_printf("%p\n", "sddfgsd");

	// printf("%lu | %lu | %lu | %lu | %i | %i \n", sizeof(int), sizeof(int *),\
	// sizeof(WCHAR_MAX), sizeof(wchar_t), WCHAR_MAX, WCHAR_MIN);
	// printf("%zu, %zu, %zu, %zu, %zu\n", sizeof(int), sizeof(long),\
	// sizeof(long long), sizeof(double), sizeof(long double));

	// setlocale(LC_ALL, "");
	printf("printf(\"%%C\") :: %C\n\n", 945);
	ft_printf("ft_printf(\"%%C\") :: %C\n\n", 945);
	printf("printf(\"%%C\") :: %-3C$\n\n", 945);
	ft_printf("ft_printf(\"%%C\") :: %-3C$\n\n", 945);
	printf("\n");

	printf("%-100.2s$\n", "asdfg");
	ft_printf("%-100.2s$\n", "asdfg");

	printf("{%100.10ls}\n", L"米米");
	ft_printf("{%100.10ls}\n", L"米米");

	printf("%-2%$\n");
	ft_printf("%-2%$\n");

	printf("%s\n", "abs");
	ft_printf("%s\n", "abs");

	printf("%2c\n", 126);
	ft_printf("%2c\n", 126);

	printf("%c\n", -126);
	ft_printf("%c\n", -126);

	printf("%.2s\n", NULL);
	ft_printf("%.2s\n", NULL);

	printf("%#05x\n", 10);
	ft_printf("%#05x\n", 10);
	
	printf("@moulitest: %#.o$\n", 0);
	ft_printf("@moulitest: %#.o$\n", 0);

	printf("%5d$\n", -42);
	ft_printf("%5d$\n", -42);

	printf("%#x\n", 0);
	ft_printf("%#x\n\n", 0);

	printf("%#.x\n", 0);
	ft_printf("%#.x\n\n", 0);

	printf("%#o\n", 0);
	ft_printf("%#o\n\n", 0);

	printf("%#.o\n", 0);
	ft_printf("%#.o\n\n", 0);

	printf("%#u\n", 0);
	ft_printf("%#u\n\n", 0);

	printf("%#.u\n", 0);
	ft_printf("%#.u\n\n", 0);

	printf("%u\n", 0);
	ft_printf("%x\n\n", 0);

	printf("%.u\n", 0);
	ft_printf("%.u\n\n", 0);

	printf("%x\n", 0);
	ft_printf("%x\n\n", 0);

	printf("%.x\n", 0);
	ft_printf("%.x\n\n", 0);

	printf("%o\n", 0);
	ft_printf("%o\n\n", 0);

	printf("%.o\n", 0);
	ft_printf("%.o\n\n", 0);

	printf("%p\n", NULL);
	ft_printf("%p\n\n", NULL);

	printf("%.p\n", NULL);
	ft_printf("%.p\n\n", NULL);

	printf("%#.p\n", NULL);
	ft_printf("%#.p\n\n", NULL);

	char	c[] = "sdfds";
	printf("%p\n", c);
	ft_printf("%p\n\n", c);

	printf("%.p\n", c);
	ft_printf("%.p\n\n", c);

	printf("%#.p\n", c);
	ft_printf("%#.p\n\n", c);

	// setlocale(LC_ALL, "");
	ft_printf("\n");
	printf("\n");
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	printf("%x\n", 505);
	ft_printf("%X\n", 505);
	printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	printf("%zd\n", 4294967295);
	ft_printf("%\n");
	printf("%\n");
	ft_printf("%U\n", 4294967295);
	printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	printf("%C\n", 15000);
	// while (1);

	// setlocale(LC_ALL, "");
	ft_printf("%06.0S\n", L"ывм");
	printf("%06.0S\n", L"ывм");

	ft_printf("%.5p\n", 0);
	printf("%.5p\n", 0);

	ft_printf("{%-15Z}\n", 123);
	printf("{%-15Z}\n", 123);

	ft_printf("%", 123);
	printf("%", 123);

	ft_printf("{%60.10S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("{%60.10S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("{%-60.10S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("{%-60.10S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("{%-60.S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%4.15S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%4.15S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%114.15S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%114.15S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%-114.15S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%-114.15S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%4.49S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%4.49S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%4.50S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%4.50S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%4.150S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%4.150S$\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	ft_printf("%hhS, %hhS\n", 0, L"米米");
	printf("%hhS, %hhS\n", 0, L"米米");

	// setlocale(LC_ALL, "");
	ft_printf("adfafgваиыип\n");
	printf("adfafgваиыип\n");
	return (0);
}
