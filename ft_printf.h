
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#include <stdio.h>

int		ft_putchar(int c);
int		ft_putstr(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_base(int value, int base);

void	ft_putnbr(int n);
int		ft_strlen(const char *s);

int		put_s(const char *s, char *fl);
int		put_d(int n);
int		put_u(unsigned int n);
int		put_o(unsigned int n);
int		put_x(unsigned int n);
int		put_X(unsigned int n);

#endif