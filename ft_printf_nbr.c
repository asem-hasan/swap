/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasan <ahasan@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:23:05 by ahasan            #+#    #+#             */
/*   Updated: 2026/11/11 10:23:08 by ahasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_nbr(int fd, int n)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		len += ft_printf_nbr(fd, nb / 10);
		len += ft_printf_nbr(fd, nb % 10);
	}
	else
		len += ft_printf_chr(fd, nb + '0');
	return (len);
}
