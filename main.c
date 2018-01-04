
#include "ft_printf.h"

int			main(void)
{
	int		k1;
	int		k2;

	k1 = 0;
	k2 = 0;
	k1 = ft_printf("%i\n", 131132);
	k2 = printf("%i\n", 131132);
	printf("k1 = %d and k2 = %d\n", k1, k2);
	k1 = ft_printf("%100.20i\n", 131132);
	k2 = printf("%100.20i\n", 131132);
	printf("k1 = %d and k2 = %d\n", k1, k2);
	k1 = ft_printf("%0.20i\n", 131132);
	k2 = printf("%0.20i\n", 131132);
	printf("k1 = %d and k2 = %d\n", k1, k2);
	k1 = ft_printf("%100i\n", 131132);
	k2 = printf("%100i\n", 131132);
	printf("k1 = %d and k2 = %d\n", k1, k2);
	k1 = ft_printf("%0i\n", 131132);
	k2 = printf("%0i\n", 131132);
	printf("k1 = %d and k2 = %d\n", k1, k2);
	return (0);
}
