
#include "ft_printf.h"

int			main(void)
{
	printf("% -100.7d\n", 124141);
	ft_printf("% -100.7d\n", 124142);
	printf("%+-100.7d\n", 124141);
	ft_printf("%+-100.7d\n", 124142);
	printf("%+-100.7d\n", -124141);
	ft_printf("%+-100.7d\n", -124142);
	printf("\n");
	return (0);
}
