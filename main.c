
#include "ft_printf.h"

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

	char	p[] = "sddfgsd";

	printf("%p\n", p);
	ft_printf("%p\n", p);
	return (0);
}
