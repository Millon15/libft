
#include <unistd.h>

int		ft_putstr(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return ((int)write(1, s, i));
}
