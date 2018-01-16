/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:09:38 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/11 21:18:03 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	short			i;
	unsigned long	result;
	short			minus;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > 9223372036854775807U && minus == 1)
			return (-1);
		if (result > 9223372036854775808U && minus == -1)
			return (0);
	}
	result = result * minus;
	return ((int)result);
}
