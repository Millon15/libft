
#include "ft_printf.h"

int			main(void)
{
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

	// printf("%#020x\n", 37732);
	// ft_printf("%#020x\n", 37732);
	// printf("%#20x\n", 37732);
	// ft_printf("%#20x\n", 37732);
	// printf("%#.20x\n", 37732);
	// ft_printf("%#.20x\n", 37732);
	// printf("%#0.20x\n", 37732);
	// ft_printf("%#0.20x\n", 37732);
	// printf("\n");

	// printf("%#0100.20x\n", 37732);
	// printf("%#100.20x\n", 37732);
	// printf("%#020x\n", 37732);
	// printf("%#020x\n", 37732);
	// printf("%#020x\n", 37732);
	// printf("%#020x\n", 37732);
	// printf("%#020x\n", 37732);
	return (0);
}
