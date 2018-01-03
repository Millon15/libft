
#include "../../ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
		ft_putnbr(n / 10);
	putchar(n % 10 + '0');
}
