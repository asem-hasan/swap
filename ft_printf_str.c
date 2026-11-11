/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasan <ahasan@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:23:14 by ahasan            #+#    #+#             */
/*   Updated: 2026/11/11 10:23:16 by ahasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_str(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(fd, "(null)", 6));
	}
	while (str[i])
	{
		ft_printf_chr(fd, str[i]);
		i++;
	}
	return (i);
}
