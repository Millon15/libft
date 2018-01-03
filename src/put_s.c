
#include "../ft_printf.h"

int		put_s(const char *s, char *fl)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return ((int)write(1, s, i));
}
