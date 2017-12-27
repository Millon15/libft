/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:05 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/18 17:33:46 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long int	ft_pow(int n, int pw)
{
	unsigned long int	nb;

	if (n <= 0 || pw <= 0)
		return (0);
	if (pw == 1 || n == 1)
		return (n);
	nb = (unsigned long int)n;
	while (--pw)
		nb *= (unsigned long int)n;
	return (nb);
}
