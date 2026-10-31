/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:04:27 by syaseen           #+#    #+#             */
/*   Updated: 2026/10/28 15:08:01 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	add_number(t_node **a, int value)
{
	t_node	*node;

	if (check_duplicates(*a, value))
		return (0);
	node = ft_lstnew(value);
	if (!node)
		return (0);
	ft_lstadd_back(a, node);
	return (1);
}

int	parse_args(int argc, char **argv, t_node **a, t_config *cfg)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!parse_flag(argv[i], cfg))
		{
			if (!parse_number(argv[i], &value) || !add_number(a, value))
			{
				free_stack(a);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
