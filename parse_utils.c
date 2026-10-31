/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:10:25 by syaseen           #+#    #+#             */
/*   Updated: 2026/10/28 15:11:49 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_duplicates(t_node *stack_a, int value)
{
	t_node	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	read_sign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

int	read_digits(const char *s, long long limit, long long *num)
{
	int	digit;

	*num = 0;
	if (!ft_isdigit(*s))
		return (0);
	while (ft_isdigit(*s))
	{
		digit = *s - '0';
		if (*num > (limit - digit) / 10)
			return (0);
		*num = *num * 10 + digit;
		s++;
	}
	return (*s == '\0');
}

int	parse_number(const char *s, int *final)
{
	long long	num;
	long long	limit;
	int			sign;

	if (!s || !final)
		return (0);
	sign = read_sign(&s);
	limit = INT_MAX;
	if (sign == -1)
		limit = (long long)INT_MAX + 1;
	if (!read_digits(s, limit, &num))
		return (0);
	*final = (int)(num * sign);
	return (1);
}
