
#include "../ft_printf.h"

int		put_s(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}
