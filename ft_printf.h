/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:49:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/01/03 12:37:36 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#include <stdio.h>

int		ft_putchar(int c);
int		ft_strlen(const char *s);
int		ft_putstr(const char *s);
char	*ft_itoa_base(int value, int base);

int		put_s(const char *s, char *fl);
int		put_d(int n);
int		put_u(unsigned int n);
int		put_o(unsigned int n);
int		put_x(unsigned int n);
int		put_X(unsigned int n);

#endif