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
	ft_printf(2,"%d.",disorder / 100);
	// ft_printf(2,".");
	if (disorder % 100 < 10)
		ft_printf(2,"0");
	ft_printf(2,"%d%%\n",disorder % 100);
	// ft_putstr_fd("%\n", 2);
}


size_t	ft_isqrt(size_t n)
{
	size_t	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}


// void	ft_putnbr_fd(int n, int fd)
// {
// 	long int	nb;

// 	nb = n;
// 	if (nb < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		nb *= -1;
// 	}
// 	if (nb >= 10)
// 		ft_putnbr_fd(nb / 10, fd);
// 	ft_putchar_fd(nb % 10 + '0', fd);
// }

// void	ft_putstr_fd(const char *s, int fd)
// {
// 	int	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
