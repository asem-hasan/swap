/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:15:12 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:47:28 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	put_disorder(int disorder)
{
	ft_printf(2, "%d.", disorder / 100);
	if (disorder % 100 < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", disorder % 100);
}

size_t	ft_isqrt(size_t n)
{
	size_t	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}
